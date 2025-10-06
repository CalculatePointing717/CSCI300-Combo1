/*
    CTable Class.
*/

#include <vector>
#include <iostream>
using DominoTile = std::pair<int,int>;

class CTable
{
    public:
    CTable() 
    {
        table = std::vector<DominoTile>();
    }

    // Place tile at front/head.
    void place_front(const DominoTile &tile)
    {
        table.insert(table.begin(), tile);
    }

    // Place tile at back/tail.
    void place_back(const DominoTile &tile)
    {
        table.push_back(tile);
    }

    // Table empty (has no tiles).
    bool empty() const
    {
        return table.empty();
    }

    // Value to match on front/head.
    int head_value() const
    {
        if (table.empty())
        {
            return -1;
        }

        return table.front().first;
    }

    // Value to match on back/tail.
    int tail_value() const
    {
        if (table.empty())
        {
            return -1;
        }
        
        return table.back().second;
    }

    // Print current table sequence.
    void display_table() const
    {
        std::cout << "\nTable: ";

        for (size_t i = 0; i < table.size(); ++i)
        {
            std::cout << "[" << table.at(i).first << "|" << table.at(i).second << "]";

            if (i + 1 < table.size())
            {
                std::cout << "-";
            }
        }

        std::cout << "\n";
    }

    // Return internal table sequence.
    std::vector<DominoTile> get_sequence() const
    {
        return table;
    }

    private:
    std::vector<DominoTile> table;
};
