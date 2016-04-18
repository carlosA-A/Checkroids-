#include "Board.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//Adds all the pieces to the board
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
            pieceArray[row][column] = new Normal (pieceExists,row,column,isWhite,0);
          }
          //Spot in the board is empty
          else{
            pieceExists = false;
            pieceArray[row][column] = new Normal (pieceExists,row,column,isWhite,0);

          }
        }
        else{
          if(column % 2 == 0){
            pieceExists = true;
            //Defines a piece as existing, gives it coordinates and sets it to be white
            pieceArray[row][column] = new Normal (pieceExists,row,column,isWhite,0);

          }
          //Spot in the board is empty
          else{
            pieceExists = false;
            pieceArray[row][column] = new Normal (pieceExists,row,column,isWhite,0);

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
            pieceArray[row][column] = new Normal (pieceExists,row,column,isWhite,0);


          }
          else{
            pieceExists = false;
            //Defines a piece as existing, gives it coordinates and sets it to be black
            pieceArray[row][column] = new Normal (pieceExists,row,column,isWhite,0);

          }

        }
        else{

          if (column % 2 == 1) {
            pieceExists = true;
            isWhite = false;
            //Defines a piece as existing, gives it coordinates and sets it to be black
            pieceArray[row][column] = new Normal (pieceExists,row,column,isWhite,0);

          }
          else{
            pieceExists = false;
            //Defines a piece as existing, gives it coordinates and sets it to be black
            pieceArray[row][column] = new Normal (pieceExists,row,column,isWhite,0);


          }
        }

      }
      else{
        pieceExists = false;
        //Defines a piece as existing, gives it coordinates and sets it to be black
        pieceArray[row][column] = new Normal (pieceExists,row,column,isWhite,0);

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
        //Check if piece is king
        if(pieceArray[row][column]->type == 1){

          cout <<  "wK "<<"\t" ;
        }
        else{

          cout <<  "w "<<"\t" ;
        }

      }
      //Prints out all the black pieces
      else if (pieceArray[row][column]->exists == true && pieceArray[row][column]->isWhite == false){

        if(pieceArray[row][column]->type == 1){

          cout << "bK"<<"\t" ;
        }

        else{cout << "b"<<"\t" ;
      }

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
  int jumpedPieceX = 0;
  int jumpedPieceY1 = 0;
  int jumpedPieceY2 = 0;

  getPieceCoordinates(&chosenPieceX,&chosenPieceY);
  //Sets coordinates in terms of array
  chosenPieceX--;
  chosenPieceY--;
  if(position_Piece_Exist(chosenPieceX,chosenPieceY,isWhite)){

    if(checkJump(chosenPieceX,chosenPieceY,jumpedPieceX,jumpedPieceY1,jumpedPieceY2)){

      pieceArray[chosenPieceX][chosenPieceY]->pieceCanJump = true;

    }

    getDestinationCoordinates(&chosenDestinationX,&chosenDestinationY);
    //Sets coordinates in terms of array
    chosenDestinationX--;
    chosenDestinationY--;
    canContinue = positionExists(chosenPieceX,chosenPieceY,chosenDestinationX,chosenDestinationY);
  }
  //If all checks are true we can perform the move
  if(canContinue){
    cout<<"Can continue"<<endl;
    movePiece(chosenPieceX,chosenPieceY,chosenDestinationX,chosenDestinationY);
    //Check if piece jumped another piece during its turn
    if(pieceArray[chosenDestinationX][chosenDestinationY]-> didJump == true){


      cout<<"Piece jumped"<<endl;
      //If piece is black, find possible jumped piece
      if(!isWhite){
        //Check if piece reached other side
        if(chosenDestinationX == 0){

          upgradeToKing(chosenDestinationX,chosenDestinationY);

        }

        int destinationToDestroyX = chosenDestinationX+1; //X destination of piece to be dispossed
        int destinationDestryYL = chosenDestinationY -1; //Y destination of piece to dispose to the left
        int destinationDestryYR = chosenDestinationY + 1;//Y destination of piece to dispose to the right
        cout<<"Works 1"<<endl;

        if(!((destinationToDestroyX<0 || destinationToDestroyX>8)&&(destinationDestryYR<0||destinationDestryYR>8))){
          cout<<"Works 2"<<endl;

          if((destinationToDestroyX == jumpedPieceX)&&(destinationDestryYR == jumpedPieceY1 ) ){
            cout<<"Works 3"<<endl;

            pieceArray[destinationToDestroyX][destinationDestryYR]-> setDead();

            pieceArray[destinationToDestroyX][destinationDestryYR]-> exists = false;

          }

        }
        if(!((destinationToDestroyX<0 || destinationToDestroyX>8) && (destinationDestryYL < 0 || destinationDestryYL > 8))){

          cout<<"Works 4"<<endl;

          if(destinationToDestroyX == jumpedPieceX && destinationDestryYL == jumpedPieceY2){

            cout<<"Works 5"<<endl;

            pieceArray[destinationToDestroyX][destinationDestryYL]-> setDead();

            pieceArray[destinationToDestroyX][destinationDestryYL]-> exists = false;
          }

        }

      }
      //Find piece that white jumped
      else{
        //If white reached other side change to king
        if(chosenDestinationX == 7){

          upgradeToKing(chosenDestinationX,chosenDestinationY);

        }

        int destinationToDestroyX = chosenDestinationX - 1; //X destination of piece to be dispossed

        int destinationDestryYL = chosenDestinationY + 1; //Y destination of piece to dispose to the left

        int destinationDestryYR = chosenDestinationY - 1;//Y destination of piece to dispose to the right

        cout<<"Works 1"<<endl;

        if(!((destinationToDestroyX<0 || destinationToDestroyX>8)&&(destinationDestryYR<0||destinationDestryYR>8))){

          if((destinationToDestroyX == jumpedPieceX)&&(destinationDestryYR == jumpedPieceY1 ) ){

            cout<<"Works 2"<<endl;

            pieceArray[destinationToDestroyX][destinationDestryYR]-> setDead();

            pieceArray[destinationToDestroyX][destinationDestryYR]-> exists = false;

          }
        }
        if(!((destinationToDestroyX<0 || destinationToDestroyX>8) && (destinationDestryYL < 0 || destinationDestryYL > 8))){
          if(destinationToDestroyX == jumpedPieceX && destinationDestryYL == jumpedPieceY2){

            cout<<"Works 3"<<endl;

            pieceArray[destinationToDestroyX][destinationDestryYL]-> setDead();

            pieceArray[destinationToDestroyX][destinationDestryYL]-> exists = false;
          }
        }

      }

    }
    //If move lands on other side of board upgrade To King
    else if(isWhite && chosenDestinationX == 7){

      upgradeToKing(chosenDestinationX,chosenDestinationY);


    }
    else if(!(isWhite) && chosenDestinationX == 0){

      upgradeToKing(chosenDestinationX,chosenDestinationY);


    }
    if(isWhite == false){
      std::cout << "Whites' turn." << std::endl;

      isWhite = true;
    }
    else{
      isWhite = false;
      std::cout << "Blacks' turn." << std::endl;

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
  pieceArray[currentX][currentY] = new Normal (false,currentX,currentY,false,0);

}
//Checks the sorroundings of current piece to see if it is possible for it to jump
bool Board::checkJump(int currentX, int currentY,int &jumpedPieceX,int &jumpedPieceY1,int &jumpedPieceY2){
  int opposingPiece = -1;
  bool canJump = false;
  int jumpX;
  int possibleJumpY1;
  int possibleJumpY2;
  //Temp variables to be replaced
  int tempX;
  int tempY1;
  int tempY2;
  //Check if piece diagonally to the right exists
  if(isWhite){
    std::cout << "Works 199" << std::endl;

    opposingPiece = abs(opposingPiece);

    //Check possible spots where there could be a piece to jump
    jumpX = currentX + opposingPiece;
    //Piece could be to left or right
    possibleJumpY1 = currentY + opposingPiece;
    possibleJumpY2 = currentY - opposingPiece;
    if(jumpPosition(jumpX,possibleJumpY1,possibleJumpY2)==false){

    }
    else{
      std::cout << "Works 1" << std::endl;
      //Checks if there is a piece active and of the opposing color to be jumped
      if((pieceArray[jumpX][possibleJumpY1]->exists == true && pieceArray[jumpX][possibleJumpY1]->isWhite!=isWhite)){
        std::cout << "Works 2" << std::endl;
        //Sets place where the piece that is going to be jumped is
        jumpedPieceX = jumpX;
        jumpedPieceY1 = possibleJumpY1;
        //Check if there is a space available to jump to diagonally to the opposing piece
        tempX =jumpX + opposingPiece;
        //Substracts one and goes left on possible arrival spot after jumping
        tempY1 = possibleJumpY1 + opposingPiece;
        //Check if position at futer spot exists
        if(!((tempX<0 || tempX>8)||(tempY1<0||tempY1>8))){
          std::cout << "Works 3" << std::endl;
          //Check if position we want to jump to is empty
          if(pieceArray[tempX][tempY1]->exists == false){
            std::cout << "Works 4" << std::endl;
            canJump = true;
          }
        }

      }
      if((pieceArray[jumpX][possibleJumpY2]->exists == true && pieceArray[jumpX][possibleJumpY2]->isWhite!=isWhite)){
        std::cout << "Works 5" << std::endl;
        jumpedPieceX = jumpX;

        jumpedPieceY2 = possibleJumpY2;

        tempX = jumpX + opposingPiece;

        tempY2 = possibleJumpY2 - opposingPiece;

        if(!((tempX<0 || tempX>8)||(tempY2<0||tempY2>8))){
          std::cout << "Works 6" << std::endl;
          //Check if position we want to jump to is empty
          if(pieceArray[tempX][tempY2]->exists == false){
            std::cout << "Works 7" << std::endl;
            canJump = true;
          }
        }

      }
    }

  }
  else{
    //Check possible spots where there could be a piece to jump
    cout<<"current X value is: "<<currentX<<endl;
    jumpX = currentX + opposingPiece;
    cout<<"current JumpX value is: "<<jumpX<<endl;
    //Piece could be to left or right
    possibleJumpY1 = currentY + opposingPiece;
    possibleJumpY2 = currentY - opposingPiece;

    std::cout << "Works 8" << std::endl;

    //Check if it's possible for a piece to exist in those coordinates
    if(jumpPosition(jumpX,possibleJumpY1,possibleJumpY2)==false){
      std::cout << "Works 9" << std::endl;


      canJump = false;
    }
    else{
      std::cout << "Works 10" << std::endl;

      //Checks if there is a piece active and of the opposing color to be jumped
      if((pieceArray[jumpX][possibleJumpY1]->exists == true && pieceArray[jumpX][possibleJumpY1]->isWhite!=isWhite) ){
        std::cout << "Works 11" << std::endl;


        jumpedPieceX = jumpX;
        jumpedPieceY1 = possibleJumpY1;
        //Check if there is a space available to jump to diagonally to the opposing piece
        tempX = jumpX + opposingPiece;
        //Substracts one and goes left on possible arrival spot after jumping
        tempY1 = possibleJumpY1 + opposingPiece;

        //Check if position at futer spot exists
        if(!((tempX<0 || tempX>8)||(tempY1<0||tempY1>8))){
          std::cout << "Works 12" << std::endl;
          std::cout << "possible X jump: "<<tempX << std::endl;
          std::cout << "possible Y jump: "<<tempY1 << std::endl;


          //Check if position we want to jump to is empty
          if(pieceArray[tempX][tempY1]->exists == false){
            std::cout << "Works 13" << std::endl;

            canJump = true;
          }

        }

      }
      //Check if there is a piece to the right and if there is check if there is an empty spot to jump to
      if((pieceArray[jumpX][possibleJumpY2]->exists == true && pieceArray[jumpX][possibleJumpY2]->isWhite!=isWhite)){
        std::cout << "Works 14" << std::endl;

        std::cout << "Check for jump" << std::endl;
        std::cout << jumpX << std::endl;
        std::cout << possibleJumpY2 << std::endl;
        jumpedPieceX = jumpX;
        jumpedPieceY2 = possibleJumpY2;
        tempX = jumpX + opposingPiece;
        tempY2 = possibleJumpY2 - opposingPiece;

        if(!((tempX<0 || tempX>8)||(tempY2<0||tempY2>8))){
          std::cout << "Works 15" << std::endl;

          //Check if position we want to jump to is empty
          if(pieceArray[tempX][tempY2]->exists == false){
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
void Board::jump(int possibleX, int possibleY1,int possibleY2){


}

void Board::getPieceCoordinates(int* intcurrX, int* intcurrY){

  string current;
  string currX;
  string currY;
  cout << "Input coordinates of piece to move ex: 1,1" << endl;
  cin >> current;

  for(int i = 0; i < current.size(); i++){
    if(current[i] != ','){
      currX += current[i];
    }
    else{
      for(int j = i+1; j < current.size(); j++){
        currY += current[j];
      }
      break;
    }
  }
  stringstream convert1(currX);
  convert1 >> *intcurrX;

  stringstream convert2(currY);
  convert2 >> *intcurrY;


}
void Board::getDestinationCoordinates(int* destinationX, int* destinationY){
  string target;
  string x;
  string y;
  cout << "Input coordinates for were to go ex: 2,3" << endl;
  cin >> target;

  for(int i = 0; i < target.size(); i++){
    if(target[i] != ','){
      x += target[i];
    }
    else{
      for(int j = i+1; j < target.size(); j++){
        y += target[j];
      }
      break;
    }
  }
  stringstream convert3(x);
  convert3 >> *destinationX;

  stringstream convert4(y);
  convert4 >> *destinationY;

}
void Board::upgradeToKing(int x, int y){
  //creates a new king piece and replaces the normal piece in that position

  pieceArray[x][y] = new King(true,x,y,isWhite,1);


}
