#pragma once
#include <iostream>
#include "clsPerson.h"
#include "clsString.h"
#include "clsInputValidation.h"
#include <vector>
#include <fstream>
using namespace std;

class clsBankClient : public clsPerson{
private:
  enum enMode {emptyMode = 0, eUpdateMode = 1, eAddMode = 2};
  enMode _mode;
  string _AccountNumber;
  string _pin;
  double _balance;
  bool deleteme = false;

  static clsBankClient _creatEmptyClient(){
    return clsBankClient(enMode::emptyMode, "", "", "", "", "", "", 0);
  }

  static clsBankClient _convertLineToClientObject(string line, string sep = "#//#"){
    vector<string>vBankClients;
    vBankClients = clsString::split(line, sep);
    return clsBankClient(
    enMode::eUpdateMode,vBankClients[0],
    vBankClients[1], vBankClients[2], vBankClients[3],
    vBankClients[4], vBankClients[5], stod(vBankClients[6])
    );
  }

  static string _convertClientObjectToLine(clsBankClient clientObject, string sep = "#//#"){
    string line = "";
    line += clientObject.getFirst() + sep + clientObject.getLast() + sep;
    line += clientObject.getEmail() + sep + clientObject.getPhone() + sep;
    line += clientObject.getAccountNumber() + sep + clientObject.getPin();
    line += sep + to_string(clientObject.getBalance());
    return line;
  }

  static vector<clsBankClient>_loadClientsFromFile(string fileName = "Clients.txt"){
    vector<clsBankClient>vClients;
    fstream f;
    string line;
    f.open(fileName, ios::in);
    if(f.is_open()){
      while(getline(f, line)){
        clsBankClient client = _convertLineToClientObject(line);
        vClients.push_back(client);
      }
      f.close();
    }
    return vClients;
  }

  static void _saveClientsDataToFile(vector<clsBankClient>vUpdatedClients, string fileName = "Clients.txt"){
    fstream f;
    f.open(fileName, ios::out);
    if(f.is_open()){
      for (clsBankClient &UpdatedClient : vUpdatedClients)
      {
        if(UpdatedClient.deleteme == false){
          string line = _convertClientObjectToLine(UpdatedClient);
          f << line << endl;
        }
      }
      f.close();
    }
  }


  void _addDataLineToFile(string line, string fileName = "Clients.txt"){
    fstream f;
    f.open(fileName, ios::out | ios::app);
    if(f.is_open()){
      f << line << endl;
    }
    f.close();
  }

  void _updateRecord(){
    vector<clsBankClient>vCurrentClients = _loadClientsFromFile();
    for (clsBankClient &currentClient : vCurrentClients)
    {
      if(currentClient.getAccountNumber() == this->getAccountNumber()){
        currentClient = *this;
        break;
      }
    }
    this->_saveClientsDataToFile(vCurrentClients);
  }

  void _add(){
    _addDataLineToFile(_convertClientObjectToLine(*this));
  }
  void _delete(){
    vector<clsBankClient>clients = _loadClientsFromFile();
    for (clsBankClient &currentClient : clients)
    {
      if(this->_AccountNumber == currentClient._AccountNumber){
        currentClient.deleteme = true;
        break;
      }
    }
    _saveClientsDataToFile(clients);
    *this = _creatEmptyClient();
  }
public:
  
