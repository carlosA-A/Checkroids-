using namespace std;
#include "Piece.h"

Piece::getPosition(){

  return position;
}

Piece::getDead(){
  return countDeadPieces;
}
Piece::getWhite(){

  return isWhite;
}

Piece::setPosition(int x, int y){

  position[0] = x;
  position[1] = y;
}
