#ifndef BOARD_H_
#define BOARD_H_
#include "Pieces.h"
using namespace std;



class Board{
public:
	friend class Piece;

  Piece* pieceArray[8][8];
  bool isWhite;	//Tracks players turn, blacks start
  bool pieceExists;   //Checks if piece in spot exists exists

  Board(){
	  //Blacks starts
	  isWhite = false;

	  }
	void populateBoard();
	void printBoard();
	void movePiece(int currentX, int currentY,int movingToX,int movingToY);	//Moves piece inside of array
	void checkForMoves();	//Takes in desired moves and checks if they are possible
	bool positionExists(int currentX, int currentY,int movingToX,int movingToY);
	bool position_Piece_Exist(int x, int y,bool colorPiece);
	bool checkJump(int currentX, int currentY);
	bool jumpPosition(int possibleX, int possibleY1,int possibleY2);


};













#endif /* PIECES_H_ */
