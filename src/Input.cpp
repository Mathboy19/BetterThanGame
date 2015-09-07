#include "Input.h"

Input::Input()
{

    SDL_Log("Input Initialized");
}

void Input::inputLoop()
{

    SDL_Log("Starting Game Loop");
    SDL_Event event;
    bool quit = false;
    while(!quit)
    {
        if(SDL_PollEvent(&event) != 0)
        {
            switch(event.type) {
                case SDL_QUIT:
                    quit = true;
                    SDL_Log("SDL_QUIT Detected, exiting.");
            }
            SDL_Delay(20);
        }
        else //if there are no events detected
        {

            //SDL_Log("No Events Dectected");
            SDL_Delay(20);
        }
    }

}

