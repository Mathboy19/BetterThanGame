#ifndef GRAPHICS_H
#define GRAPHICS_H

#include<list>

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
using namespace std;

namespace Graphics
{
        int initWindow(int width, int height);
        void clearScreen(int r, int g, int b);
        void update();
        void quit();
        SDL_Renderer* returnRender();
        SDL_Texture* createTexture(const char* file);
        list<SDL_Texture*> createSheet(const char* file, int frames, int delay);
        void drawTexture(SDL_Texture *texture, SDL_Rect rect);

}

#endif // GRAPHICS_H
