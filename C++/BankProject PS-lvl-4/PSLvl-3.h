#pragma once
#include<iostream>
#include<cctype>
#include<iomanip>
#include<fstream>
#include<cmath>
#include<vector>
#include"PSLvl-2.h"
using namespace std;

//=============Declarations==============
struct stClient{
  string Anumber;
  string name;    
  string pin;
  string phone;
  int balance;
  bool deleteme = false;
};
void addClient(string name, vector<stClient> &record);
void drawing(short num, string sh = "----");
void tabs(short num);
void saveClientData(string name, stClient &client);
stClient readClient2(string Anumber);
stClient readClient();
//=============Declarations==============

//================ Begin ================
// Problem #1
//A Matrix is at least a two dimentional array
void fillMatrixWithRandoms(int matrix[3][3], int &rows, int &columns){
  for (int i = 0; i < rows; i++){
    for (int j = 0; j < columns; j++){
      matrix[i][j] = randomNumber(0,10);
    }
  }
}
void printMatrix(int matrix[3][3], int &rows, int &columns){
  for (int i = 0; i < rows; i++){
    for (int j = 0; j < columns; j++){
      //printf("%0*d", 2 ,matrix[i][j]);
      cout << setw(5) << matrix[i][j];
      if(j == columns-1){
        cout << endl;
      }
    }
  }
  cout << endl;
}
void printMatrixInReverse(int matrix[3][3], int rows, int columns){
  for (int i = 0; i < rows; i++){
    for (int j = columns - 1; j >= 0; j--){
      //printf("%0*d", 2 ,matrix[i][j]);
      cout << setw(5) << matrix[i][j];
      if(j == 0){
        cout << endl;
      }
    }
  }
  cout << endl;
}
// Problem #1

// Problem #2
int rowSum(int matrix[3][3], int &rows, int &columns){
  int sum = 0;
    for (short j = 0; j < columns; j++){
      sum += matrix[rows][j];
    }  
  return sum;
}
void sumOfRowsInMatrix(int matrix[3][3], int &rows, int &columns){
  for (int i = 0; i < rows; i++)
  {
    cout << "Sum of row" << i+1 << " :"; 
    cout << setw(5) << rowSum(matrix, i, columns) << endl;
    //give me the sum of row number i, the columns are boundries
  }
}
// Problem #2

// Problem #3
void AddMatrixElement(int number, int matrix[3][3], int &rows, int &columns){
  matrix[--rows][--columns] = number;
}
void sumOfRowsInMatrixToArray(int matrix[3][3], int &rows, int &columns, int result[3]){
  for (int i = 0; i < rows; i++){
    result[i] = rowSum(matrix, i, columns);
  }
}
// Problem #3

// Problem #4
int colSum(int matrix[3][3], int &rows, int &columns){
  int sum = 0;
  for (short i = 0; i < rows; i++){
    sum += matrix[i][columns];
  }
  return sum;
}
void sumOfColumnsInMatrix(int matrix[3][3], int &rows, int &columns){
  int sum = 0;
  for (int i = 0; i < rows; i++){
    cout << "Sum of column" << i+1 << " :";  
    cout << setw(3) << colSum(matrix, rows, i) << endl;
    //give me the sum of column number i, the rows are boundries
  }
}
// Problem #4

// Problem #5
void sumOfColumnsInMatrixToArray(int matrix[3][3], int &rows, int &columns, int result[3]){
  for (int i = 0; i < columns; i++){
    result[i] = colSum(matrix, rows, i);
  }
}
// Problem #6
void fillMatrixWithOrderedNums(int matrix[3][3], int &rows, int &columns){
  short counter = 0;
  for (short i = 0; i < rows; i++)
  {
    for (short j = 0; j < columns; j++)
    {
      matrix[i][j] = counter + 1;
      counter++;
    }
  }
}
// Problem #6

// Problem #7
void transposeMatrix(int origin[3][3], int trans[3][3], int &rows, int &columns){
  for (short i = 0; i < rows; i++)
  {
    for (short j = 0; j < columns; j++)
    {
      trans[j][i] = origin[i][j];
    }
  }
}
// Problem #7

// Problem #8
void multiplyMatricies(int first[3][3], int second[3][3],int result[3][3], int &rows, int &columns){
  for (short i = 0; i < rows; i++){
    for (short j = 0; j < columns; j++){
      result[i][j] = first[i][j] * second[i][j];
    }
  }
}
// Problem #8

