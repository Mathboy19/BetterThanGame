#ifndef HERO_H
#define HERO_H

#include <Entity.h>
#include <Animation.h>


class Hero : public Entity
{
    public:
        Hero(SDL_Texture* givenTexture, SDL_Rect givenRect, SDL_Renderer* givenRender, const char* givenId, Animation* givenAnimation);
        void passKeyStates(const Uint8* keyStates);
        void logic();



        const Uint8* currentKeyStates;
    protected:

    private:

};

#endif // HERO_H
