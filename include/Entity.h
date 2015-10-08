#ifndef ENTITY_H
#define ENTITY_H
#include<SDL2/SDL.h>
#include"Animation.h"

class Entity
{
    public:
        Entity(SDL_Texture* givenTexture, SDL_Rect rect, const char* givenId, Animation *givenAnimation);
        SDL_Texture* getTexture();
        SDL_Texture* getCurrentTexture();
        SDL_Rect getRect();
        int getX();
        int getY();
        void setX(int x);
        void setY(int y);
        void incrementX(int x);
        void incrementY(int y);
        virtual ~Entity();

    protected:
        Animation* animation;
        SDL_Renderer* render;
        SDL_Texture *texture;
        SDL_Rect rect;
        int x;
        int y;
        const char* id;


    private:

};

#endif // ENTITY_H
