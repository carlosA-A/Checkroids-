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

          cout <<  "WK "<<"\t" ;
        }
        else{

          cout <<  "W"<<"\t" ;
        }

      }
      //Prints out all the black pieces
      else if (pieceArray[row][column]->exists == true && pieceArray[row][column]->isWhite == false){

        if(pieceArray[row][column]->type == 1){

          cout << "\033[30;1mBK\033[0m"<<"\t" ;
        }

        else{cout << "\033[30;1mB\033[0m"<<"\t" ;
      }

    }
    //prints the spaces where movement is allowed
    else{

      cout << "\033[1;31m_\033[0m"<<"\t" ;
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
  bool keepJumping = false;

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
    movePiece(chosenPieceX,chosenPieceY,chosenDestinationX,chosenDestinationY);
    //Check if piece jumped another piece during its turn
    if(pieceArray[chosenDestinationX][chosenDestinationY]-> didJump == true){


      //If piece is black, find possible jumped piece
      if(!isWhite || pieceArray[chosenDestinationX][chosenDestinationY]->type ==1){

        //Check if piece reached other side
        if(chosenDestinationX == 0 && pieceArray[chosenDestinationX][chosenDestinationY]->type !=1 ){
          std::cout << "Upgrade to King" << std::endl;

          upgradeToKing(chosenDestinationX,chosenDestinationY);

        }

        int destinationToDestroyX = chosenDestinationX + 1; //X destination of piece to be dispossed

        int destinationDestryYL = chosenDestinationY -1; //Y destination of piece to dispose to the left

        int destinationDestryYR = chosenDestinationY + 1;//Y destination of piece to dispose to the right

        int destinationToDestroyX2 = chosenPieceX - 1;

        int destinationDestryYL2 = chosenPieceY - 1;

        int destinationDestryYR2 = chosenPieceY + 1;






        if(!((destinationToDestroyX<0 || destinationToDestroyX>7)&&(destinationToDestroyX2<0 || destinationToDestroyX2>7) &&
        (destinationDestryYR<0||destinationDestryYR>7) && (destinationDestryYL2<0||destinationDestryYL2>7))){

          if((destinationToDestroyX == destinationToDestroyX2)&&(destinationDestryYR == destinationDestryYL2 ) ){
            if(pieceArray[destinationToDestroyX][destinationDestryYR]-> exists == true && pieceArray[destinationToDestroyX][destinationDestryYR]->isWhite != isWhite ){
              pieceArray[destinationToDestroyX][destinationDestryYR]-> setDead();

              pieceArray[destinationToDestroyX][destinationDestryYR]-> exists = false;
            }

          }

        }
        if(!((destinationToDestroyX<0 || destinationToDestroyX>7)&&(destinationToDestroyX2<0 || destinationToDestroyX2>7) &&
        (destinationDestryYL<0||destinationDestryYL>7) && (destinationDestryYR2<0||destinationDestryYR2>7))){


          if(destinationToDestroyX == destinationToDestroyX2 && destinationDestryYL == destinationDestryYR2){


            if(pieceArray[destinationToDestroyX][destinationDestryYL]-> exists == true && pieceArray[destinationToDestroyX][destinationDestryYL]->isWhite != isWhite){


              pieceArray[destinationToDestroyX][destinationDestryYL]-> setDead();

              pieceArray[destinationToDestroyX][destinationDestryYL]-> exists = false;

            }


          }

        }
        //Check for another jump here
        keepJumping = checkJump(chosenDestinationX,chosenDestinationY,jumpedPieceX,jumpedPieceY1,jumpedPieceY2);


      }
      //Find piece that white jumped
      if (isWhite || pieceArray[chosenDestinationX][chosenDestinationY]->type ==1){

        //If white reached other side change to king
        if(chosenDestinationX == 7 && pieceArray[chosenDestinationX][chosenDestinationY]->type !=1){
          std::cout << "Upgrade to King" << std::endl;


          upgradeToKing(chosenDestinationX,chosenDestinationY);

        }
        //Compare coordinates from place we left and place we arrived to find what we jumped
        int destinationToDestroyX = chosenDestinationX - 1; //X destination of piece to be dispossed

        int destinationDestryYR = chosenDestinationY + 1; //Y destination of piece to dispose to the right

        int destinationDestryYL = chosenDestinationY - 1;//Y destination of piece to dispose to the left

        int destinationToDestroyX2 = chosenPieceX + 1;

        int destinationDestryYL2 = chosenPieceY - 1;

        int destinationDestryYR2 = chosenPieceY + 1;



        if(!((destinationToDestroyX<0 || destinationToDestroyX>7)&&(destinationToDestroyX2<0 || destinationToDestroyX2>7) &&
        (destinationDestryYR<0||destinationDestryYR>7) && (destinationDestryYL2<0||destinationDestryYL2>7))){

          if((destinationToDestroyX == destinationToDestroyX2)&&(destinationDestryYR == destinationDestryYL2 ) ){

            //Check that there exists a piece and that it's of the oppossing type
            if(pieceArray[destinationToDestroyX][destinationDestryYR]-> exists == true && pieceArray[destinationToDestroyX][destinationDestryYR]->isWhite != isWhite){


              pieceArray[destinationToDestroyX][destinationDestryYR]-> setDead();

              pieceArray[destinationToDestroyX][destinationDestryYR]-> exists = false;

            }
          }
        }
        //Check spot actually exists in Board

        if(!((destinationToDestroyX<0 || destinationToDestroyX>7)&&(destinationToDestroyX2<0 || destinationToDestroyX2>7) &&
        (destinationDestryYL<0||destinationDestryYL>7) && (destinationDestryYR2<0||destinationDestryYR2>7))){


          //If the destination of the piece jumped is found remove it
          if(destinationToDestroyX == destinationToDestroyX2 && destinationDestryYL == destinationDestryYR2){

            if(pieceArray[destinationToDestroyX][destinationDestryYL]-> exists == true && pieceArray[destinationToDestroyX][destinationDestryYL]->isWhite != isWhite){

              pieceArray[destinationToDestroyX][destinationDestryYL]-> setDead();

              pieceArray[destinationToDestroyX][destinationDestryYL]-> exists = false;
            }
          }
        }

        /////////Check for another jump here
        keepJumping = checkJump(chosenDestinationX,chosenDestinationY,jumpedPieceX,jumpedPieceY1,jumpedPieceY2);

      }

    }
    //If move lands on other side of board upgrade To King
    else if(isWhite && chosenDestinationX == 7 && pieceArray[chosenDestinationX][chosenDestinationY]->type !=1){

      upgradeToKing(chosenDestinationX,chosenDestinationY);


    }
    else if(!(isWhite) && chosenDestinationX == 0 && pieceArray[chosenDestinationX][chosenDestinationY]->type !=1){

      upgradeToKing(chosenDestinationX,chosenDestinationY);


    }
    //If piece can keep jumping don't switch turns

    if(keepJumping == false){
      if(isWhite == false){
        std::cout << "Whites' turn." << std::endl;

        isWhite = true;
      }
      else{
        isWhite = false;
        std::cout << "Blacks' turn." << std::endl;
      }


    }

  }
  else{
    cout<<"Coordinates are wrong try again."<<endl;
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
    if(pieceArray[currentX][currentY]->isMoveLegal(movingToX,movingToY,currentX,currentY)&&(pieceArray[movingToX][movingToY]->exists == false)){

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
  bool canJumpDown = false;
  int jumpX;
  int possibleJumpY1;
  int possibleJumpY2;
  //Bools that check if coordinates will cause segmentation fault
  bool canUseY1 = true;
  bool canUseY2 = true;
  //Temp variables to be replaced
  int tempX;
  int tempY1;
  int tempY2;
  //Check if king can move up or down
  bool kingUp = false;
  bool kingDown = false;
  //Check if piece diagonally to the right exists
  if(isWhite || pieceArray[currentX][currentY]->type == 1 ){

    opposingPiece = abs(opposingPiece);

    //Check possible spots where there could be a piece to jump
    jumpX = currentX + opposingPiece;
    //Piece could be to left or right
    possibleJumpY1 = currentY + opposingPiece;
    possibleJumpY2 = currentY - opposingPiece;
    //verifies if movement is possible as a normal piece and as king

    if(jumpPosition(jumpX,possibleJumpY1,possibleJumpY2,canUseY1,canUseY2,currentX,currentY,kingUp,kingDown) == false){


    }
    else{
      //check to make sure segmentation fault won't occur by only using values that exist
      if((canUseY1==true) && ((pieceArray[currentX][currentY]->type == 1 && kingUp) || (pieceArray[currentX][currentY]->type == 0))){

        //Checks if there is a piece active and of the opposing color to be jumped
        if((pieceArray[jumpX][possibleJumpY1]->exists == true && pieceArray[jumpX][possibleJumpY1]->isWhite!=isWhite)){
          //Sets place where the piece that is going to be jumped is
          jumpedPieceX = jumpX;
          jumpedPieceY1 = possibleJumpY1;
          //Check if there is a space available to jump to diagonally to the opposing piece
          tempX =jumpX + opposingPiece;
          //Substracts one and goes left on possible arrival spot after jumping
          tempY1 = possibleJumpY1 + opposingPiece;
          //Check if position at futer spot exists
          if(!((tempX<0 || tempX>7)||(tempY1<0||tempY1>7))){
            //Check if position we want to jump to is empty
            if(pieceArray[tempX][tempY1]->exists == false){
              canJump = true;
            }
          }

        }


      }
      if((canUseY2==true) && ((pieceArray[currentX][currentY]->type == 1 && kingUp) || (pieceArray[currentX][currentY]->type == 0))){

        if((pieceArray[jumpX][possibleJumpY2]->exists == true && pieceArray[jumpX][possibleJumpY2]->isWhite!=isWhite)){
          jumpedPieceX = jumpX;

          jumpedPieceY2 = possibleJumpY2;

          tempX = jumpX + opposingPiece;

          tempY2 = possibleJumpY2 - opposingPiece;

          if(!((tempX<0 || tempX>7)||(tempY2<0||tempY2>7))){
            //Check if position we want to jump to is empty
            if(pieceArray[tempX][tempY2]->exists == false){
              canJump = true;
            }
          }

        }

      }


    }
    canJumpDown = canJump;

  }
  if(!isWhite || pieceArray[currentX][currentY]->type == 1){
    kingUp = false;
    kingDown = false;


    opposingPiece = -1;
    //Check possible spots where there could be a piece to jump
    jumpX = currentX + opposingPiece;
    //Piece could be to left or right
    possibleJumpY1 = currentY + opposingPiece;
    possibleJumpY2 = currentY - opposingPiece;


    //Check if it's possible for a piece to exist in those coordinates
    if(jumpPosition(jumpX,possibleJumpY1,possibleJumpY2,canUseY1,canUseY2,currentX,currentY,kingUp,kingDown)==false){

      canJump = false;
    }
    else{
      if((canUseY1 == true) && ((pieceArray[currentX][currentY]->type == 1 && kingDown) || (pieceArray[currentX][currentY]->type == 0))){








        //Checks if there is a piece active and of the opposing color to be jumped
        if((pieceArray[jumpX][possibleJumpY1]->exists == true && pieceArray[jumpX][possibleJumpY1]->isWhite != isWhite) ){


          jumpedPieceX = jumpX;
          jumpedPieceY1 = possibleJumpY1;
          //Check if there is a space available to jump to diagonally to the opposing piece
          tempX = jumpX + opposingPiece;
          //Substracts one and goes left on possible arrival spot after jumping
          tempY1 = possibleJumpY1 + opposingPiece;

          //Check if position at futer spot exists
          if(!((tempX<0 || tempX>7)||(tempY1<0||tempY1>7))){

            //Check if position we want to jump to is empty
            if(pieceArray[tempX][tempY1]->exists == false){

              canJump = true;
            }

          }

        }

      }

      if((canUseY2==true) && ((pieceArray[currentX][currentY]->type == 1 && kingDown) || (pieceArray[currentX][currentY]->type == 0))){


        //Check if there is a piece to the right and if there is check if there is an empty spot to jump to
        if((pieceArray[jumpX][possibleJumpY2]->exists == true && pieceArray[jumpX][possibleJumpY2]->isWhite!=isWhite)){
          jumpedPieceX = jumpX;
          jumpedPieceY2 = possibleJumpY2;
          tempX = jumpX + opposingPiece;
          tempY2 = possibleJumpY2 - opposingPiece;

          if(!((tempX<0 || tempX>7)||(tempY2<0||tempY2>7))){

            //Check if position we want to jump to is empty
            if(pieceArray[tempX][tempY2]->exists == false){
              canJump = true;
            }
          }


        }

      }



    }

    if(canJumpDown||canJump){
      canJump = true;

    }
  }


  return canJump;


}
bool Board::jumpPosition(int possibleX, int possibleY1,int possibleY2,bool &canUseY1,bool &canUseY2, int actualX, int actualY,
  bool &kingUp,bool &kingDown){



    bool canExist = false;


    if(pieceArray[actualX][actualY]->type == 0){
      if ((possibleY1<0||possibleY1>7) ){
        canUseY1 = false;

      }
      if((possibleY2 < 0 || possibleY2 > 7)){
        canUseY2 = false;


      }
      if((canUseY1 || canUseY2) && ((possibleX<0 || possibleX>7) == false)){
        canExist = true;

      }
    }
    else{

      if ((possibleY1<0||possibleY1>7) ){
        canUseY1 = false;

      }
      if((possibleY2 < 0 || possibleY2 > 7)){
        canUseY2 = false;


      }
      if((canUseY1 || canUseY2) &&  ((possibleX>7) == false)){
        canExist = true;
        kingUp = true;

      }
      if((canUseY1 || canUseY2) && ((possibleX<0) == false)){

        canExist = true;
        kingDown = true;
      }

    }


    return canExist;
  }

  void Board::getPieceCoordinates(int* intcurrX, int* intcurrY){

    string current;
    string currX;
    string currY;

    //print out current player
    if(isWhite){
      std::cout << "White Piece ~ ";
    }else{
      std::cout << "Black Piece ~ ";

    }
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

    //Check ascii range of values
    if((*intcurrX + '0')< 48 || (*intcurrX + '0') > 57 || (*intcurrY+ '0') < 48 || (*intcurrY + '0') >57 ){

      *intcurrX = 0;
      *intcurrY = 0;

    }


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

    if((*destinationX + '0')< 48 || (*destinationX + '0') > 57 || (*destinationY+ '0') < 48 || (*destinationY + '0') >57 ){

      *destinationX = 0;
      *destinationY = 0;

    }

  }
  void Board::upgradeToKing(int x, int y){
    //creates a new king piece and replaces the normal piece in that position

    pieceArray[x][y] = new King(true,x,y,isWhite,1);


  }
