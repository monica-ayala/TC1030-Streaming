#ifndef SEASONS_H
#define SEASONS_H

#include "Episodes.h"
#include <iostream>
#include <vector>
using namespace std;

class Seasons{
  private:
    int numOfEpisodes;
    vector <Episodes> listOfEpisodes; //Aggregation
    float overallRaiting;
  public:
  //constructor
    Seasons();
    Seasons(vector <Episodes> _listOfEpisodes);
  //methods
    string displayEpisodes(); 
  //getters y setters
    float getOverallRaiting();
    int getNumOfEpisodes();
    vector <Episodes> getListOfEpisodes();
    void setNumOfEpisodes(int _numOfEpisodes);
    void setListOfEpisodes(vector <Episodes> _listOfEpisodes);
    void setOverallRaiting(float _overallRaiting);
};
#endif