#pragma once

#include "raylib/raylib.h"

void createLine(Vector2 &startPos, Vector2 &endPos, bool &_firstPartOfLine) {

}

class Cable {
public:
    Vector2 worldPos1;
    Vector2 worldPos2;

    Cable(int _x1, int _y1, int _x2, int _y2) {
        worldPos1.x = _x1; worldPos1.y = _y1;
        worldPos2.x = _x2; worldPos2.y = _y2;
    }

    void draw() {
        DrawCircle(worldPos1.x, worldPos1.y, 3, BLACK);
        DrawCircle(worldPos2.x, worldPos2.y, 3, BLACK);
        DrawLine(worldPos1.x, worldPos1.y, worldPos2.x, worldPos2.y, BLACK);
    }
};