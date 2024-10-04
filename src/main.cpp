#include "raylib/raylib.h"

int main(void) {
    int WIDTH = 1000;
    int HEIGHT = 700;

    InitWindow(WIDTH, HEIGHT, "Yay!");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground({230, 230, 230, 255});

            DrawRectangle(100, 100, 200, 200, BLACK);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}