#include "block.h"
#include <iostream>

Block::Block()
{
    cellSize = 30;
    rotationState = 0;
    colors = GetCellColors();
    rowOffset = 0;
    columnOffset = 0;
}

//void Block::Draw(int offsetX, int offsetY)
//{
//    std::vector<Position> tiles = GetCellPositions(); //assign the block position (0,2),(2,3) something
//    for (Position item : tiles)
//    {
//        DrawRectangle(item.column * cellSize + offsetX, item.row * cellSize + offsetY, cellSize - 1, cellSize - 1, colors[id]);
//    }
//}

void Block::Draw(int offsetX, int offsetY)
{
    std::vector<Position> tiles = GetCellPositions();

    // Add this bounds check ?
    if (id < 1 || id >= (int)colors.size()) {
        // Handle error (e.g., default to background color)
        std::cerr << "Invalid block ID: " << id << std::endl;
        return;
    }

    for (Position item : tiles)
    {
        DrawRectangle(
            item.column * cellSize + offsetX,
            item.row * cellSize + offsetY,
            cellSize - 1,
            cellSize - 1,
            colors[id] // Now safe to access
        );
    }
}


//////////////////////////////////////////////////////////
void Block::Move(int rows, int columns)
{
    rowOffset += rows;
    columnOffset += columns;
}

std::vector<Position> Block::GetCellPositions() //to change the positions of block
{
    std::vector<Position> tiles = cells[rotationState];
    std::vector<Position> movedTiles;
    for (Position item : tiles)
    {
        Position newPos = Position(item.row + rowOffset, item.column + columnOffset);
        movedTiles.push_back(newPos);
    }
    return movedTiles;
}

void Block::Rotate() //implementation of rotate method.
{
    /*
    in order to rotate the block we will incremenetit by 1
    and we need to check if the block has reached its max rotation limit which is 4 normally
    so we will be having some conditional check as well.
    except O-block 
    */

    rotationState++;
    if (rotationState == (int)cells.size())
    {
        rotationState = 0; //resetting the block rotation to 0 if the limit has been exceeded.
    }
}

void Block::UndoRotation()
{
    rotationState--; //by this we have set the rotation of the block back to its previous one

    //now we will check if the rotationstate is -1 then we will assign the block its maximum rotationState.

    if (rotationState == -1)
    {
        rotationState = cells.size() - 1;
    }
}
