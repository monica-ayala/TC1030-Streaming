#include "include/Series.h"
#include <iostream>

using namespace std;

Series :: Series(){}

Series ::Series(double _ID, string _name, Genre _genre,float _raiting, vector <Seasons> _listOfSeasons):Media(_ID, _name, _genre,_raiting){
  raiting = _raiting;
  numOfSeasons = _listOfSeasons.size();
  for (int i=0; i<numOfSeasons; i++){
    listOfSeasons.push_back(_listOfSeasons[i]);
  }
}

string Series :: displayMedia(){
  string series= "---------- "+name+" ------------\n\n";
  series = series + "Genre: " + displayGenre()+"\n" + "Avarage Episode Raiting: " + to_string(getEpisodeRaiting())+"\n"+ "Raiting: " + to_string(raiting)+"\n";
  series=series+"\n---------- Content ------------\n";
   for (int i=0; i<numOfSeasons; i++){
    series = series + "Season "+ to_string(i+1)+ ". Raiting: "+to_string(listOfSeasons[i].getOverallRaiting())+"\n"+listOfSeasons[i].displayEpisodes();
  }
  return series;
}

int Series :: getNumOfSeasons(){
  numOfSeasons = listOfSeasons.size();
  return numOfSeasons;
}

float Series :: getEpisodeRaiting(){
  float overallRaiting = 0;
  for (int i=0; i<numOfSeasons; i++){
    overallRaiting = overallRaiting + listOfSeasons[i].getOverallRaiting();
  }
  episodeRaiting = (float)overallRaiting/numOfSeasons;
  return episodeRaiting;
}


vector<Seasons> Series :: getListOfSeasons(){
  vector <Seasons> _listOfSeasons;
  for(int i=0;i<numOfSeasons;i++){
    _listOfSeasons.push_back(listOfSeasons[i]);
  }
  return _listOfSeasons;
}