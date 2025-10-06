/*
    CTable Class.
*/

#include <vector>
#include <iostream>
using namespace std;
using dominoTile = pair<int,int>;

class CTable
{
    public:
    CTable() 
    {
        tableSeq = new vector<dominoTile>();
    }

    ~CTable()
    {
        delete tableSeq;
    }

    // Place piece at front/head.
    void place_front(const dominoTile &p)
    {
        tableSeq->insert(tableSeq->begin(), p);
    }

    // Place piece at back/tail.
    void place_back(const dominoTile &p)
    {
        tableSeq->push_back(p);
    }

    // Table empty (has no tiles).
    bool empty() const
    {
        return tableSeq->empty();
    }

    // Value to match on front/head.
    int head_value() const
    {
        if (tableSeq->empty()) return -1;
        return tableSeq->front().first;
    }

    // Value to match on back/tail.
    int tail_value() const
    {
        if (tableSeq->empty()) return -1;
        return tableSeq->back().second;
    }

    // Print current table sequence.
    void display_table() const
    {
        cout << "\nTable: ";

        for (size_t i = 0; i < tableSeq->size(); ++i)
        {
            cout << "[" << tableSeq->at(i).first << "|" << tableSeq->at(i).second << "]";
            if (i + 1 < tableSeq->size())
            {
                cout << "-";
            }
        }

        cout << "\n";
    }

    // Return internal table sequence.
    vector<dominoTile> get_sequence() const
    {
        return *tableSeq;
    }

    private:
    vector<dominoTile>* tableSeq;
};
