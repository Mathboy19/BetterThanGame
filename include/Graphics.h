#ifndef GRAPHICS_H
#define GRAPHICS_H
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>

class Graphics
{
    public:
        Graphics();
        int initWindow(int width, int height);
        void clearScreen(int r, int g, int b);
        void update();
        void quit();
        SDL_Renderer* returnRender();
        SDL_Texture* createTexture(const char* file, bool alphaMask);
        void drawTexture(SDL_Texture *texture, SDL_Rect rect);
    protected:
    private:
        SDL_Window *mainWindow;
        SDL_Renderer *mainRender;
};

#endif // GRAPHICS_H
