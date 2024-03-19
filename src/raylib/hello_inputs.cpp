
#include "raylib.h"
#include <iostream>

struct
{
    int Width;
    int Height;
    const char *Title; 
    int TFPS; // target fps 
    Camera2D Camera = { 0 };
}Window; 

// for settings , so its gonna be easier for changing 
struct
{
    KeyboardKey Up;
    KeyboardKey Down;
    KeyboardKey Right;
    KeyboardKey Left;
}Movement;

struct
{
    //sprite
    Vector2 Pos;
}Cursor;

// player position 
Vector2 PPosition = { (float)Window.Width/2, (float)Window.Height/2 };

int main(void)
{
    Window.Width = 800;
    Window.Height = 450; 
    Window.TFPS = 60;
    Window.Title = "hello Raylib";

    Window.Camera.offset = { (float)Window.Width/2, (float)Window.Height/2 };
    Window.Camera.rotation = 0.0f;
    Window.Camera.target = Cursor.Pos;
    Window.Camera.zoom = 1.0f;

    Movement.Up = KEY_W;
    Movement.Down = KEY_S;
    Movement.Right = KEY_D;
    Movement.Left = KEY_A;

    InitWindow(Window.Width, Window.Height, Window.Title);
    SetTargetFPS(Window.TFPS);

    while (!WindowShouldClose())
    {
        Cursor.Pos = GetMousePosition();
        Window.Camera.target = { PPosition.x , PPosition.y };

        Vector2 worldMousePos = { Cursor.Pos.x / Window.Camera.zoom - Window.Camera.offset.x + Window.Camera.target.x,
                                  Cursor.Pos.y / Window.Camera.zoom - Window.Camera.offset.y + Window.Camera.target.y };

        if(IsKeyDown(Movement.Up))
            PPosition.y -= 2.0f;
            Cursor.Pos.y -= 2.0f;
        if(IsKeyDown(Movement.Left))
            PPosition.x -= 2.0f;
            Cursor.Pos.x -= 2.0f;
        if(IsKeyDown(Movement.Right))
            PPosition.x += 2.0f;
            Cursor.Pos.x += 2.0f;
        if(IsKeyDown(Movement.Down))
            PPosition.y += 2.0f;
            Cursor.Pos.y += 2.0f;

        BeginDrawing();
            BeginMode2D(Window.Camera);

            ClearBackground(RAYWHITE);
            DrawText("hello inputs", 10, 20, 20, BLACK);
            DrawCircleV(PPosition, 50, BLACK);
            DrawCircleV(worldMousePos, 30, RED);
        EndDrawing();
    } 

    CloseWindow();

    return 0;
}