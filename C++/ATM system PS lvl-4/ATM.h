#pragma once
#include<iostream>
#include<cctype>
#include<iomanip>
#include<fstream>
#include<cmath>
#include<vector>
using namespace std;
//=============Declarations==============
enum options {eQWith = 1, eNWith = 2, eCheck = 3, eDep = 4, eOut = 5};
string name = "Clients.txt";
struct stClient{
  string Anumber;
  string name;    
  string pin;
  string phone;
  int balance;
  bool deleteme = false;
};
vector<stClient> getDataFromFile(string name, string sep = "//");
vector<stClient> clients = getDataFromFile(name);
//=============Declarations==============
string recordToString(stClient c, string sep = "//"){
  string banckInfo = c.Anumber + sep + c.name + sep + c.pin + sep + c.phone + sep + to_string(c.balance);
  return banckInfo;
}
vector<string>zsplit(string txt, string delimiter = " "){
  short pos = 0;
  vector<string>vtokens;
  string token = "";
  short tcount = 0;
  while((pos = txt.find(delimiter)) != string::npos){
    token = txt.substr(0, pos);
    if(token != ""){
      tcount++;
      vtokens.push_back(token);
    }
    txt.erase(0, pos + delimiter.length());
  }
  if(txt != ""){
    vtokens.push_back(txt);
  }
  return vtokens;
} 
stClient stringToRecord(string txt, string sep = "//"){
  stClient c;
  vector<string>data = zsplit(txt, sep);
  c.Anumber = data.at(0);
  c.name = data.at(1);
  c.pin = data.at(2);
  c.phone = data.at(3);
  c.balance = stoi(data.at(4));
  return c;
}
vector<stClient> getDataFromFile(string name, string sep){
  vector<stClient>data;
  fstream f;
  string line;
  f.open(name, ios::in);
  if(f.is_open()){
    while(getline(f, line)){
      data.push_back(stringToRecord(line));
      // data.push_back(line);
    }
    f.close();
  }
  return data;
}
char getLowerCase(char &word){
  return char(tolower(word));
}
string readString(string msg = "Enter a text: "){
  cout << msg;
  string t;
  getline(cin >> ws, t);
  return t;
}
char readChar(string msg = "Enter a text"){
  char answer;
  cout << msg;
  cin >> answer;
  return answer;
}
int readPositiveNumber(string msg = "Enter a positive number: "){
  int number = 0;
  do{
  cout << msg;
  cin >> number;
  }while(number < 0);
  return number;
}
void drawing(short num, string sh = "-----"){
  for (short i = 0; i < num; i++)
  {
    cout << sh;
  }
}
void tabs(short num){
  for (short i = 0; i < num; i++)
  {
    cout << "\t";
  }
}
void screenTitle(string title){
  drawing(10);
  cout << endl;
  tabs(2);
  cout << title << endl;
  drawing(10);
  cout << endl;
}
void mainMenue(){
  screenTitle("ATM system");
  cout << "[1] Quick withdraw" << endl;
  cout << "[2] Normal withdraw" << endl;
  cout << "[3] Check balance" << endl;
  cout << "[4] Deposit" << endl;
  cout << "[5] Logout" << endl;
  drawing(10);
  cout << endl;
}
short quickMenue(){
  screenTitle("Quick withdraw");
  cout << "[1] 20";
  cout << "\t\t[2] 50";
  cout << endl;
  cout << "[3] 100";
  cout << "\t\t[4] 200";
  cout << endl;
  cout << "[5] 400";
  cout << "\t\t[6] 600";
  cout << endl;
  cout << "[7] 800";
  cout << "\t\t[8] 1000" << endl;
  drawing(10);
  cout << endl;
  short ans = readPositiveNumber("Your action [1 -> 8]: ");
  return ans;
}
enum enQuick {e20 = 1, e50 = 2, e100 = 3, e200 = 4, e400 = 5, e600 = 6, e800 = 7, e1000 = 8};
int Qwithdraw(string Anumber, string pin, vector<stClient> &clients, int ammount);
void quickWithdraw(short answer, string Anumber, string pin, vector<stClient> &clients){
  switch (answer){
    case enQuick::e20:
    Qwithdraw(Anumber, pin, clients, 20);
    break;
    case enQuick::e50:
    Qwithdraw(Anumber, pin, clients, 50);
    break;
    case enQuick::e100:
    Qwithdraw(Anumber, pin, clients, 100);
    break;
    case enQuick::e200:
    Qwithdraw(Anumber, pin, clients, 200);
    break;
    case enQuick::e400:
    Qwithdraw(Anumber, pin, clients, 400);
    break;
    case enQuick::e600:
    Qwithdraw(Anumber, pin, clients, 600);
    break;
    case enQuick::e800:
    Qwithdraw(Anumber, pin, clients, 800);
    break;
    case enQuick::e1000:
    Qwithdraw(Anumber, pin, clients, 1000);
    break;
    default:
    cout << "There is no such option" << endl;
    break;
  }
}
//=========client operations
void clientProfile(stClient c){
  drawing(5);
  cout << "Client data";
  drawing(5);
  cout << endl;
  cout << "Account number: " << c.Anumber << endl;
  cout << "Name: " << c.name << endl;
  cout << "Pin code: " << c.pin << endl;
  cout << "Phone number: " << c.phone << endl;
  cout << "Balance: " << c.balance << endl;
}
bool checkClient(string Anumber, vector<stClient> &clients){
  for (stClient client : clients)
  {
    if(client.Anumber == Anumber){
      clientProfile(client);
      return true;
    }
  }
  return false;
}
bool checkClient(string Anumber, string pin, vector<stClient> &clients){
  for (stClient client : clients)
  {
    if(client.Anumber == Anumber){
      if(client.pin == pin){
        clientProfile(client);
        return true;
      }
    }
  }
  return false;
}
bool findClient(string Anumber, vector<stClient> &clients, stClient &empty){
  for (stClient client : clients)
  {
    if(client.Anumber == Anumber){
      empty = client;
      clientProfile(empty);
      return true;
    }
  }
  return false;
}
bool findClient(string Anumber, string pin, vector<stClient> &clients, stClient &empty){
  for (stClient client : clients)
  {
  if(client.Anumber == Anumber){
    if(client.pin == pin){
      empty = client;
      return true;
    } 
  }
  }
  return false;
}
stClient arrestClient(string Anumber, string pin, vector<stClient> &clients){
  stClient wanted;
  for (stClient &client : clients)
  {
  if(client.Anumber == Anumber){
    if(client.pin == pin){
      wanted = client;
      break;
    } 
  }
  }
  return wanted;
}
//=========client operations
void control(short answer, stClient client);
void startATMProject(stClient client){
  mainMenue();
  short answer = readPositiveNumber("Your action [1 -> 5]: ");
  control(answer, client);
}
void backToMain(stClient client){
  char answer = readChar("press [m] main or [e] key to exit: ");
  if(getLowerCase(answer) == 'm'){
    control(answer, client);
  }
}
bool infoValidation(string Anumber, string pin, stClient &empty){
  if(!findClient(Anumber, pin, clients, empty)){
    bool error;   
    cout << "Account number or pin wrong, try again" << endl;
    do{
      string Anumber = readString("Account number: ");
      string pin = readString("Pin: ");
      error = !findClient(Anumber, pin, clients, empty);
      if(error){
        cout << "Account number or pin wrong" << endl;
      }
    }while(error);
    return true;
  }
  return true;
}
void login(){
  char exit = readChar("Press [l] to login or any key to exit: ");
  if(getLowerCase(exit) == 'l'){
    screenTitle("Login: ");
    cout << endl;
    stClient wanted;
    string Anumber = readString("Account number: ");
    string pin = readString("Pin: ");
    if(infoValidation(Anumber, pin, wanted)){
      startATMProject(wanted);
    }
  }else{
    return;
  }
}
// =============ATM operations============
int updateBalance(stClient &wanted, vector<stClient> &clients, int ammount){
  int balance = wanted.balance += ammount;
  fstream f;
  string dataLine;
  f.open(name, ios::out);
  if(f.is_open()){
    for (stClient client : clients)
    {
      f << recordToString(client) << endl;
    }
  }
  f.close();
  clients = getDataFromFile(name);
  return balance;
}
int deposit(string Anumber, string pin, vector<stClient> &clients, int ammount){
  int balance = 0;
  for (stClient &client : clients)
  {
    if(client.Anumber == Anumber){
      balance = updateBalance(client, clients, ammount);
      break;
    }
  }
  return balance;
}
bool ammountValidation(int &ammount, stClient &wanted){
  if((wanted.balance > ammount) && (ammount % 5 == 0)){
    return true;
  }
  do{
  ammount = readPositiveNumber("Enter an ammount multiple of 5's: ");
  if(ammount > wanted.balance){cout << "Ammount exceeds your balance" << endl;};
  }while((wanted.balance < ammount) || (ammount % 5 != 0));
  return true;
}
int withdraw(string Anumber, string pin, vector<stClient> &clients, int ammount){
  stClient wanted = arrestClient(Anumber, pin, clients);
  if(ammountValidation(ammount, wanted)){
    int balance = 0;
    cout << endl << "\tYour balance was: " << wanted.balance << endl;
    balance = deposit(Anumber, pin, clients, -ammount);
    cout << endl << "\tUpdated balance is: " << balance << endl;
  }
  return 0;
}
int Qwithdraw(string Anumber, string pin, vector<stClient> &clients, int ammount){
  stClient wanted = arrestClient(Anumber, pin, clients);
    int balance = 0;
    if(ammount > wanted.balance){
      cout << "Ammount exceeds your balance" << endl;
      return 0;
    }
    cout << endl << "\tYour balance was: " << wanted.balance << endl;
    balance = deposit(Anumber, pin, clients, -ammount);
    cout << endl << "\tUpdated balance is: " << balance << endl;
  return 0;
}
// =============ATM operations===========
// =============control===============
void control(short answer, stClient client){
  string Anumber;
  string pin;
  short ans;
  int ammount;
  switch(answer){
    case options::eQWith:
      ans = quickMenue();
      quickWithdraw(ans, client.Anumber, client.pin, clients);
    break;
    case options::eNWith:
      ammount = readPositiveNumber("Ammount of mony to withdraw (multiple of 5's): ");
      withdraw(client.Anumber, client.pin, clients, ammount);
    break;
    case options::eCheck:
      cout << "Your balance is: " << client.balance << endl;
    break;
    case options::eDep:
      ammount = readPositiveNumber("Ammount of mony to deposit: ");
      deposit(client.Anumber, client.pin, clients, ammount);
    break;
    case options::eOut:
    login();
    break;
    default:
    cout << "Wrong answer" << endl;
    break;
  }
}