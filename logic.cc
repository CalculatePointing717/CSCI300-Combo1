/*
    CGame Class (game logic).
*/

#include "random.cc"
#include "player.cc"
#include "table.cc"
#include "domino.cc"
#include "func.cxx"
using DominoTile = std::pair<int,int>;

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
        available = new std::vector<DominoTile>();
    }

    ~CGame()
    {
        delete rnd;
        delete table;
        delete deck;
        for (auto tile : players)
        {
            delete tile;
        }
        delete available;
    }

    // Play game.
    void play()
    {
        create_dominoes();
        draw_dominoes();
        int starter = who_first();
        std::cout << "Starting player: " << players[starter]->name << "\n";
        first_piece(starter);
        run_game(starter);
        game_over();
    }

    private:

    CRandom* rnd;
    CTable* table;
    CDominoes* deck;
    std::vector<CPlayer*> players;
    std::vector<DominoTile>* available;

    // Put shuffled set into available pool.
    void create_dominoes()
    {
        std::vector<DominoTile> all = deck->tiles;
        rnd->shuffle_vec(all);
        available->clear();
        available->insert(available->end(), all.begin(), all.end());
    }

    // Give each player 10 tiles, put remaining into available.
    void draw_dominoes()
    {
        std::vector<DominoTile> pool = *available;
        players[0]->hand->clear();
        players[1]->hand->clear();
        for (int i = 0; i < 10; ++i)
        {
            DominoTile t = rnd->random_pop(pool);
            players[0]->add_tile(t);
        }
        for (int i = 0; i < 10; ++i)
        {
            DominoTile t = rnd->random_pop(pool);
            players[1]->add_tile(t);
        }
        available->clear();
        available->insert(available->end(), pool.begin(), pool.end());

        std::cout << "Initial hands and available tiles:\n\n";
        players[0]->display_hand();
        players[1]->display_hand();

        std::cout << "Available (" << available->size() << "): ";

        for (auto &t : *available)
        {
            std::cout << tile_to_string(t) << " ";
        }

        std::cout << "\n\n";
    }

    // Select starting player.
    int who_first()
    {
        return rnd->random_int(0,1);
    }

    // Select first tile.
    void first_piece(int starter)
    {
        int size = players[starter]->hand_size();
        int index = rnd->random_int(0, size-1);
        DominoTile tile = players[starter]->remove_at(index);
        table->place_back(tile);
        std::cout << players[starter]->name << " places first tile " << tile_to_string(tile) << "\n";
        table->display_table();
    }

    // Main game loop.
    void run_game(int starter)
    {
        int current = 1 - starter;
        int consecutive_passes = 0;

        while (true)
        {
            CPlayer* player = players[current];
            std::cout << "\n" << player->name << "'s turn.\n";
            player->display_hand();
            bool playedThisTurn = player_turn(player);

            if (player->hand_size() == 0)
            {
                std::cout << player->name << " has placed all tiles!\n";
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
                std::cout << "Both players passed consecutively. Game is deadlocked.\n";
                break;
            }

            current = 1 - current;
        }
    }

    // Run player turn.
    bool player_turn(CPlayer* player)
    {
        int headVal = table->head_value();
        int tailVal = table->tail_value();
        
        int matchIndex = player->find_matching_index(headVal, tailVal);
        if (matchIndex != -1)
        {
            DominoTile tile = player->remove_at(matchIndex);
            DominoTile oriented;

            if (tile.first == headVal || tile.second == headVal)
            {
                oriented = orient_for_head(tile, headVal);
                table->place_front(oriented);
                std::cout << player->name << " plays " << tile_to_string(oriented) << " at head (matching " << headVal << ")\n";
            } 
            
            else
            {
                oriented = orient_for_tail(tile, tailVal);
                table->place_back(oriented);
                std::cout << player->name << " plays " << tile_to_string(oriented) << " at tail (matching " << tailVal << ")\n";
            }

            table->display_table();

            return true;
        }

        while (!available->empty())
        {
            
            DominoTile drawn = rnd->random_pop(*available);
            player->add_tile(drawn);
            std::cout << player->name << " draws " << tile_to_string(drawn) << " (" << available->size() << " remaining)\n";
        
            headVal = table->head_value();
            tailVal = table->tail_value();

            int indexNow = player->find_matching_index(headVal, tailVal);
            if (indexNow != -1)
            {
                
                DominoTile tile = player->remove_at(indexNow);
                DominoTile oriented;

                if (tile.first == headVal || tile.second == headVal)
                {
                    oriented = orient_for_head(tile, headVal);
                    table->place_front(oriented);
                    std::cout << player->name << " plays drawn tile " << tile_to_string(oriented) << " at head\n";
                } 
                
                else
                {
                    oriented = orient_for_tail(tile, tailVal);
                    table->place_back(oriented);
                    std::cout << player->name << " plays drawn tile " << tile_to_string(oriented) << " at tail\n";
                }

                table->display_table();

                return true;
            }
            
        }
        
        std::cout << player->name << " cannot play and no available tiles left. Pass.\n";
        return false;
    }

    // End of game. Print summary.
    void game_over() 
    {
        std::cout << "\n---------------------------------";
        std::cout << "\n    Game Over - Final Results    ";
        std::cout << "\n---------------------------------\n";

        table->display_table();
        players[0]->display_hand();
        players[1]->display_hand();
        int s0 = players[0]->hand_size();
        int s1 = players[1]->hand_size();
        
        // P0 wins.
        if (s0 == 0)
        {
            std::cout << "Winner: " << players[0]->name << "\n";
            std::cout << players[1]->name << " left with " << s1 << " tiles: ";
            for (auto &t : *players[1]->hand)
            {
                std::cout << tile_to_string(t) << " ";
            }
            std::cout << "\n";
        }
        
        // P1 wins.
        else if (s1 == 0)
        {
            std::cout << "Winner: " << players[1]->name << "\n";
            std::cout << players[0]->name << " left with " << s0 << " tiles: ";
            for (auto &t : *players[0]->hand)
            {
                std::cout << tile_to_string(t) << " ";
            }
            std::cout << "\n";
        }
        
        // Deadlocked: Fewer tiles wins, if equal then tied.
        else 
        {
            if (s0 < s1)
            {
                std::cout << "Deadlocked. Winner by fewer tiles: " << players[0]->name << "\n";
                std::cout << players[1]->name << " left with " << s1 << " tiles: ";
                for (auto &t : *players[1]->hand) std::cout << tile_to_string(t) << " ";
                std::cout << "\n";
            }
            
            else if (s1 < s0)
            {
                std::cout << "Deadlocked. Winner by fewer tiles: " << players[1]->name << "\n";
                std::cout << players[0]->name << " left with " << s0 << " tiles: ";
                for (auto &t : *players[0]->hand)
                {
                    std::cout << tile_to_string(t) << " ";
                }
                std::cout << "\n";
            } 
            
            else
            {
                std::cout << "Deadlocked. Tied. Equal number of tiles: (" << s0 << ").\n";
            }
        }

        std::cout << "\nAvailable pile remaining (" << available->size() << "): ";

        for (auto &t : *available)
        {
            std::cout << tile_to_string(t) << " ";
        }

        std::cout << "\n";
    }
};