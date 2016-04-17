
#ifndef PIECES_H_
#define PIECES_H_

#include <string>

using namespace std;

class Piece{

	protected:
		
		int move[2];  		//Where the piece is trying to move
		int position[2];					// x and y coordinates of piece are stored in array
		int destination[2];
		bool isWhite;					//black or white piece
		bool dead;					//still in play on board
		int blackScore;
		int whiteScore;
		int countDeadPieces;
		bool isLegal;
		bool firstMoved;
		bool didMove;  //Checks is the piece has already moved


	public:
		bool exists;
		
		Piece(){};
		Piece(bool exists,int positionX,int positionY, bool isWhite)
		{
			this -> position[0] = positionX;
			this -> position[1] = positionY;
			this -> isWhite = isWhite;
			this -> exists = exists;
	

		}
		int* getPosition();
		void setPosition(int x, int y);
		int getX();
		int getY();
		bool getWhite();		//Returns true if piece is white else it's black
		void setWhite(bool isWhite);
		int getDead();		//Returns the number of dead pieces
	 	void setDead();		//Returns true if piece has been destroyed
		virtual bool isMoveLegal(int x, int y, int currentX, int currentY){return isLegal;};  //checks where piece is and wants to go, if move is legal return true
		
		bool getDidMove();


};
class Normal: public Piece{

public:
	
	

	
	Normal(bool exists,int positionX, int positionY, bool 
	isWhite):Piece(exists,positionX,positionY,isWhite)
	{
		
	}
	bool isMoveLegal(int x, int y, int currentX, int currentY);
};

class King: public Piece{

	bool isMoveLegal(int x, int y, int currentX, int currentY);

};

#endif /* PIECES_H_ */
