#include "raylib/raylib.h"
#include "headers/gate.h"
#include "headers/cable.h"

int main(void) {
    int WIDTH = 1000;
    int HEIGHT = 700;

    bool mouseDown = false;

    InitWindow(WIDTH, HEIGHT, "Yay!");
    SetTargetFPS(60);

    Gate gate = Gate("not");
    Gate gate2 = Gate("xor");

    Cable cable = Cable(200, 200, 350, 400);

    gate2.worldPos.x = 300;

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground({230, 230, 230, 255});

            if (IsMouseButtonPressed(0)) {mouseDown = true;}
            if (IsMouseButtonReleased(0)) {mouseDown = false;}

            gate.dragAndDrop(mouseDown);
            gate.draw();

            gate2.dragAndDrop(mouseDown);
            gate2.draw();

            cable.draw();
        EndDrawing();
    }

    gate.destroy();
    gate2.destroy();

    CloseWindow();

    return 0;
}