#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>
using std::cin, std::cout, std::endl, std::string, std::getline, std::string,
      std::istringstream, std::ifstream, std::ofstream;



int main(){

    srand(time(NULL));
    cout << "This program implements a hangman game for popular English movies" << endl;
    cout << endl;
    string filename = "movies.txt";
    ifstream ifs(filename);
    if (!ifs.is_open()) {
    cout << "Failed to open file " << filename << "." << endl;
    return 1;
  }
  string movie;
  int sizeOfFile = 0;
  while(getline(ifs, movie)){
    sizeOfFile++;
  }
  ifs.clear();
  int randomMovie = rand() % sizeOfFile;

  if(randomMovie == 0){
    randomMovie++;
  }
  cout << randomMovie << endl;
  ifstream ifs2(filename);

  while(randomMovie != 0){
    getline(ifs2, movie);
    randomMovie--;
  }
  string hiddenMovie;
  std::string realMovie;
  for(int i = 0; i < movie.size(); i++){
    if(movie.at(i) == ' '){
        hiddenMovie += "  ";
        realMovie += "  ";
    }
    else{
       hiddenMovie += "_ ";
       realMovie.push_back(movie.at(i));
       realMovie += " ";
    }
  }
   char characterGuess;
   string movieGuess;
   bool movieFound = false;
   bool won = false;
   int numOfGuess = movie.size() + 2;
   std::string replaceChar;
   char uppercase;
   cout << "You have " << numOfGuess << " guesses left." << endl;
   while(numOfGuess != 0){
      cout << hiddenMovie << endl;
      cout << "Guess the character: ";
      cin >> characterGuess;
      for(int i = 0; i < realMovie.size(); i++){
        if(isupper(characterGuess) && !isupper(realMovie.at(i))){
          characterGuess = characterGuess + 32;

        }
        else{
            uppercase = characterGuess - 32;
        }
        if(realMovie.at(i) == characterGuess){
            replaceChar.push_back(characterGuess);
            hiddenMovie.replace(i, 1, replaceChar);
            replaceChar.clear();
        }
        if(realMovie.at(i) == uppercase){
            replaceChar.push_back(uppercase);
            hiddenMovie.replace(i, 1, replaceChar);
            replaceChar.clear();
        }

      }
      numOfGuess--;

      if(hiddenMovie.find("_") != string::npos){
           cout << "You have " << numOfGuess << " guesses left." << endl;
           cout << endl;
           continue;
      }
      else{
        cout << hiddenMovie << endl;
        cout << "You have won" << endl;
        won = true;
        break;
      }



    }
    cin.ignore();

    if(!won){
        cout << "Your guesses have run out, you have one chance to guess the movie to win. What is your guess? ";
        getline(cin, movieGuess);
        if(movieGuess == movie){
            cout << "You have won. " << endl;
        }
        else{
           cout << "Your guesses have run out, you have lost." << endl;
           cout << "Name of movie: " << movie << endl;
        }
    }




   return 0;
}
