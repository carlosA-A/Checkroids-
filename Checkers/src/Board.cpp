#include "Pieces.cpp"
#include "Board.h"

void Board::setUpBoard(pieceArray[][8]){
	int count = 0;
	
	for(int i = 0; i < 8; i++){ //Sets up the board for beginning of game
		for(int j = 0; j < 8; j++){
			if(count == 0){
				if((j%2) == 1){
					pieceArray[i][j] = new Normal(true, j, i, true);
				}
				else{
					pieceArray[i][j] = new Normal(false, j, i, false);
				}
			}
			
			else if(count == 1){
				if((j%2) == 0){
					pieceArray[i][j] = new Normal(true, j, i, true);
				}
				else{
					pieceArray[i][j] = new Normal(false, j, i, false);
				}
			}
			
			else if(count == 2){
				if((j%2) == 1){
					pieceArray[i][j] = new Normal(true, j, i, true);
				}
				else{
					pieceArray[i][j] = new Normal(false, j, i, false);
				}
			}
			
			else if(count == 3 || count == 4){
				pieceArray[i][j] = new Normal(false, j, i, false);
			}
			
			else if(count == 5){
				if((j%2) == 0){
					pieceArray[i][j] = new Normal(true, j, i, false);
				}
				else{
					pieceArray[i][j] = new Normal(false, j, i, false);
				}
			}
			
			else if(count == 6){
				if((j%2) == 1){
					pieceArray[i][j] = new Normal(true, j, i, false);
				}
				else{
					pieceArray[i][j] = new Normal(false, j, i, false);
				}
			}
			
			else{
				if((j%2) == 0){
					pieceArray[i][j] = new Normal(true, j, i, false);
				}
				else{
					pieceArray[i][j] = new Normal(false, j, i, false);
				}
			}
		}
		count++;
	}
}

void Board::printBoard(pieceArray[][8]){
	cout << '\t' << " 0   " << "1   " << "2   " << "3   " << "4   " << "5   " << "6   " << "7" << endl;
	
	for(int i = 0; i < 8; i++){
		cout << i << '\t';
		for(int j = 0; j < 8; j++){
			if((pieceArray[i][j]->exists) && (pieceArray[i][j]->isWhite)){
				cout << "[X] ";
			}
			
			else if((pieceArray[i][j]->exists) && !(pieceArray[i][j]->isWhite)){
				cout << "[O] ";
			}
			
			else{
				cout << "[ ] ";
			}
		}
		cout << endl;
	}
}

void updateBoard(pieceArray[][8], int currentX, int currentY, int x, int y){
	if(y != 7 && y != 0){
		if(pieceArray[currentX][currentY]->isWhite){
			pieceArray[x][y] = new Normal(true, x, y, true);
		}
		
		else{
			pieceArray[x][y] = new Normal(true, x, y, false)
		}
	}
	
	else{
		//pieceArray[x][y] = new King(true, x, y, true) King should have constructor 
	}
}

void turn(pieceArray[][8]){
	bool legal
	string current;
	string target;
	int currentX, currentY, x, y;
	
	cout << "Please type in the coordinate of piece that you would like to move:" << endl;
	cin >> current; //be sure to type in correctly 
	currentX = current[0];
	currentY = current[1];
	
	cout << "Please type in the coordinate of square where you would like to move:" << endl;
	cin >> target;
	x = target[0];
	y = target[1];
	
	//if() will be used in case user input is incorrect
	
	legal = pieceArray[currentX,currentY]->isMoveLegal(x, y, currentX, currentY);
	if(legal){ 
		if(!(pieceArray[x][y]->exists) && blackTurn){
			//update board
		}
		
		else if(!(pieceArray[x][y]->exists) && !blackTurn){
			//update board
		}
		
		blackTurn = !blackTurn;
	}
}