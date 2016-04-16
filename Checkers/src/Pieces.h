


#ifndef PIECE_H_
#define PIECE_H_

#include <string>

using namespace std;

class Piece{

	protected:

		int position[2];					// x and y coordinates of piece are stored in array
		int destination[2];
		bool white;					//black or white piece
		bool dead;					//still in play on board
		int blackScore;
		int whiteScore;
		int countDeadPieces;
		bool firstMoved;

	public:
		Piece(){};

		int getX();
		int getY();
		bool getWhite();
		bool getDead();
		virtual bool isMoveLegal();



};
class Normal: public Piece{

	bool isMoveLegal();
}

class King: public Piece{

	bool isMoveLegal();

}

#endif /* PIECE_H_ */
