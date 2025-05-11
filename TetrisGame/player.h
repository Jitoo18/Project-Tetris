#pragma once
#include <string>
#include <vector>
#include <raylib.h>

class PlayerManager {
public:
    bool isEnteringName = false;
    bool nameEntered = false;
    bool showRestartPrompt = false;
    std::string playerName = "";

    void StartNameEntry();
    void HandleNameInput();
    void DrawNameEntry();
    void SaveScore(int score);
    static std::vector<std::string> GetHighScores();

private:
    int charCount = 0;
};