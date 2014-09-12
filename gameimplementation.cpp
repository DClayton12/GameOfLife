/*
 * Author: Darnel Clayon
 * Date: 6/29/2014
 * Course: CS 162
 * Assignment: Assignment 1
 * Filename: gameimplementation.cpp
 * Overview: This file holds function definitions in namespace lifespace.
 */

#include <iostream>
#include "gameinterface.h"
using std::cout;
using std::endl;
using std::cin;

namespace lifespace{

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
 * humans[55][2]=true; //Uncomment to manually place *'s and test boundaries
 * humans[55][3]=true;
 * humans[55][4]=true;
 * */
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
}
