#include "App.h"

App::App(){}
void App::start() {

  ifstream file("Series.txt");
  LoadSeries(file);
  ifstream file2("Movies.txt");
  LoadMovies(file2);
  while (true){
    bool stop;
    stop=menu();
    if (stop == true){
      break;
    }
  }

}

bool App::menu(){
  cout << endl << "------------MENU------------------"<<endl<<endl;
  cout<<"1. Media by raiting"<<endl;
  cout<<"2. Media by genre"<<endl;
  cout<<"3. Episodes in series by raiting"<<endl;
  cout<<"4. Movies of certain raiting"<<endl;
  cout<<"5. Rate Media"<<endl;
  cout<<"6. Rate an Episode of Series"<<endl;
  cout<<"7. Compare two pieces of media"<<endl;
  cout<<"8. Exit"<<endl;

  int op;
  cin >> op;
  switch (op){
    case 1:
      sortByRaiting();
      break;
    case 2:
      sortByGenre();
      break;
    case 3:
      sortEpisodesByRaiting();
      break;
    case 4:
      sortMoviesByRaiting();
      break;
    case 5:
      rateMedia();
      break;
    case 6:
      rateEpisodeMedia();
      break;
    case 7:
      compareMedia();
      break;
    case 8:
      return true;
      break; 
  }
  return false;
}

void App::LoadSeries(ifstream &file){
  for(int i=0;i<=maxPeople("Series.txt");i++){
    double ID;
    string name;
    Genre genre;
    int seasons,episodes;
    float raiting;
    vector <Seasons> listOfSeasons;
    file >> ID;
    file >> name;
    genre = readGenre(file);
    file >> raiting;
    file >> seasons;
    for(int j=0;j<seasons;j++){
      file >> episodes;
      vector <Episodes> listOfEpisodes;
      for(int k=0;k<episodes;k++){
        string name;
        double length;
        int raiting;
        file >> name;
        file >> length;
        file >> raiting;
        Episodes ep(name, length,raiting);
        listOfEpisodes.push_back(ep);
      }
      Seasons ss(listOfEpisodes);
      listOfSeasons.push_back(ss);
    }
    vectorMedia.push_back(new Series(ID,name,genre,raiting,listOfSeasons)); 
  }
}

void App::LoadMovies(ifstream &file){
  for(int i=0;i<=maxPeople("Movies.txt");i++){
    double ID;
    string name;
    Genre genre;
    float raiting;
    double length;
    file >> ID;
    file >> name;
    genre = readGenre(file);
    file >> raiting;
    file >> length;
    vectorMedia.push_back(new Movies(ID,name,genre,raiting,length)); 
}}

int App::maxPeople(const char* file){
  ifstream inFile(file);
  int c = std::count(istreambuf_iterator<char>(inFile),istreambuf_iterator<char>(), '\n');
  return c;
}

Genre App::readGenre(ifstream &input){
  char ch;
  input >> ch;
  switch(ch) {
    case 'C':
      return Genre::Comedy;
    case 'R':
      return Genre::Romance;
    case 'D':
      return Genre::Drama;
    case 'H':
      return Genre::Horror;
    default:
      return Genre::Unknown;
  }
}

void App::sortByRaiting(){
  cout<<"To sort by raiting please enter the minimum raiting out of 5 you wish to sort by: ";
  float r; cin >> r;
  for(Media *i : vectorMedia){
    if(i->getRaiting()>r){
      const type_info & type_info = typeid(*i);
      if(type_info == typeid(Series)){
        Series*pl = (Series*)i;
        cout<<pl->displayMedia()<<endl<<endl;
      }
      if(type_info == typeid(Movies)){
        Movies*ml = (Movies*)i;
        cout<<ml->displayMedia()<<endl<<endl;
      }
    }
  }
}

void App::sortByGenre(){
  cout<<"To sort by genre please enter Drama, Romance, Horror, Comedy : ";
  string r; cin >> r;

  for(Media *i : vectorMedia){
    if(i->displayGenre()==r){
      const type_info & type_info = typeid(*i);
      if(type_info == typeid(Series)){
        Series*pl = (Series*)i;
        cout<<pl->displayMedia()<<endl<<endl;
      }
      if(type_info == typeid(Movies)){
        Movies*ml = (Movies*)i;
        cout<<ml->displayMedia()<<endl<<endl;
      }
    }
  }
}

