#include "include/Episodes.h"

Episodes :: Episodes(){}

Episodes :: Episodes(string _name, double _length, float _raiting){
  name = _name;
  length = _length;
  raiting = _raiting;
}

void Episodes :: setRaiting(float _raiting){
  raiting = _raiting;
}

string Episodes :: getName(){return name;}

double Episodes :: getLength(){return length;}

float Episodes :: getRaiting(){return raiting;}