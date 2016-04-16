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
int Piece::getType(){

  return type;
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
}
void Piece::setType(int type){

  this-> type = type;
}
void Piece::setWhite(bool isWhite){

  this-> isWhite = isWhite;
}

//-----------------------------Normal Piece setup--------------------

bool Normal::isMoveLegal(int x, int y, int currentX, int currentY){

  bool isLegal = false;
  move[0] = x;
  move[1] = y;

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
  else if ((currentX + moveTo2 == move[0])&&((currentY + moveTo1 == move[1])||(currentY - moveTo1 == move[1]))){

    isLegal = true;

  }

  return isLegal;
}
