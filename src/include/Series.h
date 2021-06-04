#include "Media.h"
#include "Seasons.h"
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class Series : public Media{
  private:
    int numOfSeasons;
    float episodeRaiting;
    vector <Seasons> listOfSeasons; //aggregation
  public:
  //constructor
    Series();  
    Series(double _ID, string _name, Genre _genre,float _raiting,  vector <Seasons> _listOfSeasons);
  //method overriden from the pure virtual function
    string displayMedia() override;
  //getters y setters
    int getNumOfSeasons();
    float getEpisodeRaiting();
    vector<Seasons> getListOfSeasons();
};