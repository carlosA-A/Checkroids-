//============================================================================
// Name        : Checkers.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Pieces.cpp"
#include "Board.cpp"

using namespace std;

int main() {


Board* board = new Board();

board ->populateBoard();
while(true){
board -> printBoard();
board -> checkForMoves();
}



/*	int board[8][8];
	*/

	return 0;
}
