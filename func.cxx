/*
    Helper functions.
*/

#include <string>
#include <sstream>
using DominoTile = std::pair<int,int>;

// Convert tile to string.
std::string tile_to_string(const DominoTile &tile)
{
    std::stringstream ss;
    ss << "[" << tile.first << "|" << tile.second << "]";
    return ss.str();
}

// Try to orient tile for placement at front/head.
DominoTile orient_for_head(const DominoTile &tile, int headVal)
{
    int a = tile.first, b = tile.second;

    if (b == headVal)
    {
        return DominoTile(a,b);
    }
    
    else if (a == headVal)
    {
        return DominoTile(b,a);
    }

    return DominoTile(-1,-1);
}

// Try to orient tile for placement at back/tail.
DominoTile orient_for_tail(const DominoTile &tile, int tailVal)
{
    int a = tile.first, b = tile.second;

    if (a == tailVal)
    {
        return DominoTile(a,b);
    } 
    
    else if (b == tailVal) 
    {
        return DominoTile(b,a);
    }

    return DominoTile(-1,-1);
}