// Problem #9
void printMidRowCol(int matrix[3][3], int &rows, int &columns){
  int mr[3];
  int mc[3];
  int midr = rows / 2;
  int midc = columns / 2;
  for (short i = 0; i < rows; i++)
  {
    mc[i] = matrix[i][midc];
    mr[i] = matrix[midr][i];
  }
  cout << "Mid column: \n";
  printArray(mc, 3);
  cout << "Mid row: \n";
  printArray(mr, 3);
} 
// Problem #9

// Problem #10
int sumMatrix(int matrix[3][3], int &rows, int &columns){
  int sum = 0;
  for (short i = 0; i < rows; i++){
    for (short j = 0; j < columns; j++){
      sum += matrix[i][j];
    }
  }
  // cout << "sum of matrix is: " << sum;
  return sum;
}
// Problem #10

// Problem #11
bool areEqual(int m1[3][3], int m2[3][3], int &rows, int &columns){
  return sumMatrix(m1, rows, columns) == sumMatrix(m2, rows, columns);
}
// Problem #11

// Problem #12
bool areTypical(int m1[3][3], int m2[3][3], int &rows, int &columns){
    for (short i = 0; i < rows; i++){
      for (short j = 0; j < columns; j++){
        if(m1[i][j] != m2[i][j]){
          return false;
        };
      }
    }
  return true;
}
// Problem #12

// Problem #13
bool isIdentity(int m[3][3], int &rows, int &columns){
  for (short i = 0; i < rows; i++){
    for (short j = 0; j < columns; j++){
      if((i==j && m[i][j] != 1) || (i != j && m[i][j] != 0)){
        return false;
      }
    }
  }
  return true;
}
// Problem #13

// Problem #14
bool isScalar(int m[3][3], int &rows, int &columns){
  for (short i = 0; i < rows; i++){
    for (short j = 0; j < columns; j++){
      if((i==j && m[i][j] != m[0][0]) || (i != j && m[i][j] != 0)){
        return false;
      }
    }
  }
  return true;
}
// Problem #14

// Problem #15
short mNumberCount(int num, int m[3][3], int &rows, int &columns){
  short count = 0;
  for (short i = 0; i < rows; i++){
    for (short j = 0; j < columns; j++){
      if(m[i][j] == num){
        count++;
      }
    }
  }
  cout << num << " is repeated: " << count << " times" << endl;
  return count;
}
// Problem #15  

// Problem #16 
// simple but tricky :) 
// zeros have to be more than half members
// total members are represented by the size of the matrix
bool isSparce(int m[3][3], int &rows, int &columns){
  short zeros = mNumberCount(0, m, rows, columns);
  short mSize = rows*columns;
  return zeros > mSize/2;
}
// Problem #16

// Problem #17
// don't use count function for better performance
bool mIsfound(int target, int m[3][3], int &rows, int &columns){
  for (short i = 0; i < rows; i++){
    for (short j = 0; j < columns; j++){
      if(m[i][j] == target){
        return true;
      }
    }
  }
  return false;
}
// Problem #17

// Problem #18
void intersected(int m1[3][3], int m2[3][3], int &rows, int &columns){
  cout << "Intersected numbers are: " << endl;
  for (short i = 0; i < rows; i++){
    for (short j = 0; j < columns; j++){
      if(mIsfound(m1[i][j], m2, rows, columns)){
        cout << setw(5) << m1[i][j];
      }
    }
  }
}
// Problem #18

// Problem #19
void minMaxMatrix(int m[3][3],int &rows, int &columns){
  int min = m[0][0];
  int max = min;
  for (short i = 0; i < rows; i++){
    for (short j = 0; j < columns; j++){
      if(m[i][j] < min){
        min = m[i][j];
      }else if(m[i][j] > max){
        max = m[i][j];
      }
    }
  }
  cout << "Max is: " << max << endl;
  cout << "Min is: " << min << endl;
}
// Problem #19

// Problem #20 
// Go only half way with columns
bool mIsPalindrome(int matrix[3][3], int &rows, int &columns){
  for (int i = 0; i < rows; i++){
    for (int j = 0; j < columns/2; j++){
      if(matrix[i][j] != matrix[i][columns - 1 -j]){
        return false;
      }
    }
  }
  return true;
}
// Problem #20

// Problem #21

void fip(short reps){
  int n1 = 1;//  1 1 2 3 5 8 13 21 34 55 => 10 reps
  int n0 = 0;
  int fib;
  for (short i = 1; i <= reps; i++){
    fib = n1 + n0;
    cout << setw(3) << fib;
    n1 = n0;
    n0 = fib;
  }
}
// Problem #21