  clsBankClient(enMode mode, string f, string l, string e, string p, string AccountNumber, string pin, float balance)
  :clsPerson(f, l, e, p){
    this->_mode = mode;
    this->_AccountNumber = AccountNumber;
    this->_pin = pin;
    this->_balance = balance;
  }
  //==========setters and getters==========
  string getAccountNumber(){ // Account number is read-only
    return this->_AccountNumber;
  }
  void setPin(string pin){
    this->_pin = pin;
  }
  string getPin(){
    return this->_pin;
  }
  void setBalance(float balance){
    this->_balance = balance;
  }
  float getBalance(){
    return this->_balance;
  }
  //==========setters and getters==========
  bool isEmpty(){
    return this->_mode == enMode::emptyMode;
  }
  void print(){
    cout << "\nClient Card:";
    cout << "\n___________________";
    cout << "\nFirstName   : " << getFirst();
    cout << "\nLastName    : " << getLast();
    cout << "\nFull Name   : " << fullName();
    cout << "\nEmail       : " << getEmail();
    cout << "\nPhone       : " << getPhone();
    cout << "\nAcc. Number : " << getAccountNumber();
    cout << "\nPassword    : " << getPin();
    cout << "\nBalance     : " << getBalance();
    cout << "\n___________________\n";
  }
  static vector<clsBankClient>ltest(){
    return _loadClientsFromFile();
  }
  static clsBankClient find(string AccountNumber, string fileName = "Clients.txt"){
    // Here we search inside the file, i don't know why
    fstream f;
    f.open(fileName, ios::in);
    if(f.is_open()){
      string line;
      while(getline(f,line)){
        clsBankClient client = _convertLineToClientObject(line);
        if(client.getAccountNumber() == AccountNumber){
          f.close();
          return client;
        }
      }
      f.close();
    }
    return _creatEmptyClient();
  }

  static clsBankClient find(string AccountNumber, string pin, string fileName = "Clients.txt"){
    fstream f;
    f.open(fileName, ios::in);
    if(f.is_open()){
      string line;
      while(getline(f,line)){
        clsBankClient client = _convertLineToClientObject(line);
        if(client.getAccountNumber() == AccountNumber && client.getPin() == pin){
          f.close();
          return client;
        }
      }
      f.close();
    }
    return _creatEmptyClient();
  }

  static bool clientExist(string AccountNumber){
    clsBankClient client = find(AccountNumber);
    return (!client.isEmpty());
  }

  enum enSaveResults {eFailed = 0, eSucceeded = 1, eAccountExist = 3};

  enSaveResults save(){
    switch(this->_mode){
      case enMode::eAddMode:
        _add();
        this->_mode = eUpdateMode;
      return eSucceeded;
      case enMode::eUpdateMode:
        this->_updateRecord();
      return enSaveResults::eSucceeded;
    }
    return enSaveResults::eFailed;
  }

