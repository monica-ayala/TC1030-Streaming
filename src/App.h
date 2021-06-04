//this class has all of the functions to manipulate Media objects and interact with the user

#include "include/Episodes.h"
#include "include/Seasons.h"
#include "include/Media.h"
#include "include/Series.h"
#include "include/Movies.h"
#include "include/Genre.h"
#include <vector>
#include <bits/stdc++.h>
#include <fstream>
using namespace std;

class App{
  private:
    vector <Media*> vectorMedia; //composition
  public:
    App();
    void start();
    bool menu();
    void LoadSeries(ifstream &file); //read Series.txt
    void LoadMovies(ifstream &file); //read Movies.txt
    int maxMedia(const char* file); //MaxMedia
    Genre readGenre(ifstream &input);
    void sortByRaiting();
    void sortByGenre();
    void sortMoviesByGenre();
    void sortEpisodesByRaiting();
    void sortMoviesByRaiting();
    void rateMedia();
    void rateEpisodeMedia();
    void compareMedia();
};

