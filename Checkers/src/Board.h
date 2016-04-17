#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string> 
using namespace std;

bool blackTurn = true;


class Board{
	friend class Piece; 
	
	public:
		Board(){};
		Piece* pieceArray[8][8];
		
		void setUpBoard(Piece* pieceArray[][8]);
		void printBoard(Piece* pieceArray[][8]);
		void turn(Piece* pieceArray[][8]);
		void updateBoard(Piece* pieceArray[][8], int currentX, int currentY, int x, int y);
};




#endif 