// Problem #22
void fip2(short reps, short n1 = 1, short n2 = 0){
  if(reps > 0){
    short fib;
    fib = n1 + n2;
    n1 = n2; 
    n2 = fib;
    cout << setw(3) << fib;
    fip2(reps - 1, n1, fib);
  }
}
// Problem #22

// Problem #23
void firstLetterInString(string txt){
  bool firstAhead = true;
  for (short i = 0; i < size(txt); i++)
  {
    if(txt[i] != ' ' && firstAhead){
      cout << txt[i + 1] << endl;
    }
    firstAhead = (txt[i] == ' ' ? true : false);
  }
}
// Problem #23

// Problem #24
char getUpperCase(char &word){
  return char(toupper(word));
}

void capitalizeEachWord(string txt){
  cout << getUpperCase(txt[0]);
  for (short i = 1; i < size(txt); i++)
  {
    if(txt[i] == ' '){
      cout << txt[i] << getUpperCase(txt[i+1]);
      i++;
      continue;
    }
    cout << txt[i];
  }
}
// Problem #24

// Problem #25
char getLowerCase(char &word){
  return char(tolower(word));
}
void lowerCaseEachWord(string txt){
  cout << getLowerCase(txt[0]);
  for (short i = 1; i < size(txt); i++)
  {
    if(txt[i] == ' '){
      cout << txt[i] << getLowerCase(txt[i+1]);
      i++;
      continue;
    }
    cout << txt[i];
  }
}
// Problem #25

// Problem #26
void lowerUpperAll(string txt, bool lu = 1){
  if(lu){
    for (short i = 0; i < txt.length(); i++)
    {
      cout << getLowerCase(txt[i]) ;
    }
  }else{
    for (short i = 0; i < txt.length(); i++)
    {
      cout << getUpperCase(txt[i]) ;
    }
  }
}
// Problem #26

// Problem #27
char invertChar(char &c){
  return isupper(c) ? getLowerCase(c) : getUpperCase(c);
}
// Problem #27

// Problem #28
void invertCase(string txt){
  for (short i = 0; i < txt.length(); i++)
  {
    cout << invertChar(txt[i]);
  }
}
// Problem #28

// Problem #29
void countLetters(string txt){
  short s = 0;
  short c = 0;
  for (short i = 0; i < txt.length(); i++)
  {
    if(int(txt[i]) >= 97 && int(txt[i]) <= 120){
      s++;
    }else if(int(txt[i]) >= 65 && int(txt[i]) <= 90){
      c++;
    }
  }
  cout << "String length: " << txt.length() << endl;
  cout << "Total letters: " << c + s << endl;
  cout << "Small letters: " << s << endl;
  cout << "Capital letters: " << c << endl;
}
// Problem #29

// Problem #30
short charCount(string txt, char c){
  short count = 0;
  for (short i = 0; i < txt.length(); i++)
  {
    for (short i = 0; i < txt.length(); i++){
      txt[i] == c ? count++ : count;
    }
  }
  return count;
}
// Problem #30

// Problem #31
short charCount2(string txt, char c, bool match = true){
  short count = 0;
  if(match){
    for (short i = 0; i < txt.length(); i++){
      txt[i] == getUpperCase(c) || txt[i] == getLowerCase(c) ? count++ : count;
    }
  }else{
    for (short i = 0; i < txt.length(); i++){
      txt[i] == c ? count++ : count;
    }
  }
return count;
}
// Problem #31

// Problem #32
bool isVowel(char c){
  c = getLowerCase(c);
  return (c == 'a' || c == 'i' || c == 'o' || c == 'u' || c == 'e');
}
// Problem #32

// Problem #33
short vowelsCount(string txt){
  short count = 0;
  for (short i = 0; i < txt.length(); i++)
  {
    isVowel(txt[i]) ? count++ : count;
  }
  return count;
}
// Problem #33

// Problem #34
void printVowels(string txt){
  for (short i = 0; i < txt.length(); i++)
  {
    if(isVowel(txt[i])){
      cout << txt[i] << " ";
    }
  }
}
// Problem #34

// Problem #35
void printWords(string txt){
  string delimiter = " ";
  short pos = 0;
  string word = "";
  while((pos = txt.find(delimiter)) != string::npos){
    word = txt.substr(0, pos);
    if(word != ""){
      cout << word << endl;
    }
    txt.erase(0, pos + delimiter.length());
  }
  if(txt != ""){
    cout << txt << endl;
  }
}
// Problem #35

