#include<iostream>
#include<windows.h>
#include"PSLvl-2.h"
using namespace std;
//=====================Variables=====================
struct computer{
  int wins = 0;
  int loses = 0;
};
struct player{
  int wins = 0;
  int loses = 0;
};
struct game{
  computer c;
  player p;
  string ssp[3] = {"stone", "paper", "scissors"};
  int m = 1;
  int draws = 0;
  int rounds = 0;
};
game g;
//=====================Methods=====================
string readString(string msg = "Enter a text"){
  string answer;
  cout << msg;
  cin >> answer;
  return answer;
}
string compChoice(){
  return g.ssp[randomNumber(0,2)];
}
void results(){
  cout << "--------Results--------\n";
  cout << "---->Computer: \n";
  cout << "wins: " << g.c.wins << "  ";
  cout << "Loses: " << g.c.loses << "  ";
  cout << "Draws: " << g.draws << "\n";
  cout << "---->Player: \n";
  cout << "wins: " << g.p.wins << "  ";
  cout << "Loses: " << g.p.loses << "  ";
  cout << "Draws: " << g.draws << "\t";
  cout << "\n--------Results--------\n";
}
void gameLogic(){
  cout << "======Round: " << g.m << "======" << endl;
  string comp = compChoice();
  string pl = readString("Your choice: ");
  cout << "Computer choice: " << comp << endl;
  if(comp == "stone" && pl == "paper"){//computer won
    g.p.wins++;
    g.c.loses++;
  }else if(comp == "paper" && pl == "stone"){
    cout << '\a';
    g.c.wins++;
    g.p.loses++;
  }else if(comp == "paper" && pl == "scissors"){
    cout << '\a';
    g.p.wins++;
    g.c.loses++;
  }else if(comp == "scissors" && pl == "paper"){
    g.c.wins++;
    g.p.loses++;
  }else if(comp == "scissors" && pl == "stone"){
    cout << '\a';
    g.p.wins++;
    g.c.loses++;
  }else if(comp == "stone" && pl == "scissors"){
    g.c.wins++;
    g.p.loses++;
  }else{
    g.draws++;
  }
  results();
}

void gameOver(){
  string winner;
  cout << "----------------Game Over----------------\n";
  results();
  g.c.wins > g.p.wins ? winner = "Computer" : g.c.wins == g.p.wins ? winner = "No one" : winner = "player";
  cout << "Ther final winner is: " << winner << endl;
  cout << "\n----------------Game Over----------------\n";
}
void resetGame(){
  g.c.wins = 0;
  g.c.loses = 0;
  g.p.wins = 0;
  g.p.loses = 0;
  g.draws = 0;
  g.rounds = 0;
  g.m = 1;
}
void newGame(){
  resetGame();
  g.rounds = readPositiveNumber("Rounds to play: ");
  while(g.rounds >= 0){
    gameLogic();
    g.rounds--;
    g.m++;
    if(g.rounds == 0){
      gameOver();
      char cont = tolower(readChar(("Play agian y/n?: ")));
      if(cont == 'y'){
        newGame();
      }else{
        break;
      }
    }
  }
}
//=================Main function=================
int main(){
  int c = 2;
  // HANDLE console_color; 
  // console_color = GetStdHandle(STD_OUTPUT_HANDLE);
  srand((unsigned)time(NULL));
  cout << "=====================" << endl;
  newGame();
  cout << "=====================" << endl;
  // SetConsoleTextAttribute(console_color, c); 
  // cout << c << endl;
  return 0;
}