/*
 * Author: Darnel Clayon
 * Date: 6/29/2014
 * Course: CS 162
 * Assignment: Assignment 1
 * Filename: gameinterface.h
 * Overview: This file holds function declarations in a namespace.
 */

#ifndef F_H
#define F_H


namespace lifespace{
const int col=80,row=22;//Static values of columns and rows.
bool humans[col+1][row+1],temp[col+1][row+1];//Declare arrays with an additonal cell to keep values in bounds.
char alive='*',dead=' ';
void display(bool humans[col+1][row+1]);//Print current generation of cells on the board.
void optionCheck(int &x);//Catches and handles exceptions that user input is not numerical. Loop till input is satisfactory.
void startgame1(bool humans[col+1][row+1]);//Sets live cells on the board based on seed of computer's time.
void startgame2(bool humans[col+1][row+1]);//Manually set acorn shape on the board.
void startgame3(bool humans[col+1][row+1]);//Sets pattern of (***) on the board with loops.
void startgame4(bool humans[col+1][row+1]);//Manually sets queenbee shape on the board.
void startgame5(bool humans[col+1][row+1]);//Manually sets boat and loaf shapes on the board.
void menuCheck(int &x);//Evaluate and validate user input is numerical and 1-4. Loops till input is numerical.
void menu();//Switch statement and calls to functions to initiate the starting point of the game.
void generation(bool humans[col+1][row+1],bool temp[col+1][row+1]);//Reassign values based on rule evaluations.
}
#endif
