


#ifndef PIECE_H_
#define PIECE_H_

#include <string>

using namespace std;

class Piece{

	protected:
		int type;  //The type of piece being used, normal or King
		int move[2];  		//Where the piece is trying to move
		int position[2];					// x and y coordinates of piece are stored in array
		int destination[2];
		bool isWhite;					//black or white piece
		bool dead;					//still in play on board
		int blackScore;
		int whiteScore;
		int countDeadPieces;
		bool firstMoved;
		bool didMove;  //Checks is the piece has already moved

	public:
		Piece(){};
		Piece(int positionX,int positionY, bool isWhite,int type )
		{
			this -> type = type;
			this -> position[0] = positionX;
			this -> position[1] = positionY;
			this -> isWhite = isWhite;


		}
		int* getPosition();
		void setPosition(int x, int y);
		int getX();
		int getY();
		bool getWhite();		//Returns true if piece is white else it's black
		void setWhite(bool isWhite);
		int getDead();		//Returns the number of dead pieces
	 	void setDead();		//Returns true if piece has been destroyed
		int getType(); 	//Returns type of piece normal or King
		void setType(int type);
		virtual bool isMoveLegal(int x, int y, int currentX, int currentY);  //checks where piece is and wants to go, if move is legal return true
		virtual void upgradePiece();
		virtual bool getDidMove();


};
class Normal: public Piece{

	Normal(int positionX, int positionY, bool isWhite, int type):Piece(positionX,positionY,isWhite,type)
	{

	}
	void upgradePiece();
	bool isMoveLegal(int x, int y, int currentX, int currentY);
};

class King: public Piece{

	bool isMoveLegal(int x, int y, int currentX, int currentY);

};

#endif /* PIECE_H_ */