void App::sortMoviesByRaiting(){
  cout<<"To sort by raiting please enter the minimum raiting out of 5 you wish to sort by: ";
  float r; cin >> r;
  for(Media *i : vectorMedia){
    if(i->getRaiting()>r){
      const type_info & type_info = typeid(*i);
      if(type_info == typeid(Movies)){
        Movies*ml = (Movies*)i;
        cout<<ml->displayMedia()<<endl<<endl;
      }
    }
  }
}

void App::sortEpisodesByRaiting(){
  cout<<"To sort episodes by raiting please enter the series you wish to search: ";
  string n; cin >> n;
  cout<<"And now the minimum raiting you wish to filter by: ";
  float r; cin >> r;
  Media* choosenSeries;
  for(Media *i : vectorMedia){
    if(i->getName()==n){
      choosenSeries = i;
    }
  }
  cout<<"----------- "<<choosenSeries->getName()<<" ----------"<<endl;
  const type_info & type_info = typeid(*choosenSeries);
  if(type_info == typeid(Series)){
    Series*cs = (Series*)choosenSeries;
    for(int j=0;j<cs->getListOfSeasons().size();j++){
      for(int k=0;k<cs->getListOfSeasons()[j].getListOfEpisodes().size();k++){
        if(cs->getListOfSeasons()[j].getListOfEpisodes()[k].getRaiting()>r){
          cout<<" -"<<cs->getListOfSeasons()[j].getListOfEpisodes()[k].getName()<<endl;
        }
      }
    }
  }
}

void App::sortMoviesByGenre(){
  cout<<"To sort movies by genre please enter Drama, Romance, Horror, Comedy : ";
  string r; cin >> r;
  for(Media *i : vectorMedia){
    if(i->displayGenre()==r){
      const type_info & type_info = typeid(*i);
      if(type_info == typeid(Movies)){
        Movies*ml = (Movies*)i;
        cout<<ml->displayMedia()<<endl<<endl;
      }
    }
  }
}

void App:: rateMedia(){
  cout<<"To rate a Movie or Series first enter their name: ";
  string n;cin>>n;
  cout<<"Now enter the raiting you want: ";
  float r;cin>>r;
  Media* i;
  for(Media *j : vectorMedia){
    if(j->getName()==n){
      i = j;
      i->setRaiting(r);
    }
  }
  const type_info & type_info = typeid(*i);
  if(type_info == typeid(Series)){
     Series*pl = (Series*)i;
     cout<<pl->displayMedia()<<endl<<endl;
    }
  if(type_info == typeid(Movies)){
    Movies*ml = (Movies*)i;
    cout<<ml->displayMedia()<<endl<<endl;
  }
}
 
void App::rateEpisodeMedia(){
  cout<<"To rate an episode in a series first enter the serie´s name: ";
  string n;cin>>n;
  Series* i;
  for(Media *j : vectorMedia){
    const type_info & type_info = typeid(*j);
    if(type_info == typeid(Series)){
      if(j->getName()==n){
        i = (Series*)j;
      }
    }
  }
  cout <<"Now enter the episode name: ";
  string n2;cin>>n2;
  cout <<"Now enter the raiting: ";
  float r;cin>>r;
  for(Seasons j : i->getListOfSeasons()){
    for(Episodes k : j.getListOfEpisodes()){
      if(k.getName()==n2){
        k.setRaiting(r);
        cout<<endl<<"-------"<<n<<" Episode: "<<n2<<"--------"<<endl;
        cout<<" Raiting: "<<k.getRaiting()<<endl;

      }
    }
  }
}

void App::compareMedia(){
  cout<<endl<<"To compare two pieces of media first type the name of the first piece you wish to compare: ";
  string n; cin>>n;
  cout<<endl<<"Now type the second name of the piece you want to compare: ";
  string n2; cin>>n2;
  Media* i;
  Media* k;
  for(Media *j : vectorMedia){
    if(j->getName()==n){
      i = j;
    }
    if(j->getName()==n2){
      k = j;
    }
  }
  cout<<endl<<"Similarity: "<<to_string((int)(*i%*k))<<"%"<<endl;
}