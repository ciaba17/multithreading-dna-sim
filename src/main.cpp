#include "raylib.h"
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(nullptr));

    InitWindow(800, 600, "Hello Raylib");

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Hello World", 350, 280, 20, BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}