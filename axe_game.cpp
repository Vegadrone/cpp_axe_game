#include "raylib.h"



int main(){
    
    /*
        You need to put the loop AFTER InitWindow to see the popup window
    */

    int h = 750;
    int w = 900;

    InitWindow(h, w, "POPUP");

    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(RED);
        DrawCircle((750/2), (900/2), 100, BLUE);
        EndDrawing();
    }
}