//============================================================================
// Name        : Checkers.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include "Pieces.cpp"
#include "Board.cpp"

using namespace std;

bool menu(){
	int choice1, choice2, index;
	bool cinError;
	string lineFromFile;
	string array[2074];
	ifstream infile;
	
	infile.open("Instructions1.txt");
	
	index = 0;
	while(!infile.eof()){
		getline(infile, lineFromFile);
		array[index] = lineFromFile;
		index++;
	}
	infile.close();
	
	do{
		cout << '\n' << " 1. Start the game " << endl;
		cout << " 2. Read the Instructions " << endl;
		cout << " 3. Exit the game " << endl;
	
		do{
			cout << '\n' << "Enter your choice:" << endl;
			cin >> choice1;
			cinError = cin.fail();
			if(cinError){
				cin.clear();
				cin.ignore(1000,'\n');
				cout << '\n' << "Invalid Input" << '\n' << endl;
			}
		}while(cinError);
		
		if(choice1 == 1){
			return true;
			break;
		}	
	
		else if(choice1 == 2){
			for(index = 0; index < 40 /*array.size()*/; index++){
				cout << '\n' << array[index] << endl;
			}
			
			cout << endl;
			cout << "Input 1 if you would like to begin the game" << endl;
			cout << "Input 2 if you would like to exit the game" << endl;
			
			do{
				cout << '\n' << "Enter your choice:" << endl;
				cin >> choice2;
				cinError = cin.fail();
				if(cinError){
					cin.clear();
					cin.ignore(1000,'\n');
					cout << '\n' << "Invalid Input" << '\n' << endl;
				}
			}while(cinError);
		
			if(choice2 == 1){
				return true;
				break;
			}
			
			else if(choice2 == 2){
				return false;
				break;
			}
		}
		
		else if(choice1 == 3){
			return false;
		}
		
	}while(choice1 != 3);
}

int main() {
	bool begin;
	
	Board* board = new Board();
	
	board ->populateBoard();
	//While there are pieces left continue the game
	
	begin = menu();
	if(begin){
		while(whitePiecesLeft > 0 && blackPiecesLeft > 0){
		board -> printBoard();
		board -> checkForMoves();
	}
}

/*	int board[8][8];
	*/

	return 0;
}
