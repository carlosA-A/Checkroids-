using namespace std;
#include "Pieces.h"
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

void Piece::setDead(bool isDead){
  this->dead = isDead;
}
void Piece::setType(int type){

  this-> type = type;
}
void Piece::setWhite(bool isWhite){

  this-> isWhite = isWhite;
}

//-----------------------------Normal Piece setup--------------------

//bool Normal::isMoveLegal(int x, int y, int currentX, int currentY){


//}
