#include "player.h"
#include <fstream>
#include <ctime>
using namespace std;

void PlayerManager::StartNameEntry() {
    playerName.clear();
    isEnteringName = true;
    charCount = 0;
}

void PlayerManager::HandleNameInput() {
    int key = GetCharPressed();
    while (key > 0 && charCount < 10) {
        if ((key >= 32) && (key <= 125)) {
            playerName += (char)key;
            charCount++;
        }
        key = GetCharPressed();
    }

    if (IsKeyPressed(KEY_BACKSPACE) && !playerName.empty()) {
        playerName.pop_back();
        charCount--;
    }
}

void PlayerManager::DrawNameEntry() {
    BeginDrawing();
    ClearBackground(BLACK);
    DrawText("ENTER YOUR NAME (MAX 10 CHAR)", 200, 300, 30, WHITE);
    DrawRectangle(200, 350, 400, 50, DARKGRAY);
    DrawText(playerName.c_str(), 210, 365, 30, WHITE);
    EndDrawing();
}

void PlayerManager::SaveScore(int score) {
    std::time_t now = std::time(0);
    struct tm time_info; // Declare a tm struct
    localtime_s(&time_info, &now); // Use the safer function
    char timestamp[20];
    std::strftime(timestamp, 20, "%Y-%m-%d %H:%M:%S", &time_info); // Pass the struct address

    std::ofstream file("scores.txt", std::ios::app);
    if (file) {
        file << playerName << "," << score << "," << timestamp << "\n";
    }
    isEnteringName = false;
}

vector<string> PlayerManager::GetHighScores() {
    vector<string> scores;
    ifstream file("scores.txt");
    string line;

    while (getline(file, line)) {
        scores.push_back(line);
    }

    // Manual sorting without algorithm header
    auto parseScore = [](const string& entry) {
        size_t firstComma = entry.find(',');
        size_t secondComma = entry.find(',', firstComma + 1);
        return stoi(entry.substr(firstComma + 1, secondComma - firstComma - 1));
        };

    // Bubble sort implementation
    for (size_t i = 0; i < scores.size(); ++i) {
        for (size_t j = 0; j < scores.size() - 1 - i; ++j) {
            int currentScore = parseScore(scores[j]);
            int nextScore = parseScore(scores[j + 1]);

            if (currentScore < nextScore) {
                string temp = scores[j];
                scores[j] = scores[j + 1];
                scores[j + 1] = temp;
            }
        }
    }

    return scores;
}