
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <glm/glm.hpp>

#include <iostream>
#include <string>

struct 
{
    /*
    SDL_Renderer* renderer = NULL;
    SDL_Surface* image;
    SDL_Texture* texture = NULL;
    */
} Game;

struct 
{
    SDL_Window* gWindow;
    SDL_Surface* gScreenSurface;
} Window;

struct 
{
    const char* title;
    int Width;
    int Height;
    int fps;
} WindowGlobals = { "SDL Window", 800, 600, 60 };

static void quit_program(int code)
{
    //SDL_QUIT();
    exit(code);
}

static void free_memo()
{

}

