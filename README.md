# Group-108
This is a text-based **nim** game by group 108 for the project in COMP2113/ENGG1340.

Chow Sheung Lam will be responsible for most of the code in the main programe of the game.

Wong Ka Fai will be responsilbe for  game saving(file I/O), headers and function file and part of the code in main programe.

## What is Nim
Nim is a 2-player game which each player take turns to take a number of nim(s) out of the table. There will be a restraint on the number of nims that player each turn can take, for example each player each turn can only take up to 2 nims , and the player who takes the last nim will lose.

## Fulfilling coding reqirement
1. When each new game is started. the number of nim(s) or the number of rows will be generated randomly.
2. Game status will be stored using a (n + 1) x n dimensional array, for example 
```
[ (who's turn  , no. of nims )  
  (the no. of nims in first row) 
              .
              .
              .
  (the no. of nims in n th row) ]
```
3. By using 'new' and 'delete', it will create a dynamic array in 2) where n will be assigned by random() function.

4. By including fstream, the dynamic array in 3) will be written and read in a new file as game_staus.txt.

5. The whole programe will be divided into multiple files including header files,function files and main programe files.

## How to use these files
1. Download all files in this repository
2. type command: 
```
make main_program
```
3. type:
```
./main_program
```
Then you can play the game!

Although we do not have any input files as the number of nims is randomized and input and output files are not applicable, we have videos demonstrating how to play the game.
 
