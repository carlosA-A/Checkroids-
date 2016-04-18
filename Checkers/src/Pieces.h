
#ifndef PIECES_H_
#define PIECES_H_

#include <string>

using namespace std;
//there are 12 white and 12 black pieces, the count is reduced after a
//piece dies and game ends when one reaches 0
int whitePiecesLeft = 12;
int blackPiecesLeft = 12;

class Piece{
	public:
	
	
	friend class Board;


	int move[2];  		//Where the piece is trying to move
	int position[2];	// x and y coordinates of piece are stored in array
	int destination[2];
	bool isWhite;		//black or white piece
	bool dead;		//still in play on board
	int blackScore;
	int whiteScore;
	int countDeadPieces;
	bool isLegal;
	bool firstMoved;
	bool didMove;  		//Checks if the piece has already moved
	bool exists;
	bool didJump;
	bool pieceCanJump;
	int type;		//Type 0 is normal, type 1 is King

	Piece(){};
	Piece(bool exists,int positionX,int positionY, bool isWhite, int type)
	{
		this -> position[0] = positionX;
		this -> position[1] = positionY;
		this -> isWhite = isWhite;
		this -> exists = exists;
		this -> type = type;


	}
	int* getPosition();
	void setPosition(int x, int y);
	int getX();
	int getY();
	bool getWhite();	//Returns true if piece is white else it's black
	void setWhite(bool isWhite);
	int getDead();		//Returns the number of dead pieces
 	void setDead();		//Returns true if piece has been destroyed
	virtual bool isMoveLegal(int x, int y, int currentX, int currentY){return isLegal;};  //checks where piece is and wants to go, if move is legal return true

	bool getDidMove();
};

class Normal: public Piece{
	public:


	Normal(bool exists,int positionX, int positionY, bool isWhite,int type):Piece(exists,positionX,positionY,isWhite,type)
	{

	}
	bool isMoveLegal(int x, int y, int currentX, int currentY);
};

class King: public Piece{
	public:


	King(bool exists,int positionX, int positionY, bool isWhite,int type):Piece(exists,positionX,positionY,isWhite,type)
	{

	}

	bool isMoveLegal(int x, int y, int currentX, int currentY);
};

#endif /* PIECES_H_ */
