#pragma once
#include<iostream>
#include<cctype>
#include<iomanip>
#include<fstream>
#include<cmath>
#include<vector>
#include"PSLvl-2.h"
#include"PSLvl-3.h"
using namespace std;
//=============Declarations==============
void startBankProject();
void mainMenue();
void bankProject(short);
void transMenue();
void totalBalanceMenue(vector<stClient> &clients);
void backToTrans();
void screenTitle(string title = "Main menue");
enum enOptions {eList = 1, eNew = 2, eDelete = 3, eUpdate = 4, eFind = 5, eTransaction = 6, eExit = 7};
enum entransOptions {edep = 1, ewit = 2, etotal = 3, emain = 4};
void saveAllData(string name, vector<stClient> &clients);
string name = "Clients.txt";
vector<stClient> clients = getDataFromFile(name);
stClient wanted;
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
  if(wanted.balance > ammount){
    deposit(Anumber, clients, -ammount);
    cout << endl << "\tWithdrawed ammount is: " << ammount << endl;
  }else{
    cout << "Not enough mony to withdraw" << endl;
  }
  return 0;
}
void transOption(){
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
      backToTrans();
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
      backToTrans();
    break;
    case entransOptions::etotal:
      totalBalanceMenue(clients);
      backToTrans();
    break;
    case entransOptions::emain:
      startBankProject();
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
  cout << "[7] Exit" << endl;
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
void startBankProject(){
  mainMenue();
  short answer = readPositiveNumber("Your action [1 -> 7]: ");
  bankProject(answer);
}
void backToMain(){
  char answer = readChar("press [m] main or [e] key to exit: ");
  if(getLowerCase(answer) == 'm'){
    startBankProject();
  }
}
void backToTrans(){
  char answer = readChar("press [t] Transactions menue or [e] key to exit: ");
  if(getLowerCase(answer) == 't'){
    transOption();
  }
}
void bankProject(short answer){
  string Anumber;
  stClient wanted;
  switch(answer){
    case enOptions::eList:
      screenTitle("Clients list");
      tabs(3);
      cout << endl << clients.size() << " clients" << endl;
      totalClientsData(clients);
      backToMain();
    break;
    case enOptions::eNew:
      screenTitle("New client");
      addClient(name, clients);
      backToMain();
    break;
    case enOptions::eDelete:
      screenTitle("Delete client");
      Anumber = readString("Account number: ");
      deleteClient(name, Anumber, wanted, clients);
      backToMain();
    break;
    case enOptions::eUpdate:
      screenTitle("Update client");
      Anumber = readString("Account number: ");
      updateClient(name, Anumber, wanted, clients);
      backToMain();
    break;
    case enOptions::eFind:
      screenTitle("Find client");
      Anumber = readString("Account number: ");
      findClient(Anumber, clients, wanted);
      backToMain();
    break;
    case enOptions::eTransaction:
      transOption();
    break;
    case enOptions::eExit:
      screenTitle("Thanks for visiting");
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