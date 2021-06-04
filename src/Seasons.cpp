#include "include/Series.h"
#include <stdio.h>
#include <vector>
using namespace std;

Seasons :: Seasons(){}

Seasons :: Seasons(vector <Episodes> _listOfEpisodes){
  numOfEpisodes = _listOfEpisodes.size();
  for (int i=0; i<numOfEpisodes; i++){
    listOfEpisodes.push_back(_listOfEpisodes[i]);
  }
}

string Seasons :: displayEpisodes(){
  string seasons = "";
  for (int i=0; i<numOfEpisodes; i++){
    seasons = seasons + " "+listOfEpisodes[i].getName()+". Raiting: "+to_string(listOfEpisodes[i].getRaiting())+"\n";
  }
  return seasons;
}

float Seasons :: getOverallRaiting(){
  int raiting = 0;
  for (int i=0; i<numOfEpisodes; i++){
    raiting = raiting + listOfEpisodes[i].getRaiting();
  }
  overallRaiting = (float)raiting/numOfEpisodes;
  return overallRaiting;
}

int Seasons :: getNumOfEpisodes(){return numOfEpisodes;}

void Seasons :: setNumOfEpisodes(int _numOfEpisodes){numOfEpisodes=_numOfEpisodes;}

void Seasons :: setListOfEpisodes(vector <Episodes> _listOfEpisodes){
  for (int i=0; i<_listOfEpisodes.size(); i++){
    listOfEpisodes[i]=_listOfEpisodes[i];
  }
}

void Seasons :: setOverallRaiting(float _overallRaiting){overallRaiting=_overallRaiting;}

vector <Episodes> Seasons :: getListOfEpisodes(){
  vector <Episodes> _listOfEpisodes;
  for(int i=0;i<numOfEpisodes;i++){
    _listOfEpisodes.push_back(listOfEpisodes[i]);
  }
  return _listOfEpisodes;
}
