#ifndef EPISODES_H
#define EPISODES_H

#include <iostream>
using namespace std;

class Episodes{
  private:
    string name;
    double length;
    float raiting;
  public:
  //constructor
    Episodes();
    Episodes(string _name, double _length, float _raiting);
  //getters y setters
    void setRaiting(float _raiting);
    string getName();
    double getLength();
    float getRaiting();
};
#endif