/*
    CDominoes Class.
*/

#include <vector>
using namespace std;
using dominoTile = pair<int,int>;

class CDominoes
{
    public:
    CDominoes()
    {
        pieces.reserve(28);

        for (int a = 0; a <= 6; ++a)
        {
            for (int b = a; b <= 6; ++b)
            {
                pieces.emplace_back(a,b);
            }
        }
    }

    vector<dominoTile> pieces;
};