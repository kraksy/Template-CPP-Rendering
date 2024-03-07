
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>

struct 
{
    SDL_Surface* image; 
}Game;

struct 
{
    SDL_Window* gWindow;
    SDL_Surface* gSCreenSurface;
}Window;

struct
{
    char* title;
    int Width;
    int Height;
    int fps;
}WindowGlobals;

bool init()
{
    bool success = true;

    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }
        else
    {
        Window.gWindow = SDL_CreateWindow( WindowGlobals.title , SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WindowGlobals.Width, WindowGlobals.Height, SDL_WINDOW_SHOWN );
        if( Window.gWindow == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            Window.gSCreenSurface = SDL_GetWindowSurface( Window.gWindow );
        }
    }

    return success;
}

bool load_all_imgdata()
{
    bool success = true;

    Game.image = IMG_Load("src/Icon34.png");

    if(Game.image == NULL)
    {
        printf("unable to load image data");
        success = false;
    }

    return success;
}

void free_exit()
{
    SDL_FreeSurface(Game.image);
    Game.image = NULL;
    SDL_DestroyWindow(Window.gWindow);
    Window.gWindow = NULL;
    SDL_Quit();
    exit(0);
}

int main(int argc, char const *argv[])
{

    Window.gSCreenSurface = NULL;
    Window.gWindow = NULL;

    if (init())
    {
        if (load_all_imgdata())
        {
            SDL_BlitSurface(Game.image, NULL, Window.gSCreenSurface, NULL);
            SDL_UpdateWindowSurface(Window.gWindow);
            SDL_Event event; 
            bool running;
            while (running)
            {
                while (SDL_PollEvent(&event))
                {
                    if (event.type == SDL_QUIT) running = false;
                }
            }
        }
        else
        {
            printf("failed to load image data");
            exit(1);
        }
    }
    else
    {
        printf("failed to init the SDL2");
        exit(1);
    }

    exit(0);
}
