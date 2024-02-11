#include<iostream>
#include"PSLvl-2.h"
using namespace std;
//=====================Variables=====================
struct player{
  int wins = 0;
  int loses = 0;
};
struct game{
  player p;
  string d[4] = {"easy", "medium", "hard", "mix"};
  int m = 1;
  int rounds = 0;
  int total = 0;
  short choice = 0;
  int a = 0;
  int b = 0;
  int answer = 0;
  int correct = 0;
  char op;
};
game g;
//=====================Methods=====================
void initiate();
void question(int &a, int &b);
void resetGame(){
  g.a = 0;
  g.b = 0;
  g.answer = 0;
  g.p.wins = 0;
  g.p.loses = 0;
  g.rounds = 0;
  g.m = 1;
}
void results(){
  cout << "\n--------Results--------\n";
  cout << "---->Player: \n";
  cout << "wins: " << g.p.wins << "  ";
  cout << "Loses: " << g.p.loses << "  ";
  cout << "\n--------Results--------\n";
}
void gameOver(){
  bool winning;
  cout << "\n----------------Game Over----------------\n";
  g.p.wins > g.p.loses ? winning = true : winning = false;
  if(winning){
    cout << "You won!" << endl;
  }else{
    cout << "You lose!" << endl;
  }
  cout << "\n----------------Game Over----------------\n";
}
void adjustNumbersToDificulty(int &a, int &b){
  switch (g.choice) {
    case 0:
      a = randomNumber(0,10);
      b = randomNumber(0,10);
    break;
    case 1:
      a = randomNumber(10,500);
      b = randomNumber(10,500);
    break;
    case 2:
      a = randomNumber(10,1000);
      b = randomNumber(10,1000);
    break;
    case 3:
      a = randomNumber(10,1000);
      b = randomNumber(50,50);
    break;
  }
}
void initiate(){
  resetGame();
  g.rounds = readPositiveNumber("Number of questions to answer: ");
  g.choice = readPositiveNumber("Choose difficulty [0]easy, [1]medium, [2]hard, [3]mix: ");
  g.op = readChar("Select operation: ");
  g.total = g.rounds;
}
void newGame(){
  initiate();
  while(g.rounds > 0){
    cout << "======Question: " << g.m << " of " << g.total << "======" << endl;
    adjustNumbersToDificulty(g.a,g.b);
    question(g.a,g.b);
    g.rounds--;
    g.m++;
    if(g.rounds == 0){
      gameOver();
      char cont = tolower(readChar(("Continue y/n?: ")));
      if(cont == 'y'){
        newGame();
      }else{
        cout << "Thanks for playing :)" << endl;
        break;
      }
    }
  }
}
void checkAnswer(int &a, int &b, int &correct, int &answer, char op){
  cout << a << "\n";
  cout << "\t" << op << "\n";
  cout << b << "\n";
  cout << "________" << "\n";
  if(op == '/' && b == 0){
    b++;
  }
  answer = readNumber("Your answer: ");
  if(answer == correct){
    g.p.wins++;
    cout << "+++correct answer+++" << endl;
  }else{
    g.p.loses++;
    cout << "---wrong answer---" << endl;
    cout << "correct answer is: " << correct << endl;
  }
  answer = 0;
}
void question(int &a, int &b){
  int correct = 0; 
  int answer = 0; 
  switch (g.op){
    case '+':
    correct = a + b;
    checkAnswer(a, b, correct, answer,g.op);
    break;
    case '-':
    correct = a - b;
    checkAnswer(a, b, correct, answer,g.op);
    break;
    case '*':
    correct = a * b;
    checkAnswer(a, b, correct, answer,g.op);
    break;
    case '/':
    correct = a / b;
    checkAnswer(a, b, correct, answer,g.op);
    break;
  }
}
//=================Main function=================
int main(){
  srand((unsigned)time(NULL));
  newGame();
  return 0;
}