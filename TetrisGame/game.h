#pragma once
#include "grid.h"
#include "blocks.cpp"

class Game
{
public:
    Game();
    ~Game();
    void Draw();
    void HandleInput(); //This is used to handle in form of key strikes inputted by the user.
    void MoveBlockDown();
    bool gameOver;
    int score;
    Music music;
    void Reset();


private:
    void MoveBlockLeft();
    void MoveBlockRight();
    Block GetRandomBlock();
    std::vector<Block> GetAllBlocks(); //holding all blocks
    bool IsBlockOutside();
    void RotateBlock();
    void LockBlock();
    bool BlockFits(); //this will check if the block is setting up on the empty cell or not.
//    void Reset();
    void UpdateScore(int linesCleared, int moveDownPoints);
    Grid grid;
    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
    Sound rotateSound;
    Sound clearSound;
};