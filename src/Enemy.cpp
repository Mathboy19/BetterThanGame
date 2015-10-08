#include "Enemy.h"

Enemy::Enemy(SDL_Texture* givenTexture, SDL_Rect givenRect, const char* givenId, Animation* givenAnimation)
      :Entity(givenTexture, givenRect, givenId, givenAnimation) {
    //ctor

    animation->load("enemyhurt");

}

void Enemy::logic(Hero* hero) {

    if(sqrt((hero->getX() - getX()) * (hero->getX() - getX()) +
        (hero->getY() - getY()) * (hero->getY() - getY())) <= 100) {

    animation->start("enemyhurt", id);
    //SDL_Log("Disteance: %F", sqrt((hero->getX() - getX()) * (hero->getX() - getX()) +
    //    (hero->getY() - getY()) * (hero->getY() - getY())));

    }


    //sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))

    //herox = x1 heroy = y1 enemyx = x2 enemyy = y2

}
