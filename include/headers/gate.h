#pragma once

#include "raylib/raylib.h"
#include <cmath>

class Gate {
public:
    Vector2 worldPos;

    Image image;
    Texture2D texture;

    const char* type;

    bool isBeingDragged = false;

    Gate(const char* _type) {
        type = _type;

        worldPos.x = 100;
        worldPos.y = 300;

        if (type == "and") {image = LoadImage("../build/assets/g7.png");}
        if (type == "or") {image = LoadImage("../build/assets/g9.png");}
        if (type == "not") {image = LoadImage("../build/assets/g12.png");}
        if (type == "xor") {image = LoadImage("../build/assets/g15.png");}
        
        texture = LoadTextureFromImage(image);
        UnloadImage(image);
    }

    void dragAndDrop(bool _mouseDown) {
        Vector2 mousePos = GetMousePosition();

        int deltaX = mousePos.x - worldPos.x;
        int deltaY = mousePos.y - worldPos.y;
        float distance = std::sqrt(deltaX*deltaX + deltaY*deltaY);

        if (IsMouseButtonPressed(0) && distance < 100.0f) {
            isBeingDragged = true;
        }
        if (IsMouseButtonReleased(0)) {
            isBeingDragged = false;
        }

        if (isBeingDragged) {
            worldPos = mousePos;
        }
    }

    void draw() {
        DrawTexture(texture, worldPos.x, worldPos.y, WHITE);
    }

    void destroy() {
        UnloadTexture(texture);
    }
};