// Problem #36
short wordCount(string txt){
  string delimiter = " ";
  short count = 0;
  short pos = 0;
  string word = "";
  while((pos = txt.find(delimiter)) != string::npos){
    word = txt.substr(0, pos);
    if(word != ""){
      count++;
    }
    txt.erase(0, pos + delimiter.length());
  }
  if(txt != ""){
    count++;
  }
  return count;
}
// Problem #36

// Problem #37
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
void printVector(vector<string>v){
  for (short i = 0; i < v.size(); i++)
  {
    cout << v.at(i) << endl;
  }
}
// Problem #37

// Problem #38
string trimLeft(string txt){
  short pos = 0;
  while(txt[pos] == ' '){//'/' for testing
    pos++;
  }
  txt.erase(0, pos);
  return txt;
}
string trimRight(string txt){
  short pos = 0;
  short size = txt.length() - 1;
  while(txt[txt.length()-1-pos] == ' '){//'/' for testing
    pos++;
  }
  txt.erase(size-pos+1, txt.length());
  return txt;
}
string ztrim(string txt){
  return trimLeft(trimRight(txt));// cool
}
// Problem #38

// Problem #39
string zjoin(vector<string> v, string delimiter = " "){
  string joined = "";
  for (short i = 0; i < v.size(); i++)
  {
    joined += v.at(i) + delimiter;
  }
  return joined.substr(0, joined.length() - delimiter.length());
}
// Problem #39

// Problem #40
string zjoin(string a[50], int size, string delimiter = " "){
  string joined = "";
  for (short i = 0; i < size; i++)
  {
    joined += a[i] + delimiter;
  }
  return joined.substr(0, joined.length() - delimiter.length());
}
// Problem #40

// Problem #41
string printReversedWrods(string txt){
  vector<string>v = zsplit(txt);
  vector<string>::iterator itr = v.end();
  string rev = "";
  while(itr != v.begin()){
    --itr;
    rev += *itr + " ";
  }
  return trimRight(rev);
}
// Problem #41

// Problem #42
string nreplace(string txt, string origin, string alternative){
  short pos = txt.find(origin);
  while(pos != string::npos){
    txt = txt.replace(pos, origin.length(), alternative);
    pos = txt.find(origin);
  }
  return txt;
} 
// Problem #42

// Problem #43
string sUpper(string word){
  word[0] = getUpperCase(word[0]);
  return word;
}
string stLower(string word){
  word[0] = getLowerCase(word[0]);
  return word;
}
string zreplace(string txt, string origin, string alternative, bool match = 1){
  vector<string>v = zsplit(txt);
  for (short i = 0; i < v.size(); i++){
    if(match){
      origin = stLower(origin);
      v.at(i) = stLower(v.at(i));
    }if(v.at(i) == origin){
      v.at(i) = alternative;
    }
  }
  return zjoin(v);
}
// Problem #43

// Problem #44
string removePunc(string txt){
  for (short i = 0; i < txt.length(); i++)
  {
    if(ispunct(txt[i])){
      txt.erase(i,1);
    }
  }
  return txt;
}
// Problem #44

// Problem #45
stClient readClient(){
  stClient c;
  cout << "Account number: " << endl;
  getline(cin >> ws, c.Anumber);
  cout << "Name: " << endl;
  getline(cin, c.name);
  cout << "Pin code: " << endl;
  getline(cin, c.pin);
  cout << "Phone number: " << endl;
  getline(cin, c.phone);
  cout << "Balance: " << endl;
  cin >> c.balance;
  return c;
}
stClient readClient2(string Anumber){
  stClient c;
  c.Anumber = Anumber;
  cout << "Name: " << endl;
  getline(cin >> ws , c.name);
  cout << "Pin code: " << endl;
  getline(cin >> ws, c.pin);
  cout << "Phone number: " << endl;
  getline(cin, c.phone);
  cout << "Balance: " << endl;
  cin >> c.balance;
  return c;
}
string recordToString(stClient c, string sep = "//"){
  string banckInfo = c.Anumber + sep + c.name + sep + c.pin + sep + c.phone + sep + to_string(c.balance);
  return banckInfo;
}
// Problem #45

// Problem #46
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
// Problem #46

