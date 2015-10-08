#ifndef ENEMY_H
#define ENEMY_H

#include"Entity.h"
#include"Hero.h"

class Enemy : public Entity
{
    public:
        Enemy(SDL_Texture* givenTexture, SDL_Rect givenRect, const char* givenId, Animation* givenAnimation);
        void logic(Hero* hero);
    protected:
    private:
};

#endif // ENEMY_H
