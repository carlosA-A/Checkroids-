using namespace std;
#include "Pieces.h"
#include <stdlib.h>
//-----------------------------PIECE SETTERS AND GETTERS--------------------
int* Piece::getPosition(){

  return position;
}

int Piece::getDead(){
  return countDeadPieces;
}
bool Piece::getWhite(){

  return isWhite;
}

bool Piece::getDidMove(){


  return didMove;
}
void Piece::setPosition(int x, int y){

  position[0] = x;
  position[1] = y;
}

void Piece::setDead(){
  this->dead = true;
  if(isWhite){
    whitePiecesLeft--;
    cout<<"A white piece was lost, there are "<<whitePiecesLeft<<" left"<<endl;

  }
  else{
    blackPiecesLeft--;
    cout<<"A black piece was lost, there are "<<blackPiecesLeft<<" left"<<endl;

  }
}
void Piece::setWhite(bool isWhite){

  this-> isWhite = isWhite;
}

//-----------------------------Normal Piece setup--------------------

bool Normal::isMoveLegal(int x, int y, int currentX, int currentY){

  isLegal = false;
  move[0] = x;
  move[1] = y;
  didJump = false;

  int moveTo1 = -1;   //If the piece is black then the move will substract 1 to move forward
  int moveTo2 = -2;   //Jump will take 2 from the row

  if (isWhite){ //If white move should add to row always moving forward
    moveTo1 = abs(moveTo1);
    moveTo2 = abs(moveTo2);
  }
  //Checks if diagonal move trying to be made is legal
  if((currentX + moveTo1 == move[0])&&((currentY + moveTo1 == move[1])||(currentY - moveTo1 == move[1]))){

    isLegal = true;

  }
  //checks if jump is legal
  else if ((currentX + moveTo2 == move[0])&&((currentY + moveTo2 == move[1])||(currentY - moveTo2 == move[1]) || (currentY == move[1]))&&(pieceCanJump == true)){

    isLegal = true;
    didJump = true;
    pieceCanJump = false;

  }

  return isLegal;
}


bool King::isMoveLegal(int x, int y, int currentX, int currentY){

  bool isLegal = false;
  move[0] = x;
  move[1] = y;
  didJump = false;


  int moveTo1 = -1;   //If the piece is black then the move will substract 1 to move forward
  int moveTo2 = -2;   //Jump will take 2 from the row

  //Checks if diagonal forward or backward move trying to be made is legal
  if((currentX + moveTo1 == move[0] ||currentX - moveTo1 == move[0])&&((currentY + moveTo1 == move[1])||(currentY - moveTo1 == move[1]))){

    isLegal = true;

  }
  else if ((currentX + moveTo2 == move[0] || currentX - moveTo2 == move[0])&&((currentY + moveTo2 == move[1])||(currentY - moveTo2 == move[1]))){

    isLegal = true;
    didJump = true;
    pieceCanJump = false;


  }

  return isLegal;
}
