#include "MenuScreen.h"

void MenuScreen::LoadResources() {
    background = LoadTexture("D:/UNI/VS 22/TetrisGame/background-1.png");
    font = LoadFontEx("resources/alagard.ttf", 64, 0, 0);
}

void MenuScreen::UnloadResources(){
    UnloadTexture(background);
    UnloadFont(font);
}

bool MenuScreen::ShouldStartGame() {
    Rectangle playButton = { 300, 400, 200, 50 };
    Vector2 mousePoint = GetMousePosition();

    if (CheckCollisionPointRec(mousePoint, playButton)) {
        return IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
    }
    return false;
}

void MenuScreen::DrawMenu() {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawTexture(background, 0, 0, WHITE);
    DrawTextEx(font, "GAME", { 300, 200 }, 72, 2, GOLD);
    DrawRectangleRounded({ 300, 400, 200, 50 }, 0.3, 6, BLACK);
    DrawTextEx(font, "START", { 345, 410 }, 36, 2, WHITE);
    EndDrawing();
}