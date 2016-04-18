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
		void getDestinationCoordinates(int* destinationX, int* destinationY);
	void getPieceCoordinates(int* intcurrX, int* intcurrY);
	void populateBoard();
	void printBoard();
	void movePiece(int currentX, int currentY,int movingToX,int movingToY);	//Moves piece inside of array
	void checkForMoves();	//Takes in desired moves and checks if they are possible
	bool positionExists(int currentX, int currentY,int movingToX,int movingToY);
	bool position_Piece_Exist(int x, int y,bool colorPiece);
	bool checkJump(int currentX, int currentY,int &jumpedPieceX,int &jumpedPieceY1,int &jumpedPieceY2);
	bool jumpPosition(int possibleX, int possibleY1,int possibleY2);	//Check if coordinates are possible
	void jump(int possibleX, int possibleY1,int possibleY2 );			//Checks for possible coordinates of jumped piece

};













#endif /* PIECES_H_ */
