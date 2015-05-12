// lazyfoo is love, lazyfoo is life

#include <stdio.h>
#include <string>
#include "SDL2/SDL.h"
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define SPLASH_IMAGE "assets/splash.bmp"


SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gSplashImg = NULL;

bool init();

bool load_splash();

SDL_Surface* load_surface(std::string path);

void close();

int main(int argc, char* args[])
{
    bool quit = false;
    SDL_Event e;
    init();
    load_splash();
    SDL_BlitSurface(gSplashImg, NULL, gScreenSurface, NULL);
    while (!quit) 
    {
        while (SDL_PollEvent(&e) != 0) 
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }

        }
        SDL_UpdateWindowSurface(gWindow);
        SDL_Delay(16);
    }
    close();

}

bool init() {
    bool success = true;
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        success = false;
    }
    else
    {
        gWindow = SDL_CreateWindow("MemeBusters", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        gScreenSurface = SDL_GetWindowSurface(gWindow);
    }
    return success;
}

bool load_splash() {
    gSplashImg = load_surface(SPLASH_IMAGE);
    return gSplashImg != NULL;
}

SDL_Surface* load_surface(std::string path) {
    SDL_Surface* l = SDL_LoadBMP(path.c_str());
    if (l == NULL)
        printf("u r bad memester %s %s", path.c_str(), SDL_GetError());
    return l;
}

void close() {
    SDL_DestroyWindow(gWindow);
    SDL_Quit();
}
