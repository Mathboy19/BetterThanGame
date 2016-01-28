#include "Animation.h"


Animation::Animation()
{
    //test code
    //frames.clear();

    //graphics = givenGraphics;

    render = Graphics::returnRender();


    SDL_Log("Animation Initialized a;sdlfkj");
}

void Animation::initEntity(const char* id) {

    list<SDL_Texture*> dummy;

    entityList[id] = dummy;


}


void Animation::load(const char* name) {

    char* path = new char[128];

    strcpy(path, name);
    //SDL_Log(path or name);
    strcat(path, ".png");
    SDL_Log(path);

    SDL_Log("Loading Animation");

    list<SDL_Texture*> dummy;

    //dummy text
    dummy.push_back(Graphics::createTexture(path));

    loadedAnimations[name] = dummy;

    //loadedFrames->empty();

}

void Animation::loadSheet(const char* name, int frames) {

    char* path = new char[128];

    strcpy(path, name);
    //SDL_Log(path or name);
    strcat(path, ".png");

    SDL_Log(path);



    list<SDL_Texture*> spreadSheet = Graphics::createSheet(path, frames);
    if (spreadSheet.empty()) {
        SDL_Log("spreadSheet was empty");
    } else {
        loadedAnimations[name] = spreadSheet;

    }


}

void Animation::start(const char* name, const char* id) {

    SDL_Log("Starting Animation");



    //std::list<SDL_Texture*> frames;

    entityList[id] = loadedAnimations[name];



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

    }


    return currentFrame;

}
