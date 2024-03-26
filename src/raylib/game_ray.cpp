
#include "raylib.h"
#include <iostream>

/*
    ||||
    ||||
    sdjk 
*/

struct // declared so in settings I can directly assign the keys to these. 
{  
    KeyboardKey leave; // just here to hold place for 'esc' key. 
    KeyboardKey reset;
    KeyboardKey menu; 

    KeyboardKey left;
    KeyboardKey up;
    KeyboardKey down;
    KeyboardKey right;
}Inputs;

struct
{   Vector2 Pos;
    Rectangle Rec; // for input checking 
}Cursor;

typedef enum
{   Game_Intro,     
    Game_Menu,
    Game_Settings,
    Game_Play
}Game_State;


struct 
{   int Width, Height;
    const char *Title;
    int TargetFps;
    Game_State state;
}Window;

void createWindow()
{
    InitWindow(Window.Width, Window.Height, Window.Title);
    SetTargetFPS(Window.TargetFps);
}

void loadData()
{
    int score = 0;
    int miss = 0;
    Window.Width = 500;
    Window.Height = 500;
    Window.TargetFps = 60;
    Window.Title = "ray mania!";
    
    Inputs.leave = KEY_ESCAPE; 
    Inputs.menu = KEY_TAB;
    Inputs.reset = KEY_LEFT_ALT;

    Inputs.up = KEY_J;
    Inputs.down = KEY_F;
    Inputs.left = KEY_D; 
    Inputs.right = KEY_K;
}
 
void StartGame()
{
    int fpsCounter = 0;
    Vector2 mousePos = GetMousePosition();
    Window.state = Game_Intro;

    while (!WindowShouldClose())
    {
        switch (Window.state) {
            case Game_Intro:
                {   fpsCounter++;
                    if(fpsCounter > 180)
                        Window.state = Game_Menu;
                }break;
            case Game_Menu:
                {}break;
                // check two rect interactions 
            case Game_Play:
                {}break;
                // the game
            case Game_Settings:
                {}break;
                // check rect interactions
        }   
        
        BeginDrawing();
            switch (Window.state)
            {
                case Game_Intro:
                    DrawFPS(10, 10);
                    DrawText("intro", 20, 20, 3, BLACK);
                case Game_Menu:
                    DrawFPS(10,10);
                    DrawRectangleV(mousePos, {10, 10}, RED); 
                case Game_Settings:
                    DrawFPS(10,10);
                    DrawRectangleV(mousePos, {10, 10}, RED); 
                case Game_Play:
                    DrawFPS(10,10);
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
