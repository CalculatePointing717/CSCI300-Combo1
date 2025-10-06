/*
    CPlayer Class.
*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;
using dominoTile = pair<int,int>;

class CPlayer
{
    public:
    CPlayer(const string& n) : name(n)
    {
        hand = new vector<dominoTile>();
    }

    ~CPlayer()
    {
        delete hand;
    }

    // Add tile to hand.
    void add_tile(const dominoTile &p)
    {
        hand->push_back(p);
    }

    // Remove tile at index.
    dominoTile remove_at(int index) {
        dominoTile p = hand->at(index);
        hand->erase(hand->begin() + index);

        return p;
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
            if (a == head_val || b == head_val || a == tail_val || b == tail_val) return i;
        }

        return -1;
    }

    // Print hand.
    void display_hand() const {
        cout << name << "'s hand (" << hand_size() << "): ";

        for (auto &t : *hand)
        {
            cout << "[" << t.first << "|" << t.second << "] ";
        }

        cout << "\n";
    }

    string name;
    vector<dominoTile>* hand;
};