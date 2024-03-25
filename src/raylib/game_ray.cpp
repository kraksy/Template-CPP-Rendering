
#include "raylib.h"
#include <iostream>

/*
    ||||
    ||||
    sdjk 
*/

struct 
{   int Width, Height;
    const char *Title;
    int TargetFps;
    Camera2D Camera = { 0 };
}Window{1200, 1200, "raylib mania", 60};

struct 
{   KeyboardKey left;
    KeyboardKey up;
    KeyboardKey down;
    KeyboardKey right;
}Inputs{KEY_D, KEY_F, KEY_J, KEY_K};

struct
{   Vector2 Pos;
}Cursor;

enum
{   Game_Menu,
    Game_Settings,
    Game_Play
}Game_State;

void createWindow()
{
    InitWindow(Window.Width, Window.Height, Window.Title);
    SetTargetFPS(Window.TargetFps);
}

void loadData()
{
    static Vector2 CameraBase = { 0, 0 };
    Window.Camera.target = CameraBase;
    int score = 0;
    int miss = 0;
    Window.Width = 800;
    Window.Height = 450;
    Window.TargetFps = 60;
    Window.Title = "ray mania!";
    Window.Camera.offset = { (float)Window.Width/2, (float)Window.Height/2 };
    Window.Camera.rotation = 0.0f;
    Window.Camera.target = Cursor.Pos;
    Window.Camera.zoom = 1.f;
}



void StartMenu()
{
    loadData();

    BeginDrawing();
        BeginMode2D(Window.Camera);
        ClearBackground(RAYWHITE);

        DrawText("", 10, 20, 20, BLACK);
    EndDrawing();

}   

void StartSettings()
{
    loadData();

    BeginDrawing();
        BeginMode2D(Window.Camera);

        ClearBackground(RAYWHITE);
        DrawText("SETTINGS", 10, 20, 20, BLACK);
    EndDrawing();

}

void StartGame()
{
    loadData();
    
    Vector2 StartLine = {3, 0};
    Vector2 EndLine = {3, 200};

    while (!WindowShouldClose())
    {
        Cursor.Pos = GetMousePosition();
        BeginDrawing();
            BeginMode2D(Window.Camera);

            ClearBackground(RAYWHITE);
            DrawText("hello inputs", 10, 20, 20, BLACK);

            for (size_t i = 0; i < 5; i++)
            {
               DrawLineEx({StartLine.x*i, StartLine.y*i}, {EndLine.x*i, EndLine.y*i}, 1, BLACK);
            }

        EndDrawing();        
    }
}

int main()
{
    createWindow();
    loadData();
    StartGame();
    return 0;
}