#pragma once
#include<iostream>
#include<cctype>
#include<iomanip>
#include<fstream>
#include<cmath>
#include<vector>
#include"BankP.h"
#include"PSLvl-2.h"
#include"PSLvl-3.h"
//=============Declarations==============
struct stUser{
  string userName;
  string passWord;
  short permissions = 0;
  bool deleteme = false;
};
void startBankProject(stUser);
void backToMain(stUser);
void screenTitle(string title);
enum enOptions2 {eList2 = 1, eNew2 = 2, eDelete2 = 3, eUpdate2 = 4, eFind2 = 5, eTransaction2 = 6, eUsers2 = 7};
enum enUserOptions {euList = 1, euNew = 2, euDelete = 3, euUpdate = 4, euFind = 5, euMain = 6};
string Uname = "users.txt";
vector<stUser> uGetDataFromFile(string name, string sep = "//");
vector<stUser> users = uGetDataFromFile(Uname);
stUser zaher = users[0];
stUser w;
//=============Declarations==============
void givePermissions(stUser &u){
  char answer = readChar("Give full accsess?[y/n]: ");
  if(getLowerCase(answer) == 'y'){
    u.permissions = 127;
  }else{
    cout << "Give access to: \n" << endl;
    answer = readChar("Show client list?[y/n]: ");
    getLowerCase(answer) == 'y' ? u.permissions += pow(2,0) : u.permissions;
    answer = readChar("Add client?[y/n]: ");
    getLowerCase(answer) == 'y' ? u.permissions += pow(2,1) : u.permissions;
    answer = readChar("Delete client?[y/n]: ");
    getLowerCase(answer) == 'y' ? u.permissions += pow(2,2) : u.permissions;
    answer = readChar("Update client?[y/n]: ");
    getLowerCase(answer) == 'y' ? u.permissions += pow(2,3) : u.permissions;
    answer = readChar("Find client?[y/n]: ");
    getLowerCase(answer) == 'y' ? u.permissions += pow(2,4) : u.permissions;
    answer = readChar("Transactions?[y/n]: ");
    getLowerCase(answer) == 'y' ? u.permissions += pow(2,5) : u.permissions;
    answer = readChar("Manage users?[y/n]: ");
    getLowerCase(answer) == 'y' ? u.permissions += pow(2,6) : u.permissions;
  }
}
bool hasPermission(stUser u, enOptions2 option){
  return ((u.permissions & option) == option);
}
void userProfile(stUser u){
  drawing(5);
  cout << "User data";
  drawing(5);
  cout << endl;
  cout << "User name: " << u.userName << endl;
  cout << "Password: " << u.passWord << endl;
  cout << "Permissions: " << u.permissions << endl;
}
stUser readUser2(string username){
  stUser u;
  u.userName = username;
  cout << "Password: ";
  getline(cin >> ws, u.passWord);
  cout << endl;
  givePermissions(u);
  return u;
}
string uRecordToString(stUser u, string sep = "//"){
  string userInfo = u.userName + sep + u.passWord + sep + to_string(u.permissions);
  return userInfo;
}
void saveUserData(string Uname, stUser &user){
  string dataLine = uRecordToString(user);
  stringToFile(Uname, dataLine);
}
bool checkUser(string userName, vector<stUser> &users, stUser &wanted){
  for (stUser user : users)
  {
    if(user.userName == userName){
      wanted = user;
      return true;
    }
  }
  return false;
}
bool checkUser(string userName, string password, vector<stUser> &users, stUser &wanted){
  for (stUser user : users)
  {
    if(user.userName == userName && user.passWord == password){
      wanted = user;
      return true;
    }
  }
  return false;
}
bool findUser(string userName, vector<stUser> &users, stUser &wanted){
  for (stUser user : users)
  {
    if(user.userName == userName){
      wanted = user;
      userProfile(wanted);
      return true;
    }
  }
  return false;
}
void addUser(string Uname, vector<stUser> &users){
  stUser wanted;
  char cont = 'n';
  short added = 0;
  string userName = readString("User name: ");
  if(!checkUser(userName, users, wanted)){
    users.push_back(readUser2(userName));
    added++;
    saveUserData(Uname, users[users.size() - added]);
    cont = readChar("User added successfully, add more? y/n: ");
    if(getLowerCase(cont) == 'y'){
      addUser(Uname, users);
    }else{
      return;
    }
  }else{
    cout << "User Already exists " << endl;
    addUser(Uname, users);
  }
}
void printUsersList(stUser record){
  cout << "| " << record.userName << setw(15);
  cout << "| " << record.passWord << setw(15);
  cout << "| " << record.permissions << setw(15);
  cout << endl;
}
void usersMenue(){
  screenTitle("Users menue");
  cout << "[1] Show users' list" << endl;
  cout << "[2] Add user" << endl;
  cout << "[3] Delete user" << endl;
  cout << "[4] Update user" << endl;
  cout << "[5] find user" << endl;
  cout << "[6] Main menue" << endl;
  drawing(10);
  cout << endl;
}
stUser uStringToRecord(string txt, string sep = "//"){
  stUser u;
  vector<string>data = zsplit(txt, sep);
  u.userName = data.at(0);
  u.passWord = data.at(1);
  u.permissions = stoi(data.at(2));
  return u;
}
vector<stUser> uGetDataFromFile(string name, string sep){
  vector<stUser>data;
  fstream f;
  string line;
  f.open(name, ios::in);
  if(f.is_open()){
    while(getline(f, line)){
      data.push_back(uStringToRecord(line));
      // data.push_back(line);
    }
    f.close();
  }
  return data;
}
void userListHeader(){
  drawing(17, "======");
  cout << endl;
  cout << "| User name" << setw(15);
  cout << setw(15) << "| Password";
  cout << setw(15) << "| Permissions";
  cout << endl;
  drawing(17, "======");
  cout << endl;
}
void totalUsersData(vector<stUser>data){
  userListHeader();
  short c = 1;
  for (stUser &user : data)
  {
    cout << "\n+++++++User" << c << "+++++++\n";
    printUsersList(user);
    c++;
  }
}
void uDeletionLogic(string Uname, stUser &wanted, vector<stUser>&users){
  char answer = readChar("Delete user? y/n: ");
  bool success = false;
  if(getLowerCase(answer) == 'y'){
    for (stUser &user : users)
    {
      if(wanted.userName == "zaher"){
        cout << "Cannot delete the main user\n";
        break;
      }
      if(user.userName == wanted.userName){
        if(user.passWord == wanted.passWord){
          user.deleteme = true;
          success = true;
          break;
        }else{
          cout << "Wrong password\n";
          break;
        }
      }
    }
    fstream f;
    string dataLine;
    f.open(Uname, ios::out);
    if(f.is_open()){
      for (stUser user : users)
      {
        if(user.deleteme == false){
          f << uRecordToString(user) << endl;
        }
      }
    }
    f.close();
    users = uGetDataFromFile(Uname);
    if(success){
      cout << "Deleted successfully" << endl;
    }
  }
}
void deleteUser(string Uname, string username, string password, stUser &wanted, vector<stUser>&users){
  if(findUser(username, users, wanted)){
    userProfile(wanted);
    wanted.passWord = password;
    uDeletionLogic(Uname, wanted, users);
  }else{
    cout << "Not found :(" << endl;
  }
}
void Uupdate(stUser &wanted){
  cout << "Username: " << endl;
  getline(cin >> ws, wanted.userName);
  cout << "Password: " << endl;
  getline(cin, wanted.passWord);
  givePermissions(wanted);
}
void updateUserLogic(string Uname, stUser &wanted, vector<stUser>&users){
  char answer = readChar("Update user's data? y/n: ");
  if(getLowerCase(answer) == 'y'){
    for (stUser &user : users)
    {
      if(user.userName == wanted.userName){
        Uupdate(user);
        break;
      }
    }
    fstream f;
    string dataLine;
    f.open(Uname, ios::out);
    if(f.is_open()){
      for (stUser &user : users)
      {
        f << uRecordToString(user) << endl;
      }
    }
    f.close();
    users = uGetDataFromFile(Uname);
    cout << "Updated successfully" << endl;
  }
}
void updateUser(string Uname, string username, stUser &wanted, vector<stUser>&users){
  if(findUser(username, users, wanted)){
    userProfile(wanted);
    updateUserLogic(Uname, wanted, users);
  }else{
    cout << "Not found :(" << endl;
  }
}

