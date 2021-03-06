#include "Graphics.h"

namespace Graphics
{
SDL_Window *mainWindow;
SDL_Renderer *mainRender;

int initWindow(int width, int height)
{

    if( SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {


        SDL_Log("SDL could not initilize! SDL_Error:%s", SDL_GetError());
        return 1;

    }
    else
    {
        mainWindow = SDL_CreateWindow("MazeRunner v1", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
        if(mainWindow == NULL)
        {
            SDL_Log("Window could not be created SDL_Error:%s", SDL_GetError());
            return 1;
        }
        else
        {
            mainRender = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if(mainRender == NULL)
            {
                SDL_Log("Render could not be created SDL_Error:%s", SDL_GetError());
                return 1;
            }
            else
            {

            }
        }

    }
    SDL_Log("Window + Graphics initialized");
    return 0;
}

void quit()
{
    SDL_DestroyRenderer(mainRender);
    SDL_DestroyWindow(mainWindow);
}

void clearScreen(int r, int g, int b)
{
    SDL_SetRenderDrawColor(mainRender, r, g, b, 255);
    SDL_RenderClear(mainRender);
}
void update()
{
    SDL_RenderPresent(mainRender);
}

SDL_Texture* createTexture(const char* file)
{
    SDL_Surface* surface;
    SDL_Texture* texture;



    surface = IMG_Load(file);

    if(surface != NULL)
    {


        texture = SDL_CreateTextureFromSurface(mainRender, surface);
        SDL_FreeSurface(surface);

        return texture;
    }
    else
    {
        SDL_Log("Could not load image!");
        return NULL;
    }
}
list<SDL_Texture*> createSheet(const char* file, int frames, int delay) {

    if(frames <= 0) {
        //return NULL;
        SDL_Log("Graphics::createSheet Frames cannot <= 0!");
    }

    list<SDL_Texture*> frameList;
    //list<SDL_Texture*> dummy;
    //list<SDL_Texture*>* frameList = &dummy;

    SDL_Surface* surface;
    SDL_Surface* tempSurface;


    SDL_Rect surfaceRect;
    SDL_Rect tempRect;

    int frameWidth;

    surface = IMG_Load(file);

    if(surface != NULL) {
        //SDL_Log("Sprite sheet is not null");
        SDL_Log("Height: %d", surface->h);
        SDL_Log("Width: %d", surface->w);

        frameWidth = (surface->w)/frames;


        SDL_Log("frameWidth: %d", frameWidth);
        for (int i = 0; i < frames; i++) {

		    Uint32 rmask = 0x000000ff;
    		Uint32 gmask = 0x0000ff00;
    		Uint32 bmask = 0x00ff0000;
			Uint32 amask = 0xff000000;
			
            tempSurface = SDL_CreateRGBSurface(0, (surface->w/frames), surface->h, 32, rmask, gmask, bmask, amask);

            SDL_SetSurfaceBlendMode(surface, SDL_BLENDMODE_NONE);

            SDL_Log("Frame: %d", i);
            surfaceRect.x = i * (surface->w)/frames;
            surfaceRect.y = 0;
            surfaceRect.h = surface->h;
            surfaceRect.w = (surface->w)/frames;

            tempRect.x = 0;
            tempRect.y = 0;
            tempRect.h = surface->h;
            tempRect.w = (surface->w)/frames;
            SDL_Log("sourceRect.x = %d", surfaceRect.x);
            if(surface != NULL) {
                SDL_BlitSurface(surface, &surfaceRect, tempSurface, &tempRect);

                if(tempSurface != NULL) {
					SDL_Texture* frame = SDL_CreateTextureFromSurface(mainRender, tempSurface);
					
					for (int i = 0; i < delay;  i++) {
                    	frameList.push_back(frame);
					}
                } else {
                    SDL_Log("tempSurface = NULL Error: %s", SDL_GetError());
                }
            } else {
                SDL_Log("Sheet Sprite Surface was Null Error: %s", SDL_GetError());
            }

        }
        if(!frameList.empty()) {
            SDL_Log("Returning Framelist");
            return frameList;
        } else {
            SDL_Log("frameList is equal to NULL!");

        }



    } else {
        SDL_Log("Couldn't load sprite sheet");
        SDL_Log(SDL_GetError());


    }




}

void drawTexture(SDL_Texture *texture, SDL_Rect rect)
{

    if(texture == NULL)
    {
        SDL_Log("Texture is null, cannot draw texture");
    }
    else
    {
        SDL_RenderCopy(mainRender, texture, NULL, &rect);
    }

}

SDL_Renderer* returnRender()
{

    return mainRender;
}


}
