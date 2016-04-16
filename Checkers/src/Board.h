#ifndef BOARD_H
#define BOARD_H

using namespace std;

bool boardArray[8][8];



class Board{
	
	friend class Pieces; 
	
	public:
		Board(){};
		Pieces* pieceArray[24];
		
		void setUpBoard();
}




#endif 