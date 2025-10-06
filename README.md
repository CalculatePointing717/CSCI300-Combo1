# CSCI300 Combo #1: Dominoes Game
An auto-playing, text-based dominoes game written in C++

## Features

Automatic Gameplay

Text-Based Interface

Random Uniform Distribution

End-of-Game Summary



## Compiling

With g++ installed you can use the provided script: `make.sh`

Alternatively, you can use this command: `g++ dominoes-game.cpp -o game.bin`



## Usage

Use `run.sh` or run `game.bin` directly.

The game is played automatically and no user input is needed.



## Output
An exmaple of program output from a single run of the Dominoes Game:
```
Initial hands and available pieces:

Player 1's hand (10): [0|5] [2|3] [1|1] [3|3] [3|5] [2|6] [4|5] [0|0] [0|2] [0|1] 
Player 2's hand (10): [3|4] [2|2] [4|6] [2|5] [2|4] [4|4] [1|2] [5|6] [1|6] [1|5] 
Available (8): [0|6] [5|5] [6|6] [3|6] [1|3] [1|4] [0|4] [0|3] 

Starting player: Player 2
Player 2 places first tile [2|2]

Table: [2|2]

Player 1's turn.
Player 1's hand (10): [0|5] [2|3] [1|1] [3|3] [3|5] [2|6] [4|5] [0|0] [0|2] [0|1] 
Player 1 plays [3|2] at head (matching 2)

Table: [3|2]-[2|2]

Player 2's turn.
Player 2's hand (9): [3|4] [4|6] [2|5] [2|4] [4|4] [1|2] [5|6] [1|6] [1|5] 
Player 2 plays [4|3] at head (matching 3)

Table: [4|3]-[3|2]-[2|2]

Player 1's turn.
Player 1's hand (9): [0|5] [1|1] [3|3] [3|5] [2|6] [4|5] [0|0] [0|2] [0|1] 
Player 1 plays [2|6] at tail (matching 2)

Table: [4|3]-[3|2]-[2|2]-[2|6]

Player 2's turn.
Player 2's hand (8): [4|6] [2|5] [2|4] [4|4] [1|2] [5|6] [1|6] [1|5] 
Player 2 plays [6|4] at head (matching 4)

Table: [6|4]-[4|3]-[3|2]-[2|2]-[2|6]

Player 1's turn.
Player 1's hand (8): [0|5] [1|1] [3|3] [3|5] [4|5] [0|0] [0|2] [0|1] 
Player 1 draws [6|6] (7 remaining)
Player 1 plays drawn tile [6|6] at head

Table: [6|6]-[6|4]-[4|3]-[3|2]-[2|2]-[2|6]

Player 2's turn.
Player 2's hand (7): [2|5] [2|4] [4|4] [1|2] [5|6] [1|6] [1|5] 
Player 2 plays [5|6] at head (matching 6)

Table: [5|6]-[6|6]-[6|4]-[4|3]-[3|2]-[2|2]-[2|6]

Player 1's turn.
Player 1's hand (8): [0|5] [1|1] [3|3] [3|5] [4|5] [0|0] [0|2] [0|1] 
Player 1 plays [0|5] at head (matching 5)

Table: [0|5]-[5|6]-[6|6]-[6|4]-[4|3]-[3|2]-[2|2]-[2|6]

Player 2's turn.
Player 2's hand (6): [2|5] [2|4] [4|4] [1|2] [1|6] [1|5] 
Player 2 plays [6|1] at tail (matching 6)

Table: [0|5]-[5|6]-[6|6]-[6|4]-[4|3]-[3|2]-[2|2]-[2|6]-[6|1]

Player 1's turn.
Player 1's hand (7): [1|1] [3|3] [3|5] [4|5] [0|0] [0|2] [0|1] 
Player 1 plays [1|1] at tail (matching 1)

Table: [0|5]-[5|6]-[6|6]-[6|4]-[4|3]-[3|2]-[2|2]-[2|6]-[6|1]-[1|1]

Player 2's turn.
Player 2's hand (5): [2|5] [2|4] [4|4] [1|2] [1|5] 
Player 2 plays [1|2] at tail (matching 1)

Table: [0|5]-[5|6]-[6|6]-[6|4]-[4|3]-[3|2]-[2|2]-[2|6]-[6|1]-[1|1]-[1|2]

Player 1's turn.
Player 1's hand (6): [3|3] [3|5] [4|5] [0|0] [0|2] [0|1] 
Player 1 plays [0|0] at head (matching 0)

Table: [0|0]-[0|5]-[5|6]-[6|6]-[6|4]-[4|3]-[3|2]-[2|2]-[2|6]-[6|1]-[1|1]-[1|2]

Player 2's turn.
Player 2's hand (4): [2|5] [2|4] [4|4] [1|5] 
Player 2 plays [2|5] at tail (matching 2)

Table: [0|0]-[0|5]-[5|6]-[6|6]-[6|4]-[4|3]-[3|2]-[2|2]-[2|6]-[6|1]-[1|1]-[1|2]-[2|5]

Player 1's turn.
Player 1's hand (5): [3|3] [3|5] [4|5] [0|2] [0|1] 
Player 1 plays [5|3] at tail (matching 5)

Table: [0|0]-[0|5]-[5|6]-[6|6]-[6|4]-[4|3]-[3|2]-[2|2]-[2|6]-[6|1]-[1|1]-[1|2]-[2|5]-[5|3]

Player 2's turn.
Player 2's hand (3): [2|4] [4|4] [1|5] 
Player 2 draws [1|3] (6 remaining)
Player 2 plays drawn tile [3|1] at tail

Table: [0|0]-[0|5]-[5|6]-[6|6]-[6|4]-[4|3]-[3|2]-[2|2]-[2|6]-[6|1]-[1|1]-[1|2]-[2|5]-[5|3]-[3|1]

Player 1's turn.
Player 1's hand (4): [3|3] [4|5] [0|2] [0|1] 
Player 1 plays [2|0] at head (matching 0)

Table: [2|0]-[0|0]-[0|5]-[5|6]-[6|6]-[6|4]-[4|3]-[3|2]-[2|2]-[2|6]-[6|1]-[1|1]-[1|2]-[2|5]-[5|3]-[3|1]

Player 2's turn.
Player 2's hand (3): [2|4] [4|4] [1|5] 
Player 2 plays [4|2] at head (matching 2)

Table: [4|2]-[2|0]-[0|0]-[0|5]-[5|6]-[6|6]-[6|4]-[4|3]-[3|2]-[2|2]-[2|6]-[6|1]-[1|1]-[1|2]-[2|5]-[5|3]-[3|1]

Player 1's turn.
Player 1's hand (3): [3|3] [4|5] [0|1] 
Player 1 plays [5|4] at head (matching 4)

Table: [5|4]-[4|2]-[2|0]-[0|0]-[0|5]-[5|6]-[6|6]-[6|4]-[4|3]-[3|2]-[2|2]-[2|6]-[6|1]-[1|1]-[1|2]-[2|5]-[5|3]-[3|1]

Player 2's turn.
Player 2's hand (2): [4|4] [1|5] 
Player 2 plays [1|5] at head (matching 5)

Table: [1|5]-[5|4]-[4|2]-[2|0]-[0|0]-[0|5]-[5|6]-[6|6]-[6|4]-[4|3]-[3|2]-[2|2]-[2|6]-[6|1]-[1|1]-[1|2]-[2|5]-[5|3]-[3|1]

Player 1's turn.
Player 1's hand (2): [3|3] [0|1] 
Player 1 plays [0|1] at head (matching 1)

Table: [0|1]-[1|5]-[5|4]-[4|2]-[2|0]-[0|0]-[0|5]-[5|6]-[6|6]-[6|4]-[4|3]-[3|2]-[2|2]-[2|6]-[6|1]-[1|1]-[1|2]-[2|5]-[5|3]-[3|1]

Player 2's turn.
Player 2's hand (1): [4|4] 
Player 2 draws [1|4] (5 remaining)
Player 2 plays drawn tile [1|4] at tail

Table: [0|1]-[1|5]-[5|4]-[4|2]-[2|0]-[0|0]-[0|5]-[5|6]-[6|6]-[6|4]-[4|3]-[3|2]-[2|2]-[2|6]-[6|1]-[1|1]-[1|2]-[2|5]-[5|3]-[3|1]-[1|4]

Player 1's turn.
Player 1's hand (1): [3|3] 
Player 1 draws [5|5] (4 remaining)
Player 1 draws [3|6] (3 remaining)
Player 1 draws [0|4] (2 remaining)
Player 1 plays drawn tile [4|0] at head

Table: [4|0]-[0|1]-[1|5]-[5|4]-[4|2]-[2|0]-[0|0]-[0|5]-[5|6]-[6|6]-[6|4]-[4|3]-[3|2]-[2|2]-[2|6]-[6|1]-[1|1]-[1|2]-[2|5]-[5|3]-[3|1]-[1|4]

Player 2's turn.
Player 2's hand (1): [4|4] 
Player 2 plays [4|4] at head (matching 4)

Table: [4|4]-[4|0]-[0|1]-[1|5]-[5|4]-[4|2]-[2|0]-[0|0]-[0|5]-[5|6]-[6|6]-[6|4]-[4|3]-[3|2]-[2|2]-[2|6]-[6|1]-[1|1]-[1|2]-[2|5]-[5|3]-[3|1]-[1|4]
Player 2 has placed all tiles and wins!

[[ Game Over - Final Results ]]

Table: [4|4]-[4|0]-[0|1]-[1|5]-[5|4]-[4|2]-[2|0]-[0|0]-[0|5]-[5|6]-[6|6]-[6|4]-[4|3]-[3|2]-[2|2]-[2|6]-[6|1]-[1|1]-[1|2]-[2|5]-[5|3]-[3|1]-[1|4]
Player 1's hand (3): [3|3] [5|5] [3|6] 
Player 2's hand (0): 
Winner: Player 2
Player 1 left with 3 tiles: [3|3] [5|5] [3|6] 

Available pile remaining (2): [0|6] [0|3]
```


## License

This project is licensed under the GPL‑3.0 License – see [License](LICENSE) for details.
