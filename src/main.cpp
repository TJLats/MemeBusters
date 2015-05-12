// lazyfoo is love, lazyfoo is life

#include <stdio.h>
#include <string>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define SPLASH_IMAGE "assets/splash.png"


SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Texture* gSplashImg = NULL;
SDL_Texture* gTexture = NULL;
SDL_Renderer* gRenderer = NULL;

bool init();

void close();

SDL_Surface* load_png(std::string path);

int main(int argc, char* args[])
{
    bool quit = false;
    SDL_Event e;
    init();
    gSplashImg = SDL_CreateTextureFromSurface(gRenderer, load_png(SPLASH_IMAGE));
    gTexture = gSplashImg;
    while (!quit) 
    {
        while (SDL_PollEvent(&e) != 0) 
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
        }
        SDL_RenderClear(gRenderer);
	    SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);
        SDL_RenderPresent(gRenderer);
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
	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	IMG_Init(IMG_INIT_PNG);
        gScreenSurface = SDL_GetWindowSurface(gWindow);
    }
    return success;
}

void close() {
    SDL_DestroyWindow(gWindow);
    SDL_Quit();
}

SDL_Surface* load_png(std::string path)
{
	SDL_Texture* newTexture = NULL;
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	return loadedSurface;
}
