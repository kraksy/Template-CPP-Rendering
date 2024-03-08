#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>

struct 
{
    SDL_Renderer* renderer = NULL;
    SDL_Surface* image;
    SDL_Texture* texture = NULL;
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

bool init()
{
    bool success = true;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        Window.gWindow = SDL_CreateWindow(WindowGlobals.title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WindowGlobals.Width, WindowGlobals.Height, SDL_WINDOW_SHOWN);
        if (Window.gWindow == NULL)
        {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            Game.renderer = SDL_CreateRenderer(Window.gWindow, -1, SDL_RENDERER_ACCELERATED);
            Window.gScreenSurface = SDL_GetWindowSurface(Window.gWindow);
        }
    }

    IMG_Init(IMG_INIT_PNG);

    return success;
}

bool load_all_imgdata()
{
    bool success = true;

    Game.texture = IMG_LoadTexture(Game.renderer, "Icon34.png");
    if (Game.texture == NULL)
    {
        printf("Failed to load image! SDL_Error: %s\n", SDL_GetError());
        success = false;
    }

    return success;
}

void free_exit()
{
    SDL_DestroyTexture(Game.texture);
    SDL_DestroyRenderer(Game.renderer);
    SDL_DestroyWindow(Window.gWindow);
    SDL_Quit();
    IMG_Quit();
    exit(0);
}

void blitImageToScreen()
{
    SDL_RenderClear(Game.renderer);
    SDL_RenderCopy(Game.renderer, Game.texture, NULL, NULL);
    SDL_RenderPresent(Game.renderer);
}

int main(int argc, char const* argv[])
{
    Window.gScreenSurface = NULL;
    Window.gWindow = NULL;

    if (init())
    {
        if (load_all_imgdata())
        {
            SDL_Event event;
            bool running = true;
            while (running)
            {
                while (SDL_PollEvent(&event))
                {
                    if (event.type == SDL_QUIT)
                        running = false;
                }
                blitImageToScreen();
            }
            free_exit();
        }
        else
        {
            printf("Failed to load image data");
            exit(1);
        }
    }
    else
    {
        printf("Failed to init SDL2");
        exit(1);
    }

    exit(0);
}
