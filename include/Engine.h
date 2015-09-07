#ifndef ENGINE_H
#define ENGINE_H

#include<list>

#include<SDL2/SDL.h>

#include"Graphics.h"
#include"Entity.h"
#include"Hero.h"
#include"Animation.h"
#include"Enemy.h"

class Engine
{
public:
    Engine();
    void init(int width, int height);
    void gameLoop();
    void quitAll();

protected:

    bool testUp;
    bool testDown;
    bool testRight;
    bool testLeft;
    //Input *mainInput;
    Graphics *mainGraphics;
    //Entity *hero;
    Hero *hero;
    Enemy *enemy;

    //Animation Handler
    Animation *animation;

    double frameEndTime;
    double frameStartTime;

    std::list<Entity*> entityList;


};

#endif // ENGINE_H
