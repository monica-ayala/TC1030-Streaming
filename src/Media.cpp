#include "include/Media.h"
#include <vector>

Media :: Media(){}

Media :: Media(double _ID, string _name, Genre _genre, float _raiting){
  ID = _ID;
  name = _name;
  genre = _genre;
  raiting = _raiting;
}

string Media::displayGenre(){
  Genre ch = genre;
  string msj = "";
  if(ch==Genre::Romance){msj = "Romance";}
  else if(ch==Genre::Drama){msj = "Drama";}
  else if(ch==Genre::Horror){msj = "Horror";}
  else if(ch==Genre::Comedy){msj = "Comedy";}
  else if(ch==Genre::Unknown){msj = "Unknown";}
  return msj;
}

void Media :: changeRaiting(int _newRaiting){
  raiting = _newRaiting;
}

double Media :: getID(){return ID;}

string Media :: getName(){return name;}

Genre Media :: getGenre(){return genre;}

void Media :: setID(double _ID){
  ID = _ID;
}

void Media :: setName(string _name){
  name = _name;
}

void Media :: setGenre(Genre _genre){
  genre = _genre;
}

void Media :: setRaiting(float _raiting){
  raiting = _raiting;
}

float Media :: getRaiting(){
  return raiting;
}

float Media :: operator%(const Media& val){
  float similarity=0;
  if(genre==val.genre){
    similarity = similarity + 50;
  }
  else if(genre!=val.genre){
    similarity = similarity + 10;
  }
  if(raiting==val.raiting){
    similarity = similarity + 49;
  }
  else if(raiting!=val.raiting){
    float d = raiting - val.raiting;
    similarity = similarity + 50 - d*10;
  }
  return similarity;
}