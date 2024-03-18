
#include "raylib.h"
#include <iostream>

struct
{
    int Width;
    int Height;
    const char *title; 
    int TFPS; // target fps 
}Window; 

// for settings , so its gonna be easier for changing 
struct
{
    KeyboardKey Up;
    KeyboardKey Down;
    KeyboardKey Right;
    KeyboardKey Left;
}Movement;

// player position 
Vector2 PPosition = { (float)Window.Width/2, (float)Window.Height/2 };

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
        if(IsKeyDown(Movement.Up)) 


        BeginDrawing();

            ClearBackground(RAYWHITE);
            DrawText("hello inputs", 10, 20, 20, BLACK);
            DrawCircleV(PPosition, 50, BLACK);

        if (WindowShouldClose())
        {
            EndDrawing();
        }
        
    } 

    CloseWindow();

    return 0;
}