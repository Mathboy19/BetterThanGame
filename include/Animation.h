#ifndef ANIMATION_H
#define ANIMATION_H

#include<list>
#include<string>
#include<map>

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>


using namespace std;

class Animation
{
    public:
        Animation(SDL_Renderer* render);
        void initEntity(const char* id);
        void load(const char* name);
        void start(const char* name, const char* id);
        SDL_Texture* loadFrame(const char* name);
        SDL_Texture* getFrame(const char* id);

    protected:
        SDL_Texture* currentFrame;

        SDL_Renderer* render;

        bool currentlyAnimating; //is there an animation running right now? (prevent overloading frames and duplicate animations)

        //std::list<SDL_Texture*> frames; //(not neaded with entity list)

        std::map<const char*, list<SDL_Texture*>* > loadedAnimations; //currently only supports single frame animations, will need to change to a list of frames later

        std::map<const char*, list<SDL_Texture*> > entityList; //id of entity and its current frames

        list<SDL_Texture*>* loadedFrames;

    private:
};

#endif // ANIMATION_H
