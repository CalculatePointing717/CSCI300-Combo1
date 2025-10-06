# CSCI300 Combo #1: Dominoes Game
An auto-playing, text-based dominoes game written in C++

## Compiling

With g++ installed you can use the provided script: `make.sh`

Alternatively, you can use this command: `g++ dominoes-game.cpp -o game.bin`



## Usage

Use `run.sh` or run `game.bin` directly.

The game is played automatically and no user input is needed.



## Output
An exmaple of program output from a single run of the Dominoes Game:
```
Initial hands and available tiles:

Player 1's hand (10): [2|5] [3|5] [2|3] [1|4] [0|4] [1|2] [4|5] [5|5] [3|6] [0|5] 
Player 2's hand (10): [2|2] [4|4] [0|0] [1|5] [6|6] [0|2] [2|6] [3|3] [0|6] [5|6] 
Available (8): [0|1] [4|6] [0|3] [3|4] [1|6] [2|4] [1|3] [1|1] 

Starting player: Player 2
Player 2 places first tile [0|0]

Table: [0|0]

Player 1's turn.
Player 1's hand (10): [2|5] [3|5] [2|3] [1|4] [0|4] [1|2] [4|5] [5|5] [3|6] [0|5] 
Player 1 plays [4|0] at head (matching 0)

Table: [4|0]-[0|0]

Player 2's turn.
Player 2's hand (9): [2|2] [4|4] [1|5] [6|6] [0|2] [2|6] [3|3] [0|6] [5|6] 
Player 2 plays [4|4] at head (matching 4)

Table: [4|4]-[4|0]-[0|0]

Player 1's turn.
Player 1's hand (9): [2|5] [3|5] [2|3] [1|4] [1|2] [4|5] [5|5] [3|6] [0|5] 
Player 1 plays [1|4] at head (matching 4)

Table: [1|4]-[4|4]-[4|0]-[0|0]

Player 2's turn.
Player 2's hand (8): [2|2] [1|5] [6|6] [0|2] [2|6] [3|3] [0|6] [5|6] 
Player 2 plays [5|1] at head (matching 1)

Table: [5|1]-[1|4]-[4|4]-[4|0]-[0|0]

Player 1's turn.
Player 1's hand (8): [2|5] [3|5] [2|3] [1|2] [4|5] [5|5] [3|6] [0|5] 
Player 1 plays [2|5] at head (matching 5)

Table: [2|5]-[5|1]-[1|4]-[4|4]-[4|0]-[0|0]

Player 2's turn.
Player 2's hand (7): [2|2] [6|6] [0|2] [2|6] [3|3] [0|6] [5|6] 
Player 2 plays [2|2] at head (matching 2)

Table: [2|2]-[2|5]-[5|1]-[1|4]-[4|4]-[4|0]-[0|0]

Player 1's turn.
Player 1's hand (7): [3|5] [2|3] [1|2] [4|5] [5|5] [3|6] [0|5] 
Player 1 plays [3|2] at head (matching 2)

Table: [3|2]-[2|2]-[2|5]-[5|1]-[1|4]-[4|4]-[4|0]-[0|0]

Player 2's turn.
Player 2's hand (6): [6|6] [0|2] [2|6] [3|3] [0|6] [5|6] 
Player 2 plays [0|2] at tail (matching 0)

Table: [3|2]-[2|2]-[2|5]-[5|1]-[1|4]-[4|4]-[4|0]-[0|0]-[0|2]

Player 1's turn.
Player 1's hand (6): [3|5] [1|2] [4|5] [5|5] [3|6] [0|5] 
Player 1 plays [5|3] at head (matching 3)

Table: [5|3]-[3|2]-[2|2]-[2|5]-[5|1]-[1|4]-[4|4]-[4|0]-[0|0]-[0|2]

Player 2's turn.
Player 2's hand (5): [6|6] [2|6] [3|3] [0|6] [5|6] 
Player 2 plays [2|6] at tail (matching 2)

Table: [5|3]-[3|2]-[2|2]-[2|5]-[5|1]-[1|4]-[4|4]-[4|0]-[0|0]-[0|2]-[2|6]

Player 1's turn.
Player 1's hand (5): [1|2] [4|5] [5|5] [3|6] [0|5] 
Player 1 plays [4|5] at head (matching 5)

Table: [4|5]-[5|3]-[3|2]-[2|2]-[2|5]-[5|1]-[1|4]-[4|4]-[4|0]-[0|0]-[0|2]-[2|6]

Player 2's turn.
Player 2's hand (4): [6|6] [3|3] [0|6] [5|6] 
Player 2 plays [6|6] at tail (matching 6)

Table: [4|5]-[5|3]-[3|2]-[2|2]-[2|5]-[5|1]-[1|4]-[4|4]-[4|0]-[0|0]-[0|2]-[2|6]-[6|6]

Player 1's turn.
Player 1's hand (4): [1|2] [5|5] [3|6] [0|5] 
Player 1 plays [6|3] at tail (matching 6)

Table: [4|5]-[5|3]-[3|2]-[2|2]-[2|5]-[5|1]-[1|4]-[4|4]-[4|0]-[0|0]-[0|2]-[2|6]-[6|6]-[6|3]

Player 2's turn.
Player 2's hand (3): [3|3] [0|6] [5|6] 
Player 2 plays [3|3] at tail (matching 3)

Table: [4|5]-[5|3]-[3|2]-[2|2]-[2|5]-[5|1]-[1|4]-[4|4]-[4|0]-[0|0]-[0|2]-[2|6]-[6|6]-[6|3]-[3|3]

Player 1's turn.
Player 1's hand (3): [1|2] [5|5] [0|5] 
Player 1 draws [4|6] (7 remaining)
Player 1 plays drawn tile [6|4] at head

Table: [6|4]-[4|5]-[5|3]-[3|2]-[2|2]-[2|5]-[5|1]-[1|4]-[4|4]-[4|0]-[0|0]-[0|2]-[2|6]-[6|6]-[6|3]-[3|3]

Player 2's turn.
Player 2's hand (2): [0|6] [5|6] 
Player 2 plays [0|6] at head (matching 6)

Table: [0|6]-[6|4]-[4|5]-[5|3]-[3|2]-[2|2]-[2|5]-[5|1]-[1|4]-[4|4]-[4|0]-[0|0]-[0|2]-[2|6]-[6|6]-[6|3]-[3|3]

Player 1's turn.
Player 1's hand (3): [1|2] [5|5] [0|5] 
Player 1 plays [5|0] at head (matching 0)

Table: [5|0]-[0|6]-[6|4]-[4|5]-[5|3]-[3|2]-[2|2]-[2|5]-[5|1]-[1|4]-[4|4]-[4|0]-[0|0]-[0|2]-[2|6]-[6|6]-[6|3]-[3|3]

Player 2's turn.
Player 2's hand (1): [5|6] 
Player 2 plays [6|5] at head (matching 5)

Table: [6|5]-[5|0]-[0|6]-[6|4]-[4|5]-[5|3]-[3|2]-[2|2]-[2|5]-[5|1]-[1|4]-[4|4]-[4|0]-[0|0]-[0|2]-[2|6]-[6|6]-[6|3]-[3|3]
Player 2 has placed all tiles!

---------------------------------
    Game Over - Final Results    
---------------------------------

Table: [6|5]-[5|0]-[0|6]-[6|4]-[4|5]-[5|3]-[3|2]-[2|2]-[2|5]-[5|1]-[1|4]-[4|4]-[4|0]-[0|0]-[0|2]-[2|6]-[6|6]-[6|3]-[3|3]
Player 1's hand (2): [1|2] [5|5] 
Player 2's hand (0): 
Winner: Player 2
Player 1 left with 2 tiles: [1|2] [5|5] 

Available pile remaining (7): [0|1] [0|3] [3|4] [1|6] [2|4] [1|3] [1|1] 
```


## License

This project is licensed under the GPL‑3.0 License – see [License](LICENSE) for details.
