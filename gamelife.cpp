/*
 * Author: Darnel Clayon
 * Date: 6/29/2014
 * Course: CS 162
 * Assignment: Assignment 1
 * Filename: gamelife.cpp
 * Overview: This program is my attempt to emulate John Conway's Game of Life.
 */

#include <iostream>
#include <cstdlib>
#include "gameinterface.h"

using std::cin;
using std::cout;
using std::endl;
/*
//using namespace lifespace;
using lifespace::display;
using lifespace::optionCheck;
using lifespace::startgame1;
using lifespace::startgame2;
using lifespace::startgame3;
using lifespace::startgame4;
using lifespace::startgame5;
using lifespace::menuCheck;
*/
using lifespace::menu;
using lifespace::generation;
using lifespace::row;
using lifespace::col;
using lifespace::display;
using lifespace::humans;
using lifespace::temp;
//using lifespace::alive;
//using lifespace::dead;

//const int col=80,row=22;//Static values of columns and rows.
//bool humans[col+1][row+1],temp[col+1][row+1];//Declare arrays with an additonal cell to keep values in bounds.
//char alive='*',dead=' ';
/*
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
*/
int main(){
bool humans[col+1][row+1],temp[col+1][row+1];
cout<<"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*\n"
"\t\tWelcome to the Game of Life!\n"
"\n"
"Rules implemented:\n"
"-Each * represents a living cell.\n"
"-If an occupied cell has zero or one neighbor, it dies of loneliness.\n"
"-If an occupied cell has more than three neighbors, it dies of overcrowding.\n"
"-If an empty cell has exactly three occupied neighbor cells,\n"
"there is a birth of a new cell to replace the empty cell.\n"
"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*\n";

menu();
display(humans);
int nIterations=0;
char repeat='n';
do{
generation(humans,temp);
display(humans);
cout<<"*~*~*~*~*  ["<<++nIterations<<"]LIFE CYCLE(S) COMPLETE!  *~*~*~*~*\n"
"*~*~*~*~*  SELECT [Y] THEN PRESS [ENTER] TO RUN ANOTHER CYCLE OF LIFE!!  *~*~*~*~*\n"
"*~*~*~*~*  TO ABORT SELECT ANY OTHER KEY THEN PRESS [ENTER]  *~*~*~*~*\n";
cin>>repeat;
}while(repeat=='y'||repeat=='Y');

cout<<"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*\n"
"*~*~*~*~*  ["<<nIterations<<"]LIFE CYCLE(S) COMPLETE!  *~*~*~*~*\n"
"*~*~*~*~*  GAME OVER! THANK YOU FOR PLAYING AND ENJOY YOUR DAY!!  *~*~*~*~*\n";
return 0;}
/*
void display(bool humans[col+1][row+1]){
for(int i=5;i<col-4;i++){		
        for(int z=3;z<row-2;z++){  
                cout<<"  ";
	if(humans[i][z]==true){cout<<alive;}
	if(humans[i][z]==false){cout<<dead;}
	}
	cout<<endl;	
}
return;}

void startgame1(bool humans[col+1][row+1]){//Randomly places cells to living based on pc's time seed.
int autoSelect=0;
srand(time(0));
for(int i=0;i<col;i++){
        for(int z=0;z<row;z++){
        autoSelect=rand()%2;
	if(autoSelect==0){humans[i][z]=false;}
	if(autoSelect==1){humans[i][z]=true;}        
        }
	}
return;}

void startgame2(bool humans[col+1][row+1]){//Manually setting acorn shape. 
humans[56][9]=true;
humans[57][11]=true;
humans[58][8]=true;
humans[58][9]=true;
humans[58][12]=true;
humans[58][13]=true;
humans[58][14]=true; 
return;}

void startgame3(bool humans[col+1][row+1]){//With loops sets pattern of strip oscillators on the board.

for(int i=5;i<col-4;i+=7){
	for(int z=5;z<row-4;z+=5){
	humans[i][z]=true;
	humans[i][z+1]=true;
	humans[i][z+2]=true;
	}
}

/*
humans[55][2]=true; //Uncomment to manually place *'s and test boundaries
humans[55][3]=true;
humans[55][4]=true;
//
return;}

void startgame4(bool humans[col+1][row+1]){//Manually placing queenbee shape.
humans[56][9]=true;
humans[56][10]=true;
humans[57][11]=true;
humans[58][12]=true;
humans[59][12]=true;
humans[60][12]=true;
humans[61][11]=true;
humans[62][10]=true;
humans[62][9]=true;
return;}

void startgame5(bool humans[col+1][row+1]){//Manually placing boat and loaf shapes.
humans[46][10]=true;
humans[46][11]=true;
humans[47][10]=true;
humans[47][13]=true;
humans[48][11]=true;

humans[37][10]=true;
humans[36][11]=true;
humans[37][9]=true;
humans[37][12]=true;
humans[38][10]=true;
humans[38][12]=true;
humans[39][11]=true;
return;}
void generation(bool humans[col+1][row+1],bool temp[col+1][row+1]){
for(int c=0;c<col;c++){
	for(int h=0;h<row;h++){
	temp[c][h]=humans[c][h];}//Transfering current game info to temp array.
	}
for(int i=1;i<col;i++){
	for(int z=1;z<row;z++){
	int count=0;

	if(temp[i-1][z-1]==true){count++;}//Above and diag left
        if(temp[i-1][z]==true){count++;}  //Above
        if(temp[i-1][z+1]==true){count++;}//Above and diag right
        if(temp[i][z-1]==true){count++;}  //Left
        if(temp[i][z+1]==true){count++;}  //Right
        if(temp[i+1][z-1]==true){count++;}//Below and diag left
        if(temp[i+1][z]==true){count++;}  //Below
        if(temp[i+1][z+1]==true){count++;}//Below and diag right
       
	if(count<2){humans[i][z]=false;} //Lonely and dies 
        if(count==3){humans[i][z]=true;} //Exactly 3 -> birth
        if(count>3){humans[i][z]=false;} //Overcrowded and dies.
	}
}
}
void menu(){
cout<<"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*\n"
"\t\tHow would like to begin the Game of life?\n"
"\n"
"Select [1] to begin random placement of live cells(*).\n"
"Select [2] to begin with Acorn shape.\n"
"Select [3] to begin with a mixture of stripe shaped oscillators (***).\n"
"Select [4] to begin with Queen Bee  shape.\n"
"Select [5] to begin with Boat and Loaf shapes.\n"
"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*\n";
int userOption=0;
cin>>userOption;
menuCheck(userOption);
switch(userOption) {
            case 1:
                startgame1(humans);
                break;
            case 2:
                startgame2(humans);
                break;
	    case 3:
		startgame3(humans);
		break;
	    case 4:
		startgame4(humans);
		break;
	    case 5:
		startgame5(humans);
		break;}
return;}

void menuCheck(int &x){
while(cin.fail())//Check that input in numerical. Will loop till input is satisfactory.
        {
        cin.fail();
        cout<<"ERROR: Selection must be numerical.\n";//Alert user.
        cin.clear();//Clear stream.
        cin.ignore(9999,'\n');
        cout<<"User, please reenter your selection."<<endl;
        cin>>x;//Re-enter input.
        }
	while(x<1||x>5){
	cin.fail();
        cout<<"ERROR: Selection must be [1],[2],[3],[4], OR [5].\n";//Alert user.
        cin.clear();//Clear stream.
        cin.ignore(9999,'\n');
        cout<<"User, please reenter your selection [1],[2],[3],[4], OR [5]."<<endl;
        cin>>x;//Re-enter input.
        }
return;} 
void optionCheck(int &x){
        while(cin.fail())//Check that input in numerical. Will loop till input is satisfactory.
        {
        cin.fail();
        cout<<"ERROR: Selection must be numerical.\n";//Alert user.
        cin.clear();//Clear stream.
        cin.ignore(9999,'\n');
        cout<<"User, please reenter your selection."<<endl;
        cin>>x;//Re-enter input.
        }
return;}
*/
