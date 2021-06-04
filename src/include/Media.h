#ifndef MEDIA_H
#define MEDIA_H

#include <iostream>
#include "Genre.h"
#include <vector>
using namespace std;

class Media{
  protected:
    double ID;
    string name;
    Genre genre;
    float raiting;
  public:
  //constructor
    Media();
    Media(double _ID, string _name, Genre _genre, float _raiting); 
  //abstract methods
    virtual string displayMedia()=0;
  //methods
    string displayGenre();
    void changeRaiting(int _newRaiting);
  //getters y setters
    double getID();
    string getName();
    double getLength();
    Genre getGenre();
    float getRaiting();
    void setID(double _ID);
    void setName(string _name);
    void setGenre(Genre _genre);
    void setRaiting(float _raiting);
  //operator overloading
    float operator%(const Media& val);
};
#endif