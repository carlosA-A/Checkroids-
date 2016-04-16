//============================================================================
// Name        : Checkers.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Pieces.cpp"

using namespace std;

int main() {

	int board[8][8];
	for (int spot = 0;  spot < 8; ++ spot) {
			for (int cell = 0; cell < 8; ++ cell) {
				board[spot][cell] = 0;
			}

		}

	for (int spot = 0;  spot < 8; ++ spot) {
		for (int cell = 0; cell < 8; ++ cell) {
			cout <<  board[spot][cell]<<'\t';
			if (cell ==7) {

				cout<<endl;
			}
		}
		cout<<endl;


	}
	return 0;
}
