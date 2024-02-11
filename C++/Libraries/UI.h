#pragma once
#include <iostream>
#include "clsPerson.h"
#include "clsString.h"
#include "clsInputValidation.h"
#include <vector>
#include <fstream>
using namespace std;

enum enOptions {eList = 1, eNew = 2, eDelete = 3, eUpdate = 4, eFind = 5, eTransaction = 6, eUsers = 7, eOut = 8};
class clsScreen{
  public: 
  static void _Header(string title, string subtitle = ""){
    cout << "\n\t\t\t\t\t" << endl;
    clsUtility::drawing(20, "---");
    cout << endl << setw(35) << title << endl;
    if(subtitle != ""){
      cout << endl << setw(35) << subtitle << endl;
    }
    cout << "\n\t\t\t\t\t" << endl;
    clsUtility::drawing(20, "---");
    cout << endl;
  }
};

class clsClientsList : protected clsScreen{
public: 
  static void clientsList(){
    vector<clsBankClient> vClientsData = clsBankClient::clientsData();
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
      cout << "\n\t\t\t\t\t" << endl;
    string sub = to_string(clientsNumber) + " client(s)";
  _Header("Clients list", sub);
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
    clsBankClient::printInfoLine(c);
  }
  clsUtility::drawing(40,"---");
  cout << endl;
  }
};

class clsMainScreen : protected clsScreen{
  private:
  static void _backToMain(){
    char answer = clsInputValidation::readChar("Press [m] to main, any key to exit: ");
    if(clsUtility::getLowerCase(answer) == 'm'){
      mainMenue();
    }
  }
  static void _clientListScreen(){
    clsClientsList::clientsList();
  }
  static void _newClientScreen(){
    cout << "new client screen here" << endl;
  }
  static void _deleteClientScreen(){
    cout << "delete client screen here" << endl;
  }
  static void _updateClientScreen(){
    cout << "update client screen here" << endl;
  }
  static void _findClientScreen(){
    cout << "find client screen here" << endl;
  }
  static void _transScreen(){
    cout << "transactions screen here" << endl;
  }
  static void _usersScreen(){
    cout << "Manage users screen here" << endl;
  }
  static void _logoutScreen(){
    cout << "Logout screen here" << endl;
  }
  static void _performOption(short option){
    switch (option)
    {
    case enOptions::eList:
      _clientListScreen();
      _backToMain();
      break;
    case enOptions::eNew:
      _newClientScreen();
      _backToMain();
      break;
    case enOptions::eDelete:
      _deleteClientScreen();
      _backToMain();
      break;
    case enOptions::eUpdate:
      _updateClientScreen();
      _backToMain();
      break;
    case enOptions::eFind:
      _findClientScreen();
      _backToMain();
      break;
    case enOptions::eTransaction:
      _transScreen();
      _backToMain();
      break;
    case enOptions::eUsers:
      _usersScreen();
      _backToMain();
      break;
    case enOptions::eOut:
      _logoutScreen();
      _backToMain();
      break;
    
    default:
      cout << "Invalid input" << endl;
      break;
    }
  }
  public:
    static void mainMenue(){
      clsScreen::_Header("Main menue");
      cout << "\t[1] Show client list" << endl;
      cout << "\t[2] Add client" << endl;
      cout << "\t[3] Delete client" << endl;
      cout << "\t[4] Update client" << endl;
      cout << "\t[5] find client" << endl;
      cout << "\t[6] Transactions menue" << endl;
      cout << "\t[7] Manage users" << endl;
      cout << "\t[8] Logout" << endl;
      clsUtility::drawing(20, "---");
      cout << endl;
      short answer = clsInputValidation::readShortNumberBetween(1,8);
      _performOption(answer);
    }
};