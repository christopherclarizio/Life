//Christopher Clarizio
//Driver program for Conway's game of Life

#include <fstream>
#include <iostream>
#include <string>
#include <unistd.h>
#include "lifeboard.h"
using namespace std;

void add( lifeboard& board, int x, int y ){
	if( board.getState( x, y ) == ' ' ){
		board.setState( x, y );
	}
}
void rmv( lifeboard& board, int x, int y ){
	if( board.getState( x, y ) == 'X' ){
		board.setState( x, y );
	}
}
void tick( lifeboard& board ){
	lifeboard temp = board;
	for( int i = 0; i < 40; i ++ ){
		for( int j = 0; j < 40; j++ ){
			if( board.getState( i, j ) == 'X' ){
				if( board.numAdjLive( i, j ) < 2 ){
					temp.setState( i, j );
				}else if( board.numAdjLive( i, j ) > 3 ){
					temp.setState( i, j );
				}
			}else{
				if( board.numAdjLive( i, j ) == 3 ){
					temp.setState( i, j );
				}
			}
		}
	}
	board = temp;
}
void play( lifeboard& board ){
	while( 1 ){
		tick( board );
		usleep( 300000 );
		board.disp();
	}
}

int main( int argc, char* argv[] ){

	lifeboard board = lifeboard();
	board.disp();

	char choice = 'c';
	string x_s, y_s, line, filename;
	int x, y;

	if( argc == 1 ){

		while( choice != 'q' ){
			cout << "Choose one; a: add a cell, r: remove a cell, n: advance the one generation, p: play continuously, q: quit.\n";
			cin >> choice;
			switch( choice ){
				case 'a':
					cout << "Enter the coordinates of the location (x coordinate followed by y coordinate) to add a live cell: \n";
					cin >> x >> y;
					add( board, x, y );
					break;
				case 'r':
					cout << "Enter the coordinates of the location (x coordiante followed by y coordinate) to remove a live cell: \n";
					cin >> x >> y;
					rmv( board, x, y );
					break;
				case 'n':
					tick( board );
					break;
				case 'p':
					play( board );
					break;
			}
			system("clear");
			board.disp();
		}

	}else{

		filename = argv[1];
		ifstream fs;
		fs.open( filename );

		char c = fs.peek();
		string choice_s;
		while( c != EOF ){
			getline( fs, choice_s, ' ' );
			//cout << "choice_s[0]: " << choice_s[0] << "\n";
			switch ( choice_s[0] ){
				case 'a':
					getline( fs, x_s, ' ' );
					//cout << "x_s: " << x_s << "\n";
					getline( fs, y_s, '\n' );
					//cout << "y_s: " << y_s << "\n";
					x = atoi( x_s.c_str() );
					//cout << "x: " << x << "\n";
					y = atoi( y_s.c_str() );
					//cout << "y: " << y << "\n";
					add( board, x, y );
					c = fs.peek();
					break;
				case 'r':
					getline( fs, x_s, ' ' );
					getline( fs, y_s, '\n' );
					x = atoi( x_s.c_str() );
					y = atoi( y_s.c_str() );
					rmv( board, x, y );
					c = fs.peek();
					break;
				case 'n':
					tick( board );
					c = fs.peek();
					break;
				case 'p':
					play( board );
					c = fs.peek();
					break;
			}
			system("clear");
			board.disp();
		}
	}

}
