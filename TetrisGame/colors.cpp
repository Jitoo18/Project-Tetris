#include "colors.h"

const Color darkGrey = { 26, 31, 40, 255 };
const Color green = { 47, 230, 23, 255 };
const Color red = { 232, 18, 18, 255 };
const Color orange = { 226, 116, 17, 255 };
const Color yellow = { 237, 234, 4, 255 };
const Color purple = { 166, 0, 247, 255 };
const Color cyan = { 21, 204, 209, 255 };
const Color blue = { 13, 64, 216, 255 };
const Color lightBlue = { 59, 85, 162, 255 };
const Color darkBlue = { 44, 44, 127, 255 };

// extra colors added

const Color teal = { 0, 128, 128, 255 };
const Color lime = { 173, 255, 47, 255 };
const Color magenta = { 255, 0, 255, 255 };
const Color pink = { 255, 105, 180, 255 };
const Color gold = { 255, 215, 0, 255 };
const Color skyBlue = { 135, 206, 235, 255 };
const Color olive = { 128, 128, 0, 255 };
const Color brown = { 139, 69, 19, 255 };
const Color silver = { 192, 192, 192, 255 };
const Color whiteSmoke = { 245, 245, 245, 255 };
const Color black = { 0, 0, 0, 255 };



std::vector<Color> GetCellColors()
{
    return {
        darkGrey, // Index 0 (background)
        green,    // 1 (LBlock)
        red,      // 2 (JBlock)
        orange,   // 3 (IBlock)
        yellow,   // 4 (OBlock)
        purple,   // 5 (SBlock)
        cyan,     // 6 (TBlock)
        blue      // 7 (ZBlock)
    }; // ? Now has 8 elements (indices 0-7)
}