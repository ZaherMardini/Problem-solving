#pragma once
#include<iostream>
#include<cctype>
#include<iomanip>
#include<fstream>
#include<cmath>
#include<vector>
#include"PSLvl-2.h"
#include"PSLvl-3.h"
#include"usersOperations.h"
using namespace std;
//=============Declarations==============
void startBankProject(stUser);
void usersMenue();
void mainMenue();
void bankProject(short, stUser);
void transMenue();
void totalBalanceMenue(vector<stClient> &clients);
void backToTrans(stUser);
void screenTitle(string title = "Main menue");
enum enOptions {eList = 1, eNew = 2, eDelete = 3, eUpdate = 4, eFind = 5, eTransaction = 6, eUsers = 7, eExit = 8};
enum entransOptions {edep = 1, ewit = 2, etotal = 3, eMain = 4};
void saveAllData(string name, vector<stClient> &clients);
string name = "Clients.txt";
stClient wanted;
stUser usr;
vector<stClient> clients = getDataFromFile(name);
//=============Declarations==============
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
int deposit(string Anumber, vector<stClient> &clients, int ammount){
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
stClient arrestClient(string Anumber, vector<stClient> &clients){
  stClient wanted;
  for (stClient &client : clients)
  {
    if(client.Anumber == Anumber){
      wanted = client;
    }
  }
  return wanted;
}
int withdraw(string Anumber, vector<stClient> &clients, int ammount){
  stClient wanted = arrestClient(Anumber, clients);
  int balance = 0;
  if(wanted.balance > ammount){
    cout << endl << "\tYour balance is: " << wanted.balance << endl;
    balance = deposit(Anumber, clients, -ammount);
    cout << endl << "\tUpdated balance is: " << balance << endl;
  }else{
    cout << "Ammount exceeds your balance" << endl;
  }
  return 0;
}
void transOption(stUser user){
  transMenue();
  short answer = readPositiveNumber("Your action [1 -> 4]: ");
  string Anumber;
  int ammount;
  switch(answer){
    case entransOptions::edep:
      screenTitle("Deposit");
      Anumber= readString("Account number: ");
      if(findClient(Anumber, clients, wanted)){
        ammount = readPositiveNumber("Mony to deposit: ");
        cout << endl; 
        cout << "\tUpdated balance is: " << deposit(Anumber, clients, ammount);
        cout << endl; 
      }else{
        cout << "Not found :(";
      }
      backToTrans(user);
    break;
    case entransOptions::ewit:
      screenTitle("Withdrow");
      Anumber= readString("Account number: ");
      if(findClient(Anumber, clients, wanted)){
        ammount = readPositiveNumber("Mony to deposit: ");
        withdraw(Anumber, clients, ammount);
      }else{
        cout << "Not found :(";
      }
      backToTrans(user);
    break;
    case entransOptions::etotal:
      totalBalanceMenue(clients);
      backToTrans(user);
    break;
    case entransOptions::eMain:
      startBankProject(user);
    break;
    default:screenTitle("Wrong answer");
  }
}
void mainMenue(){
  screenTitle();
  cout << "[1] Show client list" << endl;
  cout << "[2] Add client" << endl;
  cout << "[3] Delete client" << endl;
  cout << "[4] Update client" << endl;
  cout << "[5] find client" << endl;
  cout << "[6] Transactions menue" << endl;
  cout << "[7] Manage users" << endl;
  cout << "[8] Exit" << endl;
  drawing(10);
  cout << endl;
}
void transMenue(){
  screenTitle("Transactions menue");
  cout << "[1] Deposit" << endl;
  cout << "[2] Withdraw" << endl;
  cout << "[3] Total balances" << endl;
  cout << "[4] Main menue" << endl;
  drawing(10);
  cout << endl;
}
void printClientBalance(stClient client){
  cout << "| " << client.Anumber << setw(15);
  cout << "| " << client.name << setw(15);
  cout << "| " << client.balance << setw(15);
  cout << endl;
}
void totalBalanceMenue(vector<stClient> &clients){
  listHeader();
  short c = 1;
  for (stClient &client : clients)
  {
    cout << "\n+++++++Client" << c << "+++++++\n" << endl;
    printClientBalance(client);
    c++;
  }
}
void saveAllData(string name, vector<stClient> &clients){
  for(stClient client : clients){
    saveClientData(name, client);
  }
  cout << "File updated with clients data" << endl;
}
void addClient(string name, vector<stClient> &clients){
  stClient wanted;
  char cont = 'n';
  short added = 0;
  string Anumber = readString("Account number: ");
  if(!findClient(Anumber, clients, wanted)){
      clients.push_back(readClient2(Anumber));
      added++;
      saveClientData(name, clients[clients.size() - added]);
      cont = readChar("Client added successfully, add more? y/n: ");
      if(getLowerCase(cont) == 'y'){
        addClient(name, clients);
      }else{
        return;
      }
  }else{
    cout << "Client Already exists " << endl;
    addClient(name, clients);
  }
}
void startBankProject(stUser usr){
  mainMenue();
  short answer = readPositiveNumber("Your action [1 -> 8]: ");
  bankProject(answer, usr);
}
void backToMain(stUser usr){
  char answer = readChar("press [m] main or [e] key to exit: ");
  if(getLowerCase(answer) == 'm'){
    startBankProject(usr);
  }
}
void backToTrans(stUser u){
  char answer = readChar("press [t] Transactions menue or [e] key to exit: ");
  if(getLowerCase(answer) == 't'){
    transOption(u);
  }
}
void bankProject(short answer, stUser theUser){
  string Anumber;
  stClient wanted;
  switch(answer){
    case enOptions::eList:
    if(hasPermission(theUser, enOptions2::eList2)){
      screenTitle("Clients list");
      tabs(3);
      cout << endl << clients.size() << " clients" << endl;
      totalClientsData(clients);
    }else{
      cout << "Access Denied" << endl;
    }
      backToMain(theUser);
    break;
    case enOptions::eNew:
      if(hasPermission(theUser, enOptions2::eNew2)){
        screenTitle("New client");
        addClient(name, clients);
      }else{
      cout << "Access Denied" << endl;
      }
      backToMain(theUser);
    break;
    case enOptions::eDelete:
      if(hasPermission(theUser, enOptions2::eDelete2)){
        screenTitle("Delete client");
        Anumber = readString("Account number: ");
        deleteClient(name, Anumber, wanted, clients);
      }else{
        cout << "Access Denied" << endl;
      }
      backToMain(theUser);
    break;
    case enOptions::eUpdate:
      if(hasPermission(theUser, enOptions2::eUpdate2)){
        screenTitle("Update client");
        Anumber = readString("Account number: ");
        updateClient(name, Anumber, wanted, clients);
      }else{
        cout << "Access Denied" << endl;
      }
      backToMain(theUser);
    break;
    case enOptions::eFind:
      if(hasPermission(theUser, enOptions2::eFind2)){
        screenTitle("Find client");
        Anumber = readString("Account number: ");
        if(!findClient(Anumber, clients, wanted)){
          cout << "Not found" << endl;
        };
      }else{
        cout << "Access Denied" << endl;
      }
      backToMain(theUser);
    break;
    case enOptions::eTransaction:
      if(hasPermission(theUser, enOptions2::eTransaction2)){
        transOption(theUser);
      }else{
        cout << "Access Denied" << endl;
      }
      backToMain(theUser);
    break;
    case enOptions::eUsers:
      if(hasPermission(theUser, enOptions2::eUsers2)){
        usersOption(theUser);
      }else{
        cout << "Access Denied" << endl;
      }      
      backToMain(theUser);
    break;
    case enOptions::eExit:
      login();
    break;
    default: cout << "Wrong answer" << endl;
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
void drawing(short num, string sh){
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