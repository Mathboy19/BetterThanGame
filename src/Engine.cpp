//src/Engine.cpp
//Maze Runner - v1 - by mathboy19

#include "Engine.h"

Engine::Engine()
{

    SDL_Log("Engine initialized");

}

void Engine::init(int width, int height)
{

    //mainGraphics = new Graphics();

    //mainGraphics->initWindow(width, height);
    Graphics::initWindow(width, height);



    animation = new Animation();


    //this initilizes the entity hero
    //needs to be replazed with proper loading of entities in the future

    //test data

    //uuid
    const char* id = "1";

    SDL_Texture *heroTexture = Graphics::createTexture("hero.png");

    SDL_Rect heroRect = {0, 0, 80, 120};

    hero = new Hero(heroTexture, heroRect, id, animation);

    //this initilizes the entity enemy
    //really hope I can replace this soon

    //test data

    //uuid
    id = "2";
    //texture
    SDL_Texture *enemyTexture = Graphics::createTexture("enemy.png");
    //rect
    SDL_Rect enemyRect = {200, 200, 40, 60};

    enemy = new Enemy(enemyTexture, enemyRect, id, animation);

    //entityList.push_back(hero);



}

void Engine::gameLoop()
{

    SDL_Log("Starting Game Loop");
    //gameloop

    //
    SDL_Event event;
    bool quit = false;
    while(!quit)
    {
        //begin counter
        frameStartTime = SDL_GetTicks();

        if(SDL_PollEvent(&event) != 0)
        {
            switch(event.type)
            {
            case SDL_QUIT:
                quit = true;
                SDL_Log("SDL_QUIT Detected, exiting.");
            }



        }

        const Uint8* keyState = SDL_GetKeyboardState(NULL);


        //pass keyboard
        hero->passKeyStates(keyState);


        //logic

        hero->logic();

        enemy->logic(hero);




        //start render
        Graphics::clearScreen(86, 169, 83);
        Graphics::drawTexture(hero->getCurrentTexture(), hero->getRect());
        Graphics::drawTexture(enemy->getCurrentTexture(), enemy->getRect());
        Graphics::update();

        //end counter
        //frameEndTime = SDL_GetTicks();



        //SDL_Log("FPS: %f", (1000/(SDL_GetTicks() - frameStartTime)));
    }
    SDL_Log("gameLoop Over");

}

void Engine::quitAll()
{
    Graphics::quit();

}
