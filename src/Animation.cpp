#include "Animation.h"

Animation::Animation(SDL_Renderer* givenRender)
{
    //test code
    //frames.clear();

    render = givenRender;


    SDL_Log("Animation Initialized");
}

void Animation::initEntity(const char* id) {

    list<SDL_Texture*> dummy;

    entityList[id] = dummy;


}


void Animation::load(const char* name) {


    SDL_Log("Loading Animation");

    loadedFrames->empty();

    loadedFrames->push_back(loadFrame(name));

    //loadedAnimations[name] = loadedFrames;

    //loadedFrames->empty();

}

void Animation::start(const char* name, const char* id) {

    SDL_Log("Starting Animation");

    currentlyAnimating = true;

    std::list<SDL_Texture*>* frames;

    frames = &entityList[id];

    frames = loadedAnimations[name];

}

SDL_Texture* Animation::loadFrame(const char* name) {

    SDL_Surface* surface;
    SDL_Texture* texture;

    char* path = new char[128];

    strcpy(path, name);
    //SDL_Log(path or name);
    strcat(path, ".png");
    SDL_Log(path);


    surface = IMG_Load(path);

    if(surface != NULL)
    {

        /* //old alphamask, not needed after having transparent backgrounds
        if(alphaMask)
        {
            if(surface != NULL)
            {
                Uint32 colorKey = SDL_MapRGB(surface->format, 255, 255, 255);
                SDL_SetColorKey(surface, SDL_TRUE, colorKey);
            }
        }
        */ //end alphamask

        texture = SDL_CreateTextureFromSurface(render, surface);
        SDL_FreeSurface(surface);

        if(texture != NULL) {

            return texture;

        } else {

            SDL_Log("Animation Texture is null");
            SDL_Log(SDL_GetError());
            return NULL;

        }
    }
    else
    {
        SDL_Log("Could not load image!");
        return NULL;
    }
}

SDL_Texture* Animation::getFrame(const char* id) {

    //SDL_Log("Retrieving Animation");

    std::list<SDL_Texture*>* frames;

    frames = &entityList[id];


    if(frames->empty()) {

        //SDL_Log("Animation Over");
        currentFrame = NULL;
    } else {

        //SDL_Log("Animation not over");
        currentFrame = frames->front();
        /* debug code

        if(currentFrame == NULL) {
            SDL_Log("currentFrame = Null");
        }
        */

        frames->pop_front();

        if(frames->empty()) { //are we done with the current animation?

        currentlyAnimating = false;

        }

    }


    return currentFrame;

}
