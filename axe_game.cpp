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
    int circle_y {200};
    int circle_x {200};
    int circle_radius {25};
    //Circle edges
    int l_circle_x {circle_x - circle_radius};
    int r_circle_x {circle_x + circle_radius};
    int u_circle_y {circle_y - circle_radius};
    int b_circle_y {circle_y + circle_radius};

    //Axe Coordinates
    int axe_x {400};
    int axe_y {0};
    int axe_direction {25};
    int axe_length {50};
    //Axe edges
    int l_axe_x{axe_x};
    int r_axe_x{axe_x + axe_length};
    int u_axe_y{axe_y};
    int b_axe_y{axe_y + axe_length};

    //Axe player collision
    bool collision_with_axe =
        (b_axe_y >= u_circle_y) &&
        (u_axe_y <= b_circle_y) &&
        (r_axe_x >= l_circle_x) &&
        (l_axe_x <= r_circle_x);

    //Counter
    int score_counter {};

    /*
        Per aumentare il punteggio il cerchio deve passare dall'altra parte dell'area di collisione dell'axe
        questo vuol dire che per ogni frame dovrei prendere la posizione del cerchio da dove parte e quella dove finisce
        quest ultima va confrontata con l'area di collisione.
    */

    //Player avoid axe
    bool is_axe_avoided = 
        (l_circle_x > r_axe_x);

    SetTargetFPS(60);
    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(RED);

        if (collision_with_axe)
        {
            DrawText("GAME OVER!!!\n", 235, 200, 50, YELLOW);
            DrawText(TextFormat("Your Score is: %i", score_counter), 280, 250, 25, YELLOW);
        }
        
        else
        {
            //Game logic begins

            //Recalculate edges
            //Circle edges
            l_circle_x = circle_x - circle_radius;
            r_circle_x = circle_x + circle_radius;
            u_circle_y = circle_y - circle_radius;
            b_circle_y = circle_y + circle_radius;

            //Axe edges
            l_axe_x = axe_x;
            r_axe_x = axe_x + axe_length;
            u_axe_y = axe_y;
            b_axe_y = axe_y + axe_length;

            //update collision with axe
            collision_with_axe =
                (b_axe_y >= u_circle_y) &&
                (u_axe_y <= b_circle_y) &&
                (r_axe_x >= l_circle_x) &&
                (l_axe_x <= r_circle_x);

            //update if axe is avoided
            is_axe_avoided =
                (l_circle_x > r_axe_x);

            DrawCircle(circle_x, circle_y, circle_radius, BLUE);
            DrawRectangle(axe_x, axe_y, axe_length, axe_length, WHITE);
            DrawText(TextFormat("Player score: %i", score_counter), 10, 10, 25, YELLOW);

            //axe movement
            axe_y += axe_direction;

            if (axe_y > (h - axe_length) || axe_y < 0)
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

            if (IsKeyDown(KEY_S) && circle_y < (h - circle_radius))
            {
                circle_y += 10;
            }

            //Update score
            if (is_axe_avoided)
            {
                score_counter += 1;
            }
            
            //Game logic ends
        }
            EndDrawing();
    }
}