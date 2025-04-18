# Tic-Tac-Toe
A simple 2-player Tic-Tac-Toe game built in C++ for the command-line interface. It allows two human players to take turns placing X and O on a 3x3 board. The game detects wins, draws, and prevents overwriting filled slots.

👉Feature :-
  Two-player gameplay (Player 1 vs Player 2)
  Easy-to-read 3x3 board layout
  Input validation for invalid or occupied slots\
  Automatic win or draw detection
  Clean console output

🧠 How It Works
The board is represented using a 2D array.
Players choose positions using numbers 1–9 (mapped to 2D matrix indices).
The program checks for a win after every move (rows, columns, diagonals).
If all spots are filled without a winner, the game ends in a draw.

📌 How to Play
Compile the program using a C++ compiler:
g++ tic_tac_toe.cpp -o tic_tac_toe
./tic_tac_toe
