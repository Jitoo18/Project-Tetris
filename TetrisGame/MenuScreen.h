#pragma once
#include <raylib.h>

class MenuScreen {
public:
    bool showMenu = true;
    Texture2D background;
    Font font;

    void LoadResources();
    void UnloadResources();
    bool ShouldStartGame();
    void DrawMenu();
};