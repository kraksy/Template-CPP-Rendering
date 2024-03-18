
#include "raylib.h"
#include <iostream>

struct
{
    int Width;
    int Height;
    const char *title; 
    int TFPS; // target fps 
}Window; 

int main(void)
{
    Window.Width = 800;
    Window.Height = 450; 
    Window.TFPS = 60;
    Window.title = "hello Raylib";

    InitWindow(Window.Width, Window.Height, Window.title);
    SetTargetFPS(Window.TFPS);

    while (IsWindowReady())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);

        if (WindowShouldClose())
        {
            EndDrawing();
        }
        
    } 

    CloseWindow();

    return 0;
}