// Problem #47
void stringToFile(string name, string line, string sep = "//"){
  fstream f;
  f.open(name, ios::out | ios::app);
  if(f.is_open()){
    f << line << endl;
    f.close();
  }
}
void overwriteToFile(string name, string line, string sep = "//"){
  fstream f;
  f.open(name, ios::out);
  if(f.is_open()){
    f << line << endl;
    f.close();
  }
}
void saveClientData(string name, stClient &client){
  string dataLine = recordToString(client);
  stringToFile(name, dataLine);
}
void overwriteClientData(string name, stClient &client){
  string dataLine = recordToString(client);
  overwriteToFile(name, dataLine);
}
void addDataToFolder(string name, vector<stClient>&clients){
  char cont = 'y';
  string Anumber;
  do{
    cout << "======Add clients======" << endl;
    Anumber = readString("Account number: ");
    addClient(name, clients);
    // saveClientData(name);
    cout << "Continue? y/n: ";
    cin >> cont;
  }while(getLowerCase(cont) == 'y');
}
// Problem #47

// Problem #48
vector<stClient> getDataFromFile(string name, string sep = "//"){
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
void printClientsList(stClient record){
  cout << "| " << record.Anumber << setw(15);
  cout << "| " << record.name << setw(15);
  cout << "| " << record.pin << setw(15);
  cout << "| " << record.phone << setw(15);
  cout << "| " << record.balance << setw(15);
  cout << endl;
}
void listHeader(){
  drawing(17, "======");
  cout << endl;
  cout << "| Account number" << setw(15);
  cout << setw(15) << "| Client name";
  cout << setw(15) << "| Pin code";
  cout << setw(15) << "| Phone number";
  cout << setw(15) << "| Balance";
  cout << endl;
  drawing(17, "======");
  cout << endl;
}
void totalClientsData(vector<stClient>data){
  listHeader();
  short c = 1;
  for (stClient &client : data)
  {
    cout << "\n+++++++Client" << c << "+++++++\n";
    printClientsList(client);
    c++;
  }
}
// Problem #48

// Problem #49
bool findClient(string Anumber, vector<stClient> &clients, stClient &wanted){
  for (stClient client : clients)
  {
    if(client.Anumber == Anumber){
      wanted = client;
      clientProfile(wanted);
      return true;
    }
  }
  return false;
}
// Problem #49

// Problem #50
void deletionLogic(string name, stClient &wanted, vector<stClient>&clients){
  char answer = readChar("Delete client? y/n: ");
  if(getLowerCase(answer) == 'y'){
    for (stClient &client : clients)
    {
      if(client.Anumber == wanted.Anumber){
        client.deleteme = true;
      }
    }
    fstream f;
    string dataLine;
    f.open(name, ios::out);
    if(f.is_open()){
      for (stClient client : clients)
      {
        if(client.deleteme == false){
          f << recordToString(client) << endl;
        }
      }
    }
    f.close();
    clients = getDataFromFile(name);
    cout << "Deleted successfully" << endl;
  }
}
void deleteClient(string name, string Anumber, stClient &wanted, vector<stClient>&records){
  if(findClient(Anumber, records, wanted)){
    clientProfile(wanted);
    deletionLogic(name, wanted, records);
  }else{
    cout << "Not found :(" << endl;
  }
}
// Problem #50

// Problem #51
void update(stClient &wanted){
  cout << "Name: " << endl;
  getline(cin >> ws, wanted.name);
  cout << "Pin code: " << endl;
  getline(cin, wanted.pin);
  cout << "Phone number: " << endl;
  getline(cin, wanted.phone);
  cout << "Balance: " << endl;
  cin >> wanted.balance;
}
void deletion(string name, stClient &wanted, vector<stClient>&clients){
    for (stClient &client : clients)
    {
      if(client.Anumber == wanted.Anumber){
        client.deleteme = true;
        break;
      }
    }
    fstream f;
    string dataLine;
    f.open(name, ios::out);
    if(f.is_open()){
      for (stClient client : clients)
      {
        if(client.deleteme == false){
          f << recordToString(client) << endl;
        }
      }
    }
    f.close();
    clients = getDataFromFile(name);
  }
void updateLogic(string name, stClient &wanted, vector<stClient>&clients){
  char answer = readChar("Update client's data? y/n: ");
  if(getLowerCase(answer) == 'y'){
    for (stClient &client : clients)
    {
      if(client.Anumber == wanted.Anumber){
        update(client);
        break;
      }
    }
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
    cout << "Updated successfully" << endl;
  }
}
void updateClient(string name, string Anumber, stClient &wanted, vector<stClient>&records){
  if(findClient(Anumber, records, wanted)){
    clientProfile(wanted);
    updateLogic(name, wanted, records);
  }else{
    cout << "Not found :(" << endl;
  }
}
// Problem #51