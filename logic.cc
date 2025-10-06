/*
    CGame Class (game logic).
*/

#include "random.cc"
#include "player.cc"
#include "table.cc"
#include "domino.cc"
#include "func.cxx"
using namespace std;
using dominoTile = pair<int,int>;

class CGame
{
    public:
    
    CGame()
    {
        rnd = new CRandom();
        table = new CTable();
        deck = new CDominoes();
        players.push_back(new CPlayer("Player 1"));
        players.push_back(new CPlayer("Player 2"));
        available = new vector<dominoTile>();
    }

    ~CGame()
    {
        delete rnd;
        delete table;
        delete deck;
        for (auto p : players) delete p;
        delete available;
    }

    // Play game.
    void play()
    {
        create_dominoes();
        draw_dominoes();
        int starter = who_first();
        cout << "Starting player: " << players[starter]->name << "\n";
        first_piece(starter);
        run_game(starter);
        game_over();
    }

    private:

    CRandom* rnd;
    CTable* table;
    CDominoes* deck;
    vector<CPlayer*> players;
    vector<dominoTile>* available;

    // Put shuffled set into available pool.
    void create_dominoes()
    {
        vector<dominoTile> all = deck->pieces;
        rnd->shuffle_vec(all);
        available->clear();
        available->insert(available->end(), all.begin(), all.end());
    }

    // Give each player 10 tiles, put remaining into available.
    void draw_dominoes()
    {
        vector<dominoTile> pool = *available;
        players[0]->hand->clear();
        players[1]->hand->clear();
        for (int i = 0; i < 10; ++i)
        {
            dominoTile t = rnd->random_pop(pool);
            players[0]->add_tile(t);
        }
        for (int i = 0; i < 10; ++i)
        {
            dominoTile t = rnd->random_pop(pool);
            players[1]->add_tile(t);
        }
        available->clear();
        available->insert(available->end(), pool.begin(), pool.end());

        cout << "Initial hands and available pieces:\n\n";
        players[0]->display_hand();
        players[1]->display_hand();

        cout << "Available (" << available->size() << "): ";

        for (auto &t : *available)
        {
            cout << tile_to_str(t) << " ";
        }

        cout << "\n\n";
    }

    // Select starting player.
    int who_first()
    {
        return rnd->randint(0,1);
    }

    // Select first piece.
    void first_piece(int starter)
    {
        int sz = players[starter]->hand_size();
        int index = rnd->randint(0, sz-1);
        dominoTile p = players[starter]->remove_at(index);
        table->place_back(p);
        cout << players[starter]->name << " places first tile " << tile_to_str(p) << "\n";
        table->display_table();
    }

    // Main game loop.
    void run_game(int starter)
    {
        int current = 1 - starter;
        int consecutive_passes = 0;

        while (true)
        {
            CPlayer* pl = players[current];
            cout << "\n" << pl->name << "'s turn.\n";
            pl->display_hand();
            bool playedThisTurn = player_turn(pl);

            if (pl->hand_size() == 0)
            {
                cout << pl->name << " has placed all tiles and wins!\n";
                break;
            }

            if (!playedThisTurn)
            {
                consecutive_passes++;
            }
            
            else 
            {
                consecutive_passes = 0;
            }

            if (consecutive_passes >= 2)
            {
                cout << "Both players passed consecutively. Game is deadlocked.\n";
                break;
            }

            current = 1 - current;
        }
    }

    // Run player turn.
    bool player_turn(CPlayer* pl)
    {
        int headVal = table->head_value();
        int tailVal = table->tail_value();
        
        int matchIdx = pl->find_matching_index(headVal, tailVal);
        if (matchIdx != -1)
        {
            dominoTile tile = pl->remove_at(matchIdx);
            dominoTile oriented;

            if (tile.first == headVal || tile.second == headVal)
            {
                oriented = orient_for_head(tile, headVal);
                table->place_front(oriented);
                cout << pl->name << " plays " << tile_to_str(oriented) << " at head (matching " << headVal << ")\n";
            } 
            
            else
            {
                oriented = orient_for_tail(tile, tailVal);
                table->place_back(oriented);
                cout << pl->name << " plays " << tile_to_str(oriented) << " at tail (matching " << tailVal << ")\n";
            }

            table->display_table();

            return true;
        }

        while (!available->empty())
        {
            
            dominoTile drawn = rnd->random_pop(*available);
            pl->add_tile(drawn);
            cout << pl->name << " draws " << tile_to_str(drawn) << " (" << available->size() << " remaining)\n";
        
            headVal = table->head_value();
            tailVal = table->tail_value();

            int idxNow = pl->find_matching_index(headVal, tailVal);
            if (idxNow != -1)
            {
                
                dominoTile tile = pl->remove_at(idxNow);
                dominoTile oriented;

                if (tile.first == headVal || tile.second == headVal)
                {
                    oriented = orient_for_head(tile, headVal);
                    table->place_front(oriented);
                    cout << pl->name << " plays drawn tile " << tile_to_str(oriented) << " at head\n";
                } 
                
                else
                {
                    oriented = orient_for_tail(tile, tailVal);
                    table->place_back(oriented);
                    cout << pl->name << " plays drawn tile " << tile_to_str(oriented) << " at tail\n";
                }

                table->display_table();

                return true;
            }
            
        }
        
        cout << pl->name << " cannot play and no available tiles left. Pass.\n";
        return false;
    }

    // End of game. Print summary.
    void game_over() 
    {
        cout << "\n[[ Game Over - Final Results ]]\n";

        table->display_table();
        players[0]->display_hand();
        players[1]->display_hand();
        int s0 = players[0]->hand_size();
        int s1 = players[1]->hand_size();
        
        // P0 wins.
        if (s0 == 0)
        {
            cout << "Winner: " << players[0]->name << "\n";
            cout << players[1]->name << " left with " << s1 << " tiles: ";
            for (auto &t : *players[1]->hand) cout << tile_to_str(t) << " ";
            cout << "\n";
        }
        
        // P1 wins.
        else if (s1 == 0)
        {
            cout << "Winner: " << players[1]->name << "\n";
            cout << players[0]->name << " left with " << s0 << " tiles: ";
            for (auto &t : *players[0]->hand) cout << tile_to_str(t) << " ";
            cout << "\n";
        }
        
        // Deadlocked: Fewer tiles wins, if equal then tied.
        else 
        {
            if (s0 < s1)
            {
                cout << "Deadlocked. Winner by fewer tiles: " << players[0]->name << "\n";
                cout << players[1]->name << " left with " << s1 << " tiles: ";
                for (auto &t : *players[1]->hand) cout << tile_to_str(t) << " ";
                cout << "\n";
            }
            
            else if (s1 < s0)
            {
                cout << "Deadlocked. Winner by fewer tiles: " << players[1]->name << "\n";
                cout << players[0]->name << " left with " << s0 << " tiles: ";
                for (auto &t : *players[0]->hand) cout << tile_to_str(t) << " ";
                cout << "\n";
            } 
            
            else
            {
                cout << "Deadlocked. Tied. Equal number of tiles: (" << s0 << ").\n";
            }
        }

        cout << "\nAvailable pile remaining (" << available->size() << "): ";

        for (auto &t : *available)
        {
            cout << tile_to_str(t) << " ";
        }

        cout << "\n";
    }
};