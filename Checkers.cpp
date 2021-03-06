
#include <iostream>
#include <fstream>
#include "Pieces.cpp"
#include "Board.cpp"

using namespace std;

//Create menu for game
bool menu(){
	int choice1, choice2, index;
	bool cinError;
	string lineFromFile;
	string array[2074];
	ifstream infile;

//Read file with game instructions
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
			cout << '\n' << "Enter your choice:";
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
				cout << '\n' << "Enter your choice:" ;
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
	
	return false;
	
}

int main() {
	bool begin;

//create a new board
	Board* board = new Board();

	board ->populateBoard();
	//While there are pieces left continue the game

	begin = menu();
	if(begin){
		while(whitePiecesLeft > 0 && blackPiecesLeft > 0){
		board -> printBoard();
		board -> checkForMoves();
	}
	//Determine winner based on the number of pieces left
	if(whitePiecesLeft == 0 || blackPiecesLeft == 0 ){
		board -> printBoard();

		std::cout << "Game Over" << std::endl;
		if(whitePiecesLeft == 0){

			std::cout << "Black Wins!" << std::endl;
		}
		else if(blackPiecesLeft == 0){

			std::cout << "White Wins!" << std::endl;

		}
	}
}


	return 0;
}
