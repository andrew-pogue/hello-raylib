#include "raylib.h"

int main() {
    InitWindow(800, 450, "raylib demo");

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("HELLO, WORLD!", 190, 200, 20, BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