  void readClientInfo(clsBankClient &client){
    string first = clsInputValidation::readString("First name: ");
    client.setFirst(first);
    string last = clsInputValidation::readString("Last name: ");
    client.setLast(last);
    string email = clsInputValidation::readString("Email: ");
    client.setEmail(email);
    string phone = clsInputValidation::readString("Phone: ");
    client.setPhone(phone);
    string pin = clsInputValidation::readString("Pin: ");
    client.setPin(pin);
    float balance = clsInputValidation::readDblNumber("Balance: ");
    client.setBalance(balance);
  }
  void updateClient(){
    updateClient(this->getAccountNumber());
  }
  void updateClient(string AccountNumber){
    while(!clsBankClient::clientExist(AccountNumber)){
      AccountNumber = clsInputValidation::readString("Invalid account number, try again: ");
    }
    clsBankClient clientToUpdate = clsBankClient::find(AccountNumber);
    cout << "\nClient info before update:\n" << endl;
    clientToUpdate.print();
    readClientInfo(clientToUpdate);
    enSaveResults saveResult = clientToUpdate.save();
    // UI code below
    switch(saveResult){
      case enSaveResults::eFailed:
        cout << "Failed" << endl;
      break;
      case enSaveResults::eSucceeded:
        cout << "\nUpdate complete" << endl;
        clientToUpdate.print();
      break;
    }
  }
  void addNewClient(){
    addNewClient(this->getAccountNumber());
  }
  void addNewClient(string AccountNumber){
    while(clsBankClient::clientExist(AccountNumber)){
      AccountNumber = clsInputValidation::readString("Account Exists, try again: ");
    }
    clsBankClient newClient = _creatEmptyClient();
    newClient._mode = enMode::eAddMode;
    newClient._AccountNumber = AccountNumber;
    readClientInfo(newClient);
    enSaveResults saveResult = newClient.save();
    // UI code below
    switch(saveResult){
      case enSaveResults::eSucceeded:
        cout << "\nNew client added successfuly" << endl;
        newClient.print();
      break;
      case enSaveResults::eAccountExist:
        cout << "\n Process failed, Client already exists" << endl;
      break;
      default:
        cout << "\n Cannot save an empty client" << endl;
      break;
    }
  }
  void deleteClient(){
    deleteClient(this->_AccountNumber);
  }
  void deleteClient(string AccountNumber){
    while(!clsBankClient::clientExist(AccountNumber)){
      AccountNumber = clsInputValidation::readString("Account doesn't exist, try again: ");
    }
    if(this->_AccountNumber == AccountNumber){
      *this = _creatEmptyClient();
    }
    clsBankClient c = find(AccountNumber);
    c.print();
    char answer = clsInputValidation::readChar("Delete this client [y/n]?: ");
    if(clsUtility::getLowerCase(answer) == 'y'){
      c._delete();
      c.print();
    }
  }
  static vector<clsBankClient>clientsData(){
    return _loadClientsFromFile();
  }
static void printClientList(){
  vector<clsBankClient> vClientsData = clientsData();
  short clientsNumber = vClientsData.size();
  if(clientsNumber == 0){
    cout << "\n\t\t\t\t\tClients List (" << vClientsData.size() << ") Client(s)." << endl;
    cout << endl;
    clsUtility::drawing(40,"---");
    cout << endl;
    clsUtility::tabs(6);
    cout << "No clients to show";
    cout << endl;
    clsUtility::drawing(40,"---");
    cout << endl;
    return;
  }
  cout << "\n\t\t\t\t\tClients List (" << vClientsData.size() << ") Client(s)." << endl;
  cout << endl;
  clsUtility::drawing(40,"---");
  cout << endl;
  cout << "| " << setw(20) << left << "Account number: ";
  cout << " | " << setw(25) << left << "Client name: ";
  cout << " | " << setw(15) << left << "Phone: ";
  cout << " | " << setw(20) << left << "Email: ";
  cout << " | " << setw(15) << left << "Pin code: ";
  cout << " | " << setw(10) << left << "Balance: ";
  cout << endl;
  clsUtility::drawing(40,"---");
  cout << endl;
  for (clsBankClient &c : vClientsData)
  {
    printInfoLine(c);
  }
  clsUtility::drawing(40,"---");
  cout << endl;
}
static void printTotalBalances(){
  vector<clsBankClient> vClientsData = clientsData();
  short clientsNumber = vClientsData.size();
  if(clientsNumber == 0){
    cout << "\n\t\t\t\t\tClients List (" << vClientsData.size() << ") Client(s)." << endl;
    cout << endl;
    clsUtility::drawing(40,"---");
    cout << endl;
    clsUtility::tabs(6);
    cout << "No clients to show";
    cout << endl;
    clsUtility::drawing(40,"---");
    cout << endl;
    return;
  }
  cout << "\n\t\t\t\t\tClients List (" << vClientsData.size() << ") Client(s)." << endl;
  cout << endl;
  clsUtility::drawing(40,"---");
  cout << endl;
  cout << "| " << setw(20) << left << "Account number: ";
  cout << " | " << setw(25) << left << "Client name: ";
  cout << " | " << setw(15) << left << "Balance: ";
  cout << endl;
  clsUtility::drawing(40,"---");
  cout << endl;
  double total = 0;
  for (clsBankClient &c : vClientsData)
  {
    printShortInfoLine(c);
    total += c.getBalance();
  }
  cout << endl ;
  clsUtility::tabs(8) ;
  cout << "Total balance: " << total << endl; 
  clsUtility::drawing(40,"---");
  cout << endl;
}
static void printInfoLine(clsBankClient client){
  cout << endl;
  cout << "| " << setw(20) << left << client.getAccountNumber();//set width is like a custom function for spaces
  cout << " | " << setw(25) << left << client.fullName();
  cout << " | " << setw(15) << left << client.getPhone();
  cout << " | " << setw(20) << left << client.getEmail();
  cout << " | " << setw(15) << left << client.getPin();
  cout << " | " << setw(10) << left << client.getBalance();
  cout << endl;
}
static void printShortInfoLine(clsBankClient client){
  cout << endl;
  cout << "| " << setw(20) << left << client.getAccountNumber();//set width is like a custom function for spaces
  cout << " | " << setw(25) << left << client.fullName();
  cout << " | " << setw(15) << left << client.getBalance();
  cout << endl;
}
};