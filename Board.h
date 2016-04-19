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
	void getDestinationCoordinates(int* destinationX, int* destinationY);	//get coordinates for destination of piece
	void getPieceCoordinates(int* intcurrX, int* intcurrY);	//get coordinates for piece to be moved
	void populateBoard();	//add pieces to board
	void printBoard();	//Print board to terminal
	void movePiece(int currentX, int currentY,int movingToX,int movingToY);	//Moves piece inside of array
	void checkForMoves();	//Takes in desired moves and checks if they are possible
	bool positionExists(int currentX, int currentY,int movingToX,int movingToY);	//Check if position of piece exists
	bool position_Piece_Exist(int x, int y,bool colorPiece);	//more checks for existence of coordinates and piece
	bool checkJump(int currentX, int currentY,int &jumpedPieceX,int &jumpedPieceY1,int &jumpedPieceY2); //checks if a jump is possible
	bool jumpPosition(int possibleX, int possibleY1,int possibleY2,bool &canUseY1,bool &canUseY2,int currentX,int currentY ,bool &kingUp,bool &kingDown);	//Check if coordinates are possible
	void upgradeToKing(int x, int y);	// Transforms normal piece into a King


};




#endif /* PIECES_H_ */
