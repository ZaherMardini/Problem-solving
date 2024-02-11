#pragma once
#include<iostream>
#include<vector>
using namespace std;
class clsString{
  private:
  string _str;
  public:
  clsString(string str){
    _str = str;
  }
  clsString(){
    _str = "";
  }
  void setString(string str){
    _str = str;
  }
  string getString(){
    return _str;
  }
  //=========Begin=========
  static void firstLetterInString(string txt){
    bool firstAhead = true;
    for (short i = 0; i < size(txt); i++)
    {
      if(txt[i] != ' ' && firstAhead){
        cout << txt[i] << endl;
      }
      firstAhead = (txt[i] == ' ' ? true : false);
    }
  }
  void firstLetterInString(){
    firstLetterInString(_str);
  }
  static char getUpperCase(char &letter){
    return char(toupper(letter));
  }
  //===========start testing from here
  static char getLowerCase(char &letter){
    return char(tolower(letter));
  }
  static void capitalizeEachWord(string txt){
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
  void capitalizeEachWord(){
    capitalizeEachWord(_str);
  }
  static void lowerCaseEachWord(string txt){
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
  void lowerCaseEachWord(){
    lowerCaseEachWord(_str);
  }
  static void lowerOrUpperAll(string txt, bool lu = 1){
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
  void lowerOrUpperAll(){
    lowerOrUpperAll(_str);
  }
  static char invertCharCase(char &c){
    return isupper(c) ? getLowerCase(c) : getUpperCase(c);
  }
  static void invertCase(string txt){
    for (short i = 0; i < txt.length(); i++)
    {
      cout << invertCharCase(txt[i]);
    }
  }
  void invertCase(){
    invertCase(_str);
  }
  static void countLetters(string txt){
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
  void countLetters(){
    countLetters(_str);
  }
  static short letterCount(string txt, char c){
    short count = 0;
    for (short i = 0; i < txt.length(); i++)
    {
      for (short i = 0; i < txt.length(); i++){
        txt[i] == c ? count++ : count;
      }
    }
    return count;
  }
  static short letterCount2(string txt, char c, bool match = true){
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
  static bool isVowel(char c){
    c = getLowerCase(c);
    return (c == 'a' || c == 'i' || c == 'o' || c == 'u' || c == 'e');
  }
  static short vowelsCount(string txt){
    short count = 0;
    for (short i = 0; i < txt.length(); i++)
    {
      isVowel(txt[i]) ? count++ : count;
    }
    return count;
  }
  short vowelsCount(){
    return vowelsCount(_str);
  }
  static void printVowels(string txt){
    for (short i = 0; i < txt.length(); i++)
    {
      if(isVowel(txt[i])){
        cout << txt[i] << " ";
      }
    }
  }
  void printVowels(){
    printVowels(_str);
  }
  static void printWords(string txt){
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
  void printWords(){
    printWords(_str);
  }
  static short wordCount(string txt){
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
  short wordCount(){
    return wordCount(_str);
  }
  static vector<string>split(string txt, string delimiter = " "){
    short pos = 0;
    vector<string> vtokens;
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
  static void printVector(vector<string>v){
    for (short i = 0; i < v.size(); i++)
    {
      cout << v.at(i) << endl;
    }
  }
  static string trimLeft(string txt){
    short pos = 0;
    while(txt[pos] == ' '){//'/' for testing
      pos++;
    }
    txt.erase(0, pos);
    return txt;
  }
  string trimLeft(){
    return trimLeft(_str);
  }
  static string trimRight(string txt){
    short pos = 0;
    short size = txt.length() - 1;
    while(txt[txt.length()-1-pos] == ' '){//'/' for testing
      pos++;
    }
    txt.erase(size-pos+1, txt.length());
    return txt;
  }
  string trimRight(){
    return trimRight(_str);
  }
  static string ztrim(string txt){
    return trimLeft(trimRight(txt));// cool
  }
  string ztrim(){
    return ztrim(_str);
  }
  static string zjoin(vector<string> v, string delimiter = " "){
    string joined = "";
    for (short i = 0; i < v.size(); i++)
    {
      joined += v.at(i) + delimiter;
    }
    return joined.substr(0, joined.length() - delimiter.length());
  }
  static string zjoin(string a[50], int size, string delimiter = " "){
    string joined = "";
    for (short i = 0; i < size; i++)
    {
      joined += a[i] + delimiter;
    }
    return joined.substr(0, joined.length() - delimiter.length());
  }
  static string printReversedWrods(string txt){
    vector<string>v = split(txt);
    vector<string>::iterator itr = v.end();
    string rev = "";
    while(itr != v.begin()){
      --itr;
      rev += *itr + " ";
    }
    return trimRight(rev);
  }
  string printReversedWrods(){
    return printReversedWrods(_str);
  }
  static string nreplace(string txt, string origin, string alternative){
    short pos = txt.find(origin);
    while(pos != string::npos){
      txt = txt.replace(pos, origin.length(), alternative);
      pos = txt.find(origin);
    }
    return txt;
  }
  static string sUpper(string word){
    word[0] = getUpperCase(word[0]);
    return word;
  }
  string sUpper(){
    return sUpper(_str);
  }
  static string stLower(string word){
    word[0] = getLowerCase(word[0]);
    return word;
  }
  string stLower(){
    return stLower(_str);
  }
  string zreplace(string txt, string origin, string alternative, bool match = 1){
    vector<string>v = split(txt);
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
  static string removePunc(string txt){
    for (short i = 0; i < txt.length(); i++)
    {
      if(ispunct(txt[i])){
        txt.erase(i,1);
      }
    }
    return txt;
  }
  string removePunc(){
    return removePunc(_str);
  }

};
