#include "include/Movies.h"

Movies :: Movies(){}
Movies :: Movies(double _ID, string _name, Genre _genre,float _raiting,double _length):Media(_ID,_name,_genre,_raiting){
  length = _length;
}

string Movies :: displayMedia(){
  string movie= "---------- "+name+" ------------\n\n";
  movie = movie + "Genre: " + displayGenre()+"\n" +  "Raiting: " + to_string(raiting)+"\n"+  "Length: " + to_string(length)+"\n";
  
  return movie;
}

void Movies :: setLength(double _length){
  length = _length;
}

double Movies :: getLength(){
  return length;
}