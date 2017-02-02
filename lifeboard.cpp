//Christopher Clarizio
//Class implementation for lifeboard.cpp

#include <iostream>
#include <stdlib.h>
#include <vector>
#include "lifeboard.h"
using namespace std;

//default constructor; sets all cells to dead
lifeboard::lifeboard(){
	vector<char> temp;
	for( int i = 0; i < 40; i++ ){
		for( int j = 0; j < 40; j++ ){
			temp.push_back(' ');
		}
		board.push_back( temp );
	}
}

//destructor; does nothing
lifeboard::~lifeboard(){}

//Getter and Setter for the state of input cell
char lifeboard::getState( int x, int y ){ return board[x][y]; }
void lifeboard::setState( int x, int y ){ board[x][y] == ' ' ? board[x][y] = 'X' : board[x][y] = ' '; }

//Utilities
int lifeboard::numAdjLive( int x, int y ){
	int numAdjLive = 0;   //counter variable; stores the number of live adjacent cells
	for( int i = -1; i <= 1; i++ ){   //iterates through all the cells surrounding board[x][y]
		for( int j = -1; j <= 1; j++ ){
			if( ( i != 0 ) || ( j != 0 ) ){   //skips checking board[x][y] itself
				if( ( x + i >= 0 ) && ( x + i <= 39 ) && ( y + j >= 0 ) && ( y + j <=39 ) ){   //ensures that the adjacent cells are inbounds
					board[x+i][y+j] == 'X' ? numAdjLive++: numAdjLive += 0;   //if the cell contains 'X' a.k.a. is alive increments	the	counter 1
				}
			}
		}
	}
	return numAdjLive;
}
void lifeboard::disp(){
	system("clear");   //clears the screen

	//prints a header: "----------------------------"
	for( int h = 0; h < 44; h++ ){
		cout << "-";
	}
	cout << "\n";

	//prints the cells
	for( int y = 0; y < 40; y++ ){
		cout << "| ";
		for( int x = 0; x < 40; x++ ){
			cout << board[x][y];
//			cout << 'X';
		}
		cout << " |\n";
	}

	//prints a footer: "-------------------------"
	for( int f = 0; f < 44; f++ ){
		cout << "-";
	}
	cout << "\n";

}

