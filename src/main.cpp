//main.cpp
//MazeRunner - v1 - by Mathboy19
#include<SDL2/SDL.h>
#include"Engine.h"

int main(int argc, char** argv)
{

    Engine *gameng = new Engine();

    gameng->init(480, 600);

    gameng->gameLoop();
    SDL_Log("Program Ended");
    return 0;
}
