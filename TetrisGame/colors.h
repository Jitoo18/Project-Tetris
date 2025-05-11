//grid and block both needs colors 
#pragma once
#include <raylib.h>
#include <vector>
extern const Color darkGrey; //extern use to share a VARIABLE by declaring in one file and use in another
extern const Color green;
extern const Color red;
extern const Color orange;
extern const Color yellow;
extern const Color purple;
extern const Color purple;
extern const Color cyan;
extern const Color blue;
extern const Color lightBlue;
extern const Color darkBlue;

//

extern const Color teal;
extern const Color lime;
extern const Color magenta;
extern const Color pink;
extern const Color gold;
extern const Color skyBlue;
extern const Color olive;
extern const Color brown;
extern const Color silver;
extern const Color whiteSmoke;
extern const Color black;


std::vector<Color>GetCellColors();