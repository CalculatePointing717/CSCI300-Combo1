/*
    Helper functions.
*/

#include <string>
#include <sstream>
using namespace std;
using dominoTile = pair<int,int>;

// Convert tile to string.
string tile_to_str(const dominoTile &p)
{
    stringstream ss;
    ss << "[" << p.first << "|" << p.second << "]";
    return ss.str();
}

// Try to orient tile for placement at front/head.
dominoTile orient_for_head(const dominoTile &tile, int headVal)
{
    int a = tile.first, b = tile.second;

    if (b == headVal)
    {
        return dominoTile(a,b);
    }
    
    else if (a == headVal)
    {
        return dominoTile(b,a);
    }

    return dominoTile(-1,-1);
}

// Try to orient tile for placement at back/tail.
dominoTile orient_for_tail(const dominoTile &tile, int tailVal)
{
    int a = tile.first, b = tile.second;

    if (a == tailVal)
    {
        return dominoTile(a,b);
    } 
    
    else if (b == tailVal) 
    {
        return dominoTile(b,a);
    }

    return dominoTile(-1,-1);
}