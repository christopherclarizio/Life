//Christopher Clarizio
//Header file for the class lifeboard

#include <iostream>
#include <vector>
using namespace std;

class lifeboard{
	public:
		lifeboard();   //default constructor
		~lifeboard();   //destructor
		char getState(int,int);   //returns the state of the choosen cell 
		void setState(int,int);   //flips the state of the choosen cell
		int numAdjLive(int,int);   //returns num of live adjacent cells
		void disp();   //display the board
	private:
		vector< vector<char> > board;   //storage for the board
		//board[0][0] will be top left corner
		//board[0][39] will be bot left corner
		//board[39][0] will be top right corner
		//board[39][39] will be bot right corner
};
