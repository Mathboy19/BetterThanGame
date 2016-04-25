
#include <SDL2/SDL.h>
#include "Hero.h"



Hero::Hero(SDL_Texture* givenTexture, SDL_Rect givenRect, const char* givenId, Animation *givenAnimation)
    :Entity(givenTexture, givenRect, givenId, givenAnimation) {

    //load animations


    animation->loadSheet("herosinks.png", 5, 30);

    animation->loadSheet("herosad.png", 1, 60);



}

void Hero::passKeyStates(const Uint8* keyStates) {

    currentKeyStates = keyStates;



}

void Hero::logic() {

        //logic
        if(currentKeyStates[SDL_SCANCODE_DOWN] == true && currentKeyStates[SDL_SCANCODE_UP] == false) {
            incrementY(1);
        } else if(currentKeyStates[SDL_SCANCODE_UP] == true && currentKeyStates[SDL_SCANCODE_DOWN] == false) {
            incrementY(-1);
        }
        if(currentKeyStates[SDL_SCANCODE_RIGHT] == true && currentKeyStates[SDL_SCANCODE_LEFT] == false) {
            incrementX(1);
        } else if(currentKeyStates[SDL_SCANCODE_LEFT] == true && currentKeyStates[SDL_SCANCODE_RIGHT] == false) {
            incrementX(-1);
        }
        if(currentKeyStates[SDL_SCANCODE_SPACE] == true) {
            //animation->load("herosad");
            animation->start("herosad.png", getId());
        }
        if(currentKeyStates[SDL_SCANCODE_Z]== true) {
            //SDL_Log("Z input detected");
            animation->start("herosinks.png", getId());
        }

}

