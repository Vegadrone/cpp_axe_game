#include "raylib.h"



int main(){
    
    /*
        You need to put the loop AFTER InitWindow to see the popup window
    */

    //Windows dimensions
    int h = 750;
    int w = 900;

    InitWindow(h, w, "POPUP");

    //Circle coordinates
    int circle_x {750/2};
    int circle_y {900/2};

    SetTargetFPS(60);
    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(RED);

        //Game logic begins

        DrawCircle(circle_x, circle_y, 100, BLUE);

        if (IsKeyDown(KEY_D))
        {
            circle_x = circle_x + 10;
        }

        if (IsKeyDown(KEY_A))
        {
            circle_x = circle_x - 10;
        }

        if (IsKeyDown(KEY_W))
        {
            circle_y = circle_y - 10;
        }

        if (IsKeyDown(KEY_S))
        {
            circle_y = circle_y + 10;
        }

        //Game logic ends
        EndDrawing();
    }
}