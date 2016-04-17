#ifndef BOARD_H_
#define BOARD_H_
#include "Pieces.h"
using namespace std;



class Board{
	

Piece* pieceArray[8][8];
bool isWhite;
bool pieceExists;
void populateBoard();
void printBoard();


};

































#endif /* PIECES_H_ */
