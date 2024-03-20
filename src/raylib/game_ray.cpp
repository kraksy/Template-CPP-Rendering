
#include "raylib.h"
#include <iostream>

/*
    ||||
    ||||
    sdjk 
*/

struct 
{
    int Width, Height;
    const char *Title;
    int TargetFps;
    Camera2D Camera = { 0 };
}Window{1200, 1200, "raylib mania", 60};

struct 
{
    KeyboardKey left;
    KeyboardKey up;
    KeyboardKey down;
    KeyboardKey right;
}Inputs{KEY_D, KEY_F, KEY_J, KEY_K};

static Vector2 CameraBase = { 0, 0 };

void StartMenu()
{
    // --------- init ------------
    Window.Camera.target = CameraBase; // set camera back to zero so its back in the place when going from game to menu 

    // ---------- loop -----------

    BeginDrawing();
        BeginMode2D(Window.Camera);
        ClearBackground(RAYWHITE);

        DrawText("", 10, 20, 20, BLACK);
    EndDrawing();

}   

void StartSettings()
{
    // --------- init ------------
    Window.Camera.target = CameraBase;


    BeginDrawing();
        BeginMode2D(Window.Camera);

        ClearBackground(RAYWHITE);
        DrawText("SETTINGS", 10, 20, 20, BLACK);
    EndDrawing();

}

void StartGame()
{
    // --------- init ------------
    int score = 0;
    int miss = 0;

        BeginDrawing();
            BeginMode2D(Window.Camera);

            ClearBackground(RAYWHITE);
            DrawText("hello inputs", 10, 20, 20, BLACK);
            DrawCircleV(worldMousePos, 30, RED);
        EndDrawing();
}


int main()
{
    
    while (!WindowShouldClose())
    {
        



    }
    





    return 0;
}