// ===========main control here
string username;
string password;
void usersOption(stUser ur){
  usersMenue();
  short answer = readPositiveNumber("Your action [1 -> 6]: ");
  switch (answer)
  {
  case enUserOptions::euList:
    totalUsersData(users);
    backToMain(ur);
    break;
  case enUserOptions::euNew:
    addUser(Uname, users);
    backToMain(ur);
    break;
  case enUserOptions::euDelete:
    username = readString("Username: ");
    password = readString("Password: ");
    deleteUser(Uname, username, password, w, users);
    backToMain(ur);
    break;
  case enUserOptions::euUpdate:
    username = readString("Username: ");
    updateUser(Uname, username, w, users);
    backToMain(ur);
    break;
  case enUserOptions::euFind:
    username = readString("Username: ");
    findUser(username, users, w);
    backToMain(ur);
    break;
  case enUserOptions::euMain:
    startBankProject(ur);
    break;
    default:
    cout << "Wrong answer" << endl;
    break;
  }
}
void login(){
  char exit = readChar("Press [l] to login or any key to exit: ");
  if(getLowerCase(exit) == 'l'){
    screenTitle("Login: ");
    cout << endl;
    string username = readString("User name: ");
    string password = readString("password: ");
    stUser wanted; 
    if(checkUser(username, password, users, wanted)){
        cout << "Logged in successfully\n";
        startBankProject(wanted);
    }else{
      cout << "Username or password wrong" << endl;
      login();
    }
  }else{
    return;
  }
}