/*
    CPlayer Class.
*/

#include <string>
#include <vector>
#include <iostream>
using DominoTile = std::pair<int,int>;

class CPlayer
{
    public:
    CPlayer(const std::string& n) : name(n)
    {
        hand = new std::vector<DominoTile>();
    }

    ~CPlayer()
    {
        delete hand;
    }

    // Add tile to hand.
    void add_tile(const DominoTile &tile)
    {
        hand->push_back(tile);
    }

    // Remove tile at index.
    DominoTile remove_at(int index)
    {
        DominoTile tile = hand->at(index);
        hand->erase(hand->begin() + index);

        return tile;
    }

    // Number of tiles in hand.
    int hand_size() const
    {
        return (int)hand->size();
    }

    // Find index of matching tile.
    int find_matching_index(int head_val, int tail_val) const
    {
        for (int i = 0; i < (int)hand->size(); ++i)
        {
            int a = hand->at(i).first, b = hand->at(i).second;

            if (a == head_val || b == head_val || a == tail_val || b == tail_val)
            {
                return i;
            }
        }

        return -1;
    }

    // Print hand.
    void display_hand() const
    {
        std::cout << name << "'s hand (" << hand_size() << "): ";

        for (auto &t : *hand)
        {
            std::cout << "[" << t.first << "|" << t.second << "] ";
        }

        std::cout << "\n";
    }

    std::string name;
    std::vector<DominoTile>* hand;
};