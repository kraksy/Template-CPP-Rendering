
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <glm/glm.hpp>

#include <sstream>
#include <iostream>
#include <string>
#include <stdexcept>

enum INFO_LEVEL
{
    INFO,
    DEBUG,
    ERROR
};

// fix this shit man 
// https://stackoverflow.com/questions/5093460/how-to-convert-an-enum-type-variable-to-a-string
inline const char* ToString(INFO_LEVEL l)
{
    switch (l)
    {
        case INFO: return "info";
        case DEBUG: return "debug";
        case ERROR: return "error";
        default: return "[Unknown INFO_LEVEL]";
    }
}

template<typename... Args>
std::string format_string(const std::string& fmt, Args... args) {
    std::ostringstream oss;
    size_t len = fmt.size();
    size_t argIndex = 0;
    for (size_t i = 0; i < len; ++i) {
        if (fmt[i] == '{' && i + 1 < len && fmt[i + 1] != '{') {
            size_t endPos = fmt.find('}', i + 1);
            if (endPos == std::string::npos) {
                throw std::invalid_argument("Invalid format string: unmatched '{'");
            }
            std::string argStr = fmt.substr(i + 1, endPos - i - 1);
            try {
                oss << args[argIndex]; // Try to output the corresponding argument
                ++argIndex;
            } catch (...) {
                throw std::out_of_range("Not enough arguments provided for format string");
            }
            i = endPos; // Move iterator to the end of this argument
        } else if (fmt[i] == '}' && i + 1 < len && fmt[i + 1] != '}') {
            // Unmatched '}'
            throw std::invalid_argument("Invalid format string: unmatched '}'");
        } else if (fmt[i] == '{' && i + 1 < len && fmt[i + 1] == '{') {
            // Escaped '{', skip next character
            ++i;
            oss << '{';
        } else if (fmt[i] == '}' && i + 1 < len && fmt[i + 1] == '}') {
            // Escaped '}', skip next character
            ++i;
            oss << '}';
        } else {
            oss << fmt[i]; // Output regular character
        }
    }
    return oss.str();
}

void log( INFO_LEVEL level, std::string msg)
{
    std::printf(ToString(level), msg);
}

struct 
{
    SDL_Renderer* renderer = NULL;
    SDL_Surface* image = NULL;
    SDL_Texture* texture = NULL;
} Game;

struct 
{
    SDL_Window* gWindow = NULL;
    SDL_Surface* gScreenSurface = NULL;
    SDL_Surface* gKeyPressSurfaces[ KEY_PRESS_SURFACE_TOTAL ];
    SDL_Surface* gCurrentSurface = NULL;
} Window;

struct 
{
    const char* title;
    int Width;
    int Height;
    int fps;
} WindowGlobals = { "SDL Window", 800, 600, 60 };

enum KeyPressSurfaces
{
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_TOTAL
};

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

SDL_Surface* loadSurface( std::string path ) // for image loading 
{
    SDL_Surface* loadedSurface = SDL_LoadBMP( path.c_str() );

    if( loadedSurface == NULL )
    {
        log(INFO_LEVEL::INFO, "image unable to load" );
    }

    return loadedSurface;
}

bool load_all_imgdata()
{
    bool success = true;

    Game.texture = IMG_LoadTexture(Game.renderer, "Icon34.png");
    if (Game.texture == NULL)
    {
        log(INFO_LEVEL::INFO, "image unable to load" );
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
            Window.gCurrentSurface = Window.gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ];

            while (running)
            {
                while (SDL_PollEvent(&event))
                {
                    if (event.type == SDL_QUIT)
                        running = false;

                    if(event.type == SDL_KEYDOWN)
                    {
                        switch (event.key.keysym.sym)
                        {
                            case SDLK_UP:
                                break;
                        
                            default:
                                break;
                        }
                    }
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
