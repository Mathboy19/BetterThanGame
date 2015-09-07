#include "Graphics.h"

Graphics::Graphics()
{
    SDL_Log("Grahpics Initiated");
}

int Graphics::initWindow(int width, int height)
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
            mainRender = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_ACCELERATED);
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

void Graphics::quit()
{
    SDL_DestroyRenderer(mainRender);
    SDL_DestroyWindow(mainWindow);
}

void Graphics::clearScreen(int r, int g, int b)
{
    SDL_SetRenderDrawColor(mainRender, r, g, b, 255);
    SDL_RenderClear(mainRender);
}
void Graphics::update()
{
    SDL_RenderPresent(mainRender);
}

SDL_Texture* Graphics::createTexture(const char* file, bool alphaMask)
{
    SDL_Surface* surface;
    SDL_Texture* texture;



    surface = IMG_Load(file);

    if(surface != NULL)
    {

        //old alphamask, not needed after having transparent backgrounds
        if(alphaMask)
        {
            if(surface != NULL)
            {
                Uint32 colorKey = SDL_MapRGB(surface->format, 255, 255, 255);
                SDL_SetColorKey(surface, SDL_TRUE, colorKey);
            }
        }
        //end alphamask

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

void Graphics::drawTexture(SDL_Texture *texture, SDL_Rect rect)
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

SDL_Renderer* Graphics::returnRender()
{

    return mainRender;
}

