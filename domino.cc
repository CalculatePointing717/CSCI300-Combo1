/*
    CDominoes Class.
*/

#include <vector>
using DominoTile = std::pair<int,int>;

class CDominoes
{
    public:
    CDominoes()
    {
        tiles.reserve(28);

        for (int a = 0; a <= 6; ++a)
        {
            for (int b = a; b <= 6; ++b)
            {
                tiles.emplace_back(a,b);
            }
        }
    }

    std::vector<DominoTile> tiles;
};