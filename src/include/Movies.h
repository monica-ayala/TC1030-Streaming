#include <iostream>
using namespace std;
#include "Media.h"

class Movies : public Media{
  private:
    double length;
  public:
    //constructor
    Movies();
    Movies(double _ID, string _name, Genre _genre,float _raiting,double _length);
    //method
    string displayMedia() override;
    //getters y setters
    void setLength(double _length);
    double getLength();
};