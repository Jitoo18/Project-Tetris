#include <iostream>
#include "raylib.h"
#include "game.h"
#include "colors.h"
#include "MenuScreen.h"

// #include "player.h"

double lastUpdateTime = 0; //this will be used to see when is the last time the game got updated.
//but this is equal to 0 only when the game starts.

static bool EventTriggered(double interval) //double interval is used to get interval tracks.
{
    /*
    now this is happeneing because without it the tetris block was falling rapidly because the loop makes the blck fall 60 times/sec etc.
    so to take it slow like to 200 seconds etc we use ths event triggered thing.
    getTime is used to get the current time in second.
    */

    double currentTime = GetTime(); //this currentTime is the variable we assigning the interval to.

    //now lets compare the currentTime and lastUpdatedTime.
    if (currentTime - lastUpdateTime >= interval)
    {
        //means that the time interval has already passed since the last update.
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}


int main() {

    /*InitWindow(600, 700, "raylib Tetris");*/

    InitWindow(800, 720, "raylib Tetris");
    SetTargetFPS(60); //speed will be same for all computer

    MenuScreen menu;
    menu.LoadResources();
    while (!WindowShouldClose() && menu.showMenu) {
        menu.showMenu = !menu.ShouldStartGame();
        menu.DrawMenu();
    }

    Game game = Game();

    /*
    Grid grid=Grid();
    grid.Print();
    LBlock block=LBlock();
    */

    Font font = LoadFontEx("monogram.ttf", 64, 0, 0);

    while (WindowShouldClose() == false)
    {
        UpdateMusicStream(game.music);
        game.HandleInput(); //to call the methods in the game loop we called the handleinput here in main file.
        if (EventTriggered(0.35))
        {
            //we want the block to fall in 0.3s

            game.MoveBlockDown();
        }

        BeginDrawing();
        ClearBackground(olive);       //this is the game loop 
        DrawTextEx(font, "Score", { 365,15 }, 38, 2, WHITE);
        DrawTextEx(font, "Next", { 370,175 }, 38, 2, WHITE);
        
        if (game.gameOver)
         {
             DrawTextEx(font, "GAME OVER", { 320,450 }, 38, 2, WHITE);
         }
         

        //if (game.gameOver) {
        //    if (!playerManager.isEnteringName) {
        //        playerManager.StartNameEntry();
        //    }

        //    if (!playerManager.isEnteringName && playerManager.showRestartPrompt) {
        //        // Display high scores
        //        auto highscores = PlayerManager::GetHighScores();
        //        int yPos = 550;  // Starting Y position

        //        DrawTextEx(font, "HIGH SCORES:", { 250.0f, 520.0f }, 28.0f, 2.0f, GOLD);

        //        // Display top 5 scores
        //        for (int i = 0; i < 5 && i < highscores.size(); i++) {
        //            size_t firstComma = highscores[i].find(',');
        //            size_t secondComma = highscores[i].find(',', firstComma + 1);

        //            std::string name = highscores[i].substr(0, firstComma);
        //            std::string score = highscores[i].substr(firstComma + 1,
        //                secondComma - firstComma - 1);

        //            DrawTextEx(font, TextFormat("%s: %s", name.c_str(), score.c_str()),
        //                { 250, yPos }, 24, 2, WHITE);
        //            yPos += 30;
        //        }
        //    }
        //    EndDrawing();

        //}
        //else
        //{
        //    DrawTextEx(font, "GAME OVER", { 320,450 }, 38, 2, WHITE);
        //}


        DrawRectangleRounded({ 320,55,177,60 }, 0.3, 6, black);
        char scoreText[10]{};
        snprintf(scoreText, sizeof(scoreText), "%d", game.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);


        DrawTextEx(font, scoreText, { 320 + (170 - textSize.x) / 2, 65 }, 38, 2, GOLD);
        DrawRectangleRounded({ 320,215,177,180 }, 0.3, 6, black);
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
}