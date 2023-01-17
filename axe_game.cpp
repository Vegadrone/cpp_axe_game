#include "raylib.h"



int main(){
    
    /*
        You need to put the loop AFTER InitWindow to see the popup window
    */

    //Windows dimensions
    int w = 800;
    int h = 450;

    InitWindow(w, h, "POPUP");

    //Circle coordinates
    int circle_y {w/2};
    int circle_x {h/2};
    int circle_radius {50};

    //Axe Coordinates
    int axe_x {400};
    int axe_y {0};
    int axe_direction {10};

    SetTargetFPS(60);
    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(RED);

        //Game logic begins

        DrawCircle(circle_x, circle_y, circle_radius, BLUE);
        DrawRectangle(axe_x, axe_y, 150, 150, WHITE);

        //axe movement
        axe_y += axe_direction;

        if (axe_y > 300 || axe_y < 0)
        {
            axe_direction = -axe_direction;
        }
        

        //Circle movement
        if (IsKeyDown(KEY_D) && circle_x < (w - circle_radius))
        {
            circle_x += 10;
        }

        if (IsKeyDown(KEY_A) && circle_x > (0 + circle_radius))
        {
            circle_x -= 10;
        }

        if (IsKeyDown(KEY_W) && circle_y > (0 + circle_radius))
        {
            circle_y -= 10;
        }

        if (IsKeyDown(KEY_S) && circle_y < (h - circle_radius) )
        {
            circle_y += 10;
        }

        //Game logic ends
        EndDrawing();
    }
}