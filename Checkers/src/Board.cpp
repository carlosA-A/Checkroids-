#include "Board.h"
using namespace std;


void Board::populateBoard(){

  for (int row = 0; row < 8; row++) {
    for (int column = 0; column < 8; column++) {
      //populate upper part of the boaard
      if (row < 3){
        //Add a piece in every even column
        if (row % 2== 0){
          if (column % 2 == 1){
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
          if(column % 2 == 0){
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
//Takes in coordinates to move, and if verified as proper moves the pieces to desired location
void Board::checkForMoves(){
  int chosenPieceX;
  int chosenPieceY;
  int chosenDestinationX;
  int chosenDestinationY;
  bool canContinue = false;

  cout<< "Which piece would you like to move?(w White,b Black)"<<endl;
  cout<< "Enter X coodinate"<<endl;
  cin>>chosenPieceX;
  cout<< "Enter Y coodinate"<<endl;
  cin>>chosenPieceY;
  //Sets coordinates in terms of array
  chosenPieceX--;
  chosenPieceY--;
  if(position_Piece_Exist(chosenPieceX,chosenPieceY,isWhite)){
    checkJump(chosenPieceX,chosenPieceY);
    cout<< "Where would you like to move?(o Empty)"<<endl;
    cout<< "Enter X coodinate"<<endl;
    cin>>chosenDestinationX;
    cout<< "Enter Y coodinate"<<endl;
    cin>>chosenDestinationY;
    //Sets coordinates in terms of array
    chosenDestinationX--;
    chosenDestinationY--;
    canContinue = positionExists(chosenPieceX,chosenPieceY,chosenDestinationX,chosenDestinationY);
  }
  //If all checks are true we can perform the move
  if(canContinue){
    cout<<"Can continue"<<endl;
    movePiece(chosenPieceX,chosenPieceY,chosenDestinationX,chosenDestinationY);
    if(isWhite == false){

      isWhite = true;
    }
    else{
      isWhite = false;

    }
  }
  else{
    cout<<"Can't continue"<<endl;
  }

}

//Checks if the coordinates are possible and if there is a piece matching the player
bool Board::position_Piece_Exist(int x, int y,bool colorPiece){
  bool posExists = true;


  if((x < 0 || x > 7)&&(y < 0 || y > 7)){

    std::cout << "Position doesn't exist" << std::endl;
    posExists = false;
  }
  else{
    //Check if at position there exists a piece and is same color as player
    if(pieceArray[x][y]-> exists == true && pieceArray[x][y]->isWhite == colorPiece ){
    }
    else{
      posExists = false;
    }

  }


  return posExists;

}
//Checks if the position the player wants to go to is accesible
bool Board::positionExists(int currentX, int currentY,int movingToX,int movingToY){
  bool posExists = true;
  //Check if pos exists
  if((movingToX < 0 || movingToX > 7)&&(movingToY < 0 || movingToY > 7)){
    std::cout << "Position doesn't exist" << std::endl;
    posExists = false;
  }
  //Check if piece can move there
  else{
    //Checl if the move is legal and that there aren't any pieces in that same spot
    if(pieceArray[currentX][currentY]->isMoveLegal(movingToX,movingToY,currentX,currentY)&&(pieceArray[movingToX][movingToY]->exists ==false)){

    }
    else{
      posExists = false;
    }
  }


  return posExists;

}


void Board::movePiece(int currentX, int currentY,int movingToX,int movingToY){

  pieceArray[movingToX][movingToY] = pieceArray[currentX][currentY];
  pieceArray[currentX][currentY] = new Normal (false,currentX,currentY,false);

}
//Checks the sorroundings of current piece to see if it is possible for it to jump
bool Board::checkJump(int currentX, int currentY){
  int opposingPiece = -1;
  bool canJump = false;
  int jumpX;
  int possibleJumpY1;
  int possibleJumpY2;
  //Check if piece diagonally to the right exists
  if(isWhite){
    opposingPiece = abs(opposingPiece);

    //Check possible spots where there could be a piece to jump
    jumpX = currentX + opposingPiece;
    //Piece could be to left or right
    possibleJumpY1 = currentY + opposingPiece;
    possibleJumpY2 = currentY - opposingPiece;
    if(jumpPosition(jumpX,possibleJumpY1,possibleJumpY2)==false){

    }
    else{

      //Checks if there is a piece active and of the opposing color to be jumped
      if((pieceArray[jumpX][possibleJumpY1]->exists == true && pieceArray[jumpX][possibleJumpY1]->isWhite!=isWhite)){
        //Check if there is a space available to jump to diagonally to the opposing piece
        jumpX = jumpX + opposingPiece;
        //Substracts one and goes left on possible arrival spot after jumping
        possibleJumpY1 = possibleJumpY1 + opposingPiece;
        //Check if position at futer spot exists
        if(!((jumpX<0 || jumpX>8)||(possibleJumpY1<0||possibleJumpY1>8))){
            //Check if position we want to jump to is empty
            if(pieceArray[jumpX][possibleJumpY1]->exists == false){
              canJump = true;
            }
        }

      }
      else if((pieceArray[jumpX][possibleJumpY2]->exists == true && pieceArray[jumpX][possibleJumpY2]->isWhite!=isWhite)){
        jumpX = jumpX + opposingPiece;
        possibleJumpY2 = possibleJumpY2 - opposingPiece;
        if(!((jumpX<0 || jumpX>8)||(possibleJumpY2<0||possibleJumpY2>8))){
            //Check if position we want to jump to is empty
            if(pieceArray[jumpX][possibleJumpY2]->exists == false){
              canJump = true;
            }
        }

      }
    }

  }
  else{
    //Check possible spots where there could be a piece to jump
    jumpX = currentX + opposingPiece;
    //Piece could be to left or right
    possibleJumpY1 = currentY + opposingPiece;
    possibleJumpY2 = currentY - opposingPiece;

    //Check if it's possible for a piece to exist in those coordinates
    if(jumpPosition(jumpX,possibleJumpY1,possibleJumpY2)==false){

      canJump = false;
    }
    else{
      //Checks if there is a piece active and of the opposing color to be jumped
      if((pieceArray[jumpX][possibleJumpY1]->exists == true && pieceArray[jumpX][possibleJumpY1]->isWhite!=isWhite) ){
          //Check if there is a space available to jump to diagonally to the opposing piece
          jumpX = jumpX + opposingPiece;
          //Substracts one and goes left on possible arrival spot after jumping
          possibleJumpY1 = possibleJumpY1 + opposingPiece;
          //Check if position at futer spot exists
          if(!((jumpX<0 || jumpX>8)||(possibleJumpY1<0||possibleJumpY1>8))){
              //Check if position we want to jump to is empty
              if(pieceArray[jumpX][possibleJumpY1]->exists == false){
                canJump = true;
              }
          }

      }
      //Check if there is a piece to the right and if there is check if there is an empty spot to jump to
      else if((pieceArray[jumpX][possibleJumpY2]->exists == true && pieceArray[jumpX][possibleJumpY2]->isWhite!=isWhite)){
          jumpX = jumpX + opposingPiece;
          possibleJumpY2 = possibleJumpY2 - opposingPiece;
          if(!((jumpX<0 || jumpX>8)||(possibleJumpY2<0||possibleJumpY2>8))){
              //Check if position we want to jump to is empty
              if(pieceArray[jumpX][possibleJumpY2]->exists == false){
                canJump = true;
              }
          }


      }

    }
  }


cout<<"Can jump = "<<canJump<<endl;
return canJump;


}
bool Board::jumpPosition(int possibleX, int possibleY1,int possibleY2){
  bool canExist = false;
  if((possibleX<0 || possibleX>8)||(possibleY1<0||possibleY1>8)||(possibleY2 < 0 || possibleY2 > 8)){

  }
  else{
    canExist = true;
  }

  return canExist;
}
