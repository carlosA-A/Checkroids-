#include "Board.h"
using namespace std;


void Board::populateBoard(){

  for (int row = 0; row < 8; row++) {
    for (int column = 0; column < 8; column++) {
      //populate upper part of the boaard
      if (row < 3){
        //Add a piece in every even column
        if (row % 2== 0){
          if (column % 2 ==0){
            pieceExists = true;
            isWhite = true;
            //Defines a piece as existing, gives it coordinates and sets it to be white
            pieceArray[row][column] = new Normal (pieceExists,row,column,isWhite);
          }
          //Spot in the board is empty
          else{
            pieceExists = false;
            pieceArray[row][column] = new Normal (pieceExists,row,column,isWhite);

          }
        }
        else{
          if(column % 2 == 1){
            pieceExists = true;
            //Defines a piece as existing, gives it coordinates and sets it to be white
            pieceArray[row][column] = new Normal (pieceExists,row,column,isWhite);

          }
          //Spot in the board is empty
          else{
            pieceExists = false;
            pieceArray[row][column] = new Normal (pieceExists,row,column,isWhite);

          }
        }
      }
      //Populate black side of board
      else if (row > 4){

        if(row % 2 == 1){
          if(column % 2 == 0){
            pieceExists = true;
            isWhite = false;
            //Defines a piece as existing, gives it coordinates and sets it to be black
            pieceArray[row][column] = new Normal (pieceExists,row,column,isWhite);


          }
          else{
            pieceExists = false;
            //Defines a piece as existing, gives it coordinates and sets it to be black
            pieceArray[row][column] = new Normal (pieceExists,row,column,isWhite);

          }

        }
        else{

          if (column % 2 == 1) {
            pieceExists = true;
            isWhite = false;
            //Defines a piece as existing, gives it coordinates and sets it to be black
            pieceArray[row][column] = new Normal (pieceExists,row,column,isWhite);

          }
          else{
            pieceExists = false;
            //Defines a piece as existing, gives it coordinates and sets it to be black
            pieceArray[row][column] = new Normal (pieceExists,row,column,isWhite);


          }
        }

      }
      else{
        pieceExists = false;
        //Defines a piece as existing, gives it coordinates and sets it to be black
        pieceArray[row][column] = new Normal (pieceExists,row,column,isWhite);

      }
    }
  }

}
//Print board if there is a piece
void Board::printBoard(){


  for (int row = 0,columnIndex = 0,rowIndex = 1;  row < 8; ++ row) {

    for (int column = 0; column < 8; ++ column) {

      //Adds numbering for columns
      while(columnIndex<9){
        if(columnIndex==0){
          cout <<  " " <<"\t";
          columnIndex++;
        }
        else{
          cout <<  columnIndex++ <<"\t";
        }

        if (columnIndex == 9) {
          cout <<endl<<endl;
        }
      }
      if(column == 0){

        cout<<rowIndex++<<"\t";
      }
      //Prints out all the white pieces
      if(pieceArray[row][column]->exists == true && pieceArray[row][column]->isWhite == true){

        cout <<  "w "<<"\t" ;
      }
      //Prints out all the black pieces
      else if (pieceArray[row][column]->exists == true && pieceArray[row][column]->isWhite == false){

        cout << "b"<<"\t" ;
      }
      //prints the spaces where movement is allowed
      else{

        cout << "o"<<"\t" ;
      }


      if (column == 7) {

        cout<<endl;
      }
    }
    cout<<endl;


  }

}

void Board::movePiece(){
    int chosenPieceX;
    int chosenPieceY;
    int chosenDestinationX;
    int chosenDestinationY;
    bool canContinue = false;
    isWhite = false;      //Blacks start

    cout<< "Which piece would you like to move?(w White,b Black)"<<endl;
    cout<< "Enter X coodinate"<<endl;
    cin>>chosenPieceX;
    cout<< "Enter Y coodinate"<<endl;
    cin>>chosenPieceY;

    if(position_Piece_Exist(chosenPieceX,chosenPieceY)){
      cout<< "Where would you like to move?(o Empty)"<<endl;
      cout<< "Enter X coodinate"<<endl;
      cin>>chosenDestinationX;
      cout<< "Enter Y coodinate"<<endl;
      cin>>chosenDestinationY;
      canContinue = positionExists(chosenPieceX,chosenPieceY,chosenDestinationX,chosenDestinationY);
    }
	if(canContinue){
		cout<<"Can continue"<<endl;
		}
		else{
			cout<<"Can't continue"<<endl;
			}

}
bool Board::position_Piece_Exist(int x, int y){
  bool posExists = true;

  if((x < 1 || x > 8)&&(y < 1 || y > 8)){

    std::cout << "Position doesn't exist" << std::endl;
    posExists = false;
  }
  else{
    int arrayPosX = x-1;   //-1 to find in array
    int arrayPosY = y-1;
    //Check if at position there exists a piece and is same color as player
    if(pieceArray[arrayPosX][arrayPosY]-> exists == true && pieceArray[arrayPosX][arrayPosY]->isWhite == isWhite){
      
    }
    else{
      posExists = false;
    }

  }


  return posExists;

}
bool Board::positionExists(int currentX, int currentY,int movingToX,int movingToY){
  bool posExists = true;
  //Check if pos exists
  if((movingToX < 1 || movingToX > 8)&&(movingToY < 1 || movingToY > 8)){

    std::cout << "Position doesn't exist" << std::endl;
    posExists = false;
  }
  //Check if piece can move there
  else{
    //Current x y pos
    int arrayPosX = currentX-1;   //-1 to find in array
    int arrayPosY = currentY-1;
    //Position trying to move to
    int moveToX = movingToX -1;
    int MoveToY = movingToY-1;

    if(pieceArray[arrayPosX][arrayPosY]->isMoveLegal(moveToX,MoveToY,arrayPosX,arrayPosY)){

    }
    else{
      posExists = false;
    }
  }


  return posExists;

}
