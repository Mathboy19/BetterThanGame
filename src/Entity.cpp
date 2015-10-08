#include "Entity.h"

Entity::Entity(SDL_Texture* givenTexture, SDL_Rect givenRect, const char* givenId, Animation *givenAnimation)
{
    texture = givenTexture;
    rect = givenRect;

    id = givenId;
    //init animation
    animation = givenAnimation;
    animation->initEntity(givenId);



}

Entity::~Entity()
{
    //dtor
}

SDL_Texture* Entity::getTexture() {
    return texture;
}

SDL_Texture* Entity::getCurrentTexture() {

    SDL_Texture* animationFrame = animation->getFrame(id);

    if (animationFrame == NULL) {

        //SDL_Log("AnimationFrame = NULL");
        return getTexture();

    } else { //if there is a texture

        return animationFrame;

    }

}

SDL_Rect Entity::getRect() {

    return rect;

}

void Entity::setX(int x) {
    rect.x = x;
}
void Entity::setY(int y) {
    rect.y = y;
}

int Entity::getX() {
    return rect.x;
}

int Entity::getY() {
    return rect.y;
}


void Entity::incrementX(int x) {
    rect.x = rect.x + x;
}
void Entity::incrementY(int y) {
    rect.y = rect.y + y;
}


