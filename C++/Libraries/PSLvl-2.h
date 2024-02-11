#pragma once
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
//================ Begin ================
//Global
string readString(string msg = "Enter a text: "){
  cout << msg;
  string t;
  getline(cin >> ws, t);
  return t;
}
float getFractionPart(float num){
  return num - int(num);
}
bool isOdd(int num){
  return num % 2 != 0;
}
bool isPositive(float num){
  return num >= 0;
}
void swap(int &a, int &b){
  int temp = a;
  a = b;
  b = temp;
}
int readNumber(string msg = "Enter a positive number: "){
  int number = 0;
  cin >> number;
  return number;
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
float readfloatNumber(string msg = "Enter a positive number: "){
  float number = 0;
  cout << msg;
  cin >> number;
  return number;
}
bool isPrime(int num){
  if(num <= 1){
    return false;
  }
  for(int i = 2; i*i <= num; i++){
    if(num % i == 0 ){
      return false;
    }
  }
  return true;
}
//Global

//Problem #1
void header(){
  for(int i = 0; i <= 10; i++){
    if(i == 0){
      continue;
    }else if(i==1){
    cout << setw(12) << i;
    }
    else{
    cout << setw(6) << i;
    }
  }
  cout << endl;
  for(int i = 0; i <= 70; i++){
    cout << "_";
  }
  cout << endl;
}
void printTable(){
  for(int i = 0; i < 10; i++){
      cout<< setw(3) << i+1 << setw(3)  << "|";
    for(int j = 0; j < 10; j++){
      cout << setw(6) << (i+1)*(j+1);
      if(j+1 == 10){
        cout << endl;
      }
    }
  }
}
//Problem #1

//Problem #2
void primeNumbers(int num){
  for(int i = 1; i <= num; i++){
    if(isPrime(i)){
      cout << "\t" << i << "\t";
    }
  }
}
//Problem #2

//Problem #3
bool isPerfect(int num){
  int result = 0;
  for(int i = 1; i < num; i++){
    if(num % i == 0){
      result += i;
    }
  }
  return result == num;
}
//Problem #3

//Problem #4
void perfectNumbers(int num){
  for(int i = 1; i <= num; i++){
    if(isPerfect(i)){
      cout << i << endl;
    }
  }
}
//Problem #4

//Problem #5
void reverseDigits(int digits){
  int remainder = 0;
  while(digits > 0){
    remainder = digits % 10;
    digits = digits / 10;
    cout << remainder << endl;
  }
}
int reverseDigits2(int digits){//123 => 3 , 32 , 321
  int remainder = 0;
  int result = 0;
  while(digits > 0){
    remainder = digits % 10;
    digits = digits / 10;
    result = result * 10 + remainder;
  }
  return result;
}
//Problem #5

//Problem #6
int sumOfDigits(int d){
  int result = 0;
  int remainder = 0;
  while(d > 0){
    remainder = d % 10;
    result += remainder;
    d = d / 10;
  }
  return result;
}
//Problem #6

//Problem #7
int repetitionOfDigit(int number, short digit){
  int freq = 0;
  int remainder = 0;
  while(number > 0){
    remainder = number % 10;
    if(remainder == digit){
      freq++;
    }
    number = number / 10;
  }
  cout << digit << " is repeated: " << freq << " time(s)";
  return freq;
}
//Problem #7

//Problem #8

//Problem #8

//Problem #9
void totalRepetitionOfDigit(int num){
  int duplicate = 0;
  for(int i = 0; i <= 10; i++){
    duplicate = repetitionOfDigit(num, i);
    if(duplicate > 0){
      cout << i << " was repeated: " << duplicate << " time(s)\n";
    }
  }
};
//Problem #9

//Problem #10
void printInOrder(int num){
  int rem = 0;
  while(num > 0){
    rem = num % 10;
    num = num / 10;
    cout << rem << endl;
  }
}
//Problem #10

//Problem #11
bool isPalindrome(int num = 0){
  return reverseDigits2(num) == num;
}
//Problem #11

//Problem #12
void descendingPattern(int num){
  for(int i = num; i > 0; i--){
    for(int j = i; j > 0; j-- ){
      cout << i;
    }
    cout << endl;
  }
}
// the first loop is for rows, second for columns
// the descending or ascending order is detected by the first loop
//Problem #12

//Problem #13
void ascendingPattern(int num){
  for(int i = 1; i <= num; i++){
    for(int j = i; j > 0; j-- ){
      cout << i;
    }
    cout << endl;
  }
}
//Problem #13

//Problem #14
void descendingLettersPattern(int num){
  for(int i = num + 64; i >= 65; i--){
      //instructor intervals: j=1; j<=num-(num+64-i)
    for(int j = i; j >= 65; j-- ){
      cout << char(i);
    }
    cout << endl;
  }
  //A->Z in ASCII is 65->90 || a->z in ASCII is 97->122
}
//Problem #14

//Problem #15
void ascendingLettersPattern(int num){
  for(int i = 65; i < 65 + num; i++){
    for(int j = i; j >= 65; j-- ){
      cout << char(i);
    }
    cout << endl;
  }
}
//Problem #15

//Problem #16
void lettersPossibilities(){
  for(int i = 65; i <= 90; i++){
    for(int j = 65; j <= 90; j++){
      for(int k = 65; k <= 90; k++){
        cout << char(i) << char(j) << char(k) << endl;
      }
    }
  }
}
//Problem #16

//Problem #17
bool guessWordOf3Characters(){
  string pw;
  cout << "Enter 3-character word all capital: ";
  cin >> pw;
  string word = "";
  int tries = 0;
  for(int i = 65; i <= 90; i++){
    for(int j = 65; j <= 90; j++){
      for(int k = 65; k <= 90; k++){
        word = word + char(i);
        word = word + char(j);
        word = word + char(k);
        tries++;
        if(word == pw){
          cout << endl << word << "  found after " << tries << " trie(s)";
          return true;
        }
        cout << word << endl;
        word = "";
      }
    }
  }
  cout << "Not found\n";
  return false;
}
//Problem #17

//Problem #18
string encryptDecryptText(){
  string txt;
  bool encryption;
  cout << "Enter a text: ";
  cin >> txt;
  cout << "For encryption type 1, for decryption type 0: ";
  cin >> encryption;
  if(encryption){
    string encText = "";
    for(int i = 0; i < size(txt); i++){
      encText += char(txt[i]+2);
    }
    cout << "Text after encryption: " << encText << endl;
    return encText;
  }else{
    string decText = "";
    for(int i = 0; i < size(txt); i++){
      decText += char(txt[i] - 2);
    }    
    cout << "Text after decryption: " << decText << endl;
    return decText;
  }
}
//Problem #18

//Problem #19
int randomNumber(int from, int to){
  int result = rand() % (to - from + 1) + from;
  return result;
  //when using rand() function put
  //this in the main() function one time only: srand((unsigned)time(NULL));
}
//Problem #19

//Problem #20
enum enChar {smallLetter = 1, capitalLetter = 2, digit = 3, special = 4};
char randomThing(enChar thing){
  switch(thing){
    case enChar::smallLetter: return char(randomNumber(97,122));
    break;
    case enChar::capitalLetter: return char(randomNumber(65,90));
    break;
    case enChar::digit: return char(randomNumber(48,57));
    break;
    case enChar::special: return char(randomNumber(33,47));
    break;
  }
  return 0;
}
//Problem #20

//Problem #21
string generateWord(enChar thing, short length){
  string word = "";
  for(int i = 1; i <= length; i++){
    word += randomThing(enChar::capitalLetter);
  }
  return word;
}
string generateKey(){
  string key = "";
    for(int j = 1; j <= 4; j++){
      key += generateWord(enChar::capitalLetter, 4);
      j < 4 ? key += "-" : key;
    } 
  return key;
}
void generateKeys(int num){
  //just to showup
  for(int i = 1; i <= num; i++){
    cout << "Key[" << i << "]: " << generateKey() << endl;
  }
}
//Problem #21

//Problem #22
void readArray(int array[], int &size){
  cout << "Enter size: ";
  cin >> size;
  cout << "\nEnter Elements: " << endl;
    for(int i = 0; i < size; i++){
    cout << "Element[" << i+1 << "]: ";
    cin >> array[i];
    }
}
void printArray(int arr[], int size){
  for(int i = 0; i < size; i++){
    // cout << endl << "Element[" << i + 1 << "]: ";
    cout << arr[i] << " ";
  }
  cout << endl;
}
void printArray(string arr[], int &size){
  for(int i = 0; i < size; i++){
    cout << "Element[" << i + 1 << "]: ";
    cout << arr[i] << endl;
  }
  cout << endl;
}
int repetitionInArray(int arr[], int size, short check){
  int reps = 0;
  for(int i = 0; i < size; i++){
    if(arr[i] == check){
      reps++;
    }
  }
  return reps;
}
//Problem #22

//Problem #23
void fillArrayWithRandoms(int arr[], int &size){
  for(int i = 0; i < size; i++){
    arr[i] = randomNumber(-100, 100);
  }
}
//Problem #23

//Problem #24
int maxInArray(int array[], int &size){
  int max = 0;
  for(int i = 0; i < size; i++){
    if(array[i] > array[max]){
      max = i;
    }
  }
  return array[max];
}
void fillThenMax(int array[], int &size){
  fillArrayWithRandoms(array, size);
  printArray(array, size);
  cout << "maximum is: " << maxInArray(array, size) << endl;
}
//Problem #24

//Problem #25
int minInArray(int array[], int &size){
  int min = 0;
  for(int i = 0; i < size; i++){
    if(array[i] < array[min]){
      min = i;
    }
  }
  return array[min];
}
void fillThenMin(int array[], int &size){
  fillArrayWithRandoms(array, size);
  printArray(array, size);
  cout << "minimum is: " << minInArray(array, size) << endl;
}
//Problem #25

//Problem #26
int fillThensum(int arr[100], int &size){
  int sum = 0;
  fillArrayWithRandoms(arr, size);
  for(int i = 0; i < size; i++){
    sum += arr[i];
  }
  printArray(arr, size);
  return sum;
}
//Problem #26

//Problem #27
float fillThenAvg(int arr[100], int &size){
  float avg = (float(fillThensum(arr, size)) / float(size));
  return avg;
}
//Problem #27

//Problem #28
void copyArray(int origin[100], int cop[100], int &size){
  for(int i = 0; i < size; i++){
    cop[i] = origin[i];
  }
}
//Problem #28

//Problem #29
void copyPrime(int origin[100], int cop[100], int &size, int &size2){
  int clength = 0;
  for(int i = 0; i < size; i++){
    if(isPrime(origin[i])){
      cop[clength] = origin[i];
      cout << cop[clength] << " ";
      clength++;
    }
  }
  --clength;
  size2 = clength;
}
// ================ in main():===================
// int main(){
//   srand((unsigned)time(NULL));
//   int test[100];
//   int testing[100];
//   int size = readPositiveNumber("Enter size: ");
//   int size2 = 0;
//   fillArrayWithRandoms(test, size);
//   cout << "Original array: ";
//   printArray(test, size);
//   cout << "\nPrime numbers copied to the second array are: ";
//   copyPrime(test, testing, size, size2);
//   return 0;
// }
//Problem #29

//Problem #30
void sumOfTwoArrays(int arr1[100], int arr2[100], int &size){
  int arr3[100];
  for(int i = 0; i < size; i++){
    arr3[i] = arr1[i] + arr2[i];
    cout << arr3[i] << " ";
  }
}
//Problem #30

//Problem #31
void shuffleArray(int arr[100], int &size){
  int temp;
  for(int i = 0; i < size; i++){
    int r = randomNumber(0,size - 1);
    swap(arr[i], arr[r]);
  }
}
// int main(){
  // srand((unsigned)time(NULL));
  // int z[100];
  // int size = readPositiveNumber("Array size: ");
  // fillArrayWithRandoms(z, size);
  // cout << endl << "Array before shuffling: ";
  // printArray(z,size);
  // cout << endl;
  // cout << endl << "Array after shuffling: ";
  // printArray(z,size);
//   return 0;
// }
//Problem #31

//Problem #32
void reverseArray(int arr[100], int &size){
  int i = 0;
  while(arr[i] != arr[size-1 - i] && size-1-i > i){
    swap(arr[i], arr[size-1 - i]);
    i++;
  }
}
void copyArrayInReverse(int origin[100], int cop[100], int &size){
  reverseArray(origin, size);
  copyArray(origin, cop, size);
}
// int main(){
//   srand((unsigned)time(NULL));
//   int z[100];
//   int z2[100];
//   int size = readPositiveNumber("Array size: ");
//   fillArrayWithRandoms(z, size);
//   cout << endl << "Original array: ";
//   printArray(z,size);
//   cout << endl;
//   copyArrayInReverse(z, z2, size);
//   cout << endl << "Copy Array in reverse: ";
//   printArray(z2,size);
//   return 0;
// }
//Problem #32

//Problem #33
void fillArrayWithKeys(string arr[100], int &keys){
  for(int i = 0; i < keys; i++){
    arr[i] = generateKey();
  }
}
//  fillArrayWithKeys(z, keys);
//  printArray(z,size);

//Problem #33
//Problem #34
short int searchInArray(int arr[100], int target, int &size){
  for(int i = 0; i < size; i++){
    if(arr[i] == target){
      return i;
    }
  }
  return -1;
}
// int main(){
//   srand((unsigned)time(NULL));
//   int z[100];
//   int size = readPositiveNumber("Array size: ");
//   fillArrayWithRandoms(z, size);
//   cout << endl << "Original array: ";
//   printArray(z, size);
//   cout << endl;
//   int target = readPositiveNumber("Number to search for: ");
//   if(searchInArray(z, target, size) == -1){
//     cout << "Not found :(" << endl;
//   }else{
//     cout << "Number " << target << " is at index: ";
//     cout << searchInArray(z, target, size);
//   }
//   return 0;
// }
//Problem #34

//Problem #35
bool isFound(int arr[100], int target, int &size){
  if(searchInArray(arr, target, size) == -1){
    // cout << "Not found :(" << endl;
    return false; 
  }else{
    // cout << "Number " << target << " is found at index: ";
    // cout << searchInArray(arr, target, size);
    return true;
  }
}
//Problem #35

//Problem #36
void semiDynamicArray(int arr[100]){
  bool cont;
  int size = 0;
  do{
    arr[size] = readPositiveNumber("Enter an element: ");
    cont = readPositiveNumber("Add more? [0]no/[1]yes: ");
    size++;
  }while(cont);
  printArray(arr, size);
  cout << "Length is: " << size;
}
void AddArrayElement(int Number, int arr[100], int &arrLength) { 
  //its a new element so we need to add the length by 1
  //arrlength must start from zero to only book the necessary size
  arrLength++; 
  arr[arrLength - 1] = Number; 
} 
//Problem #36

//Problem #37
void copyArray2(int origin[100], int cop[100], int &size, int &size2){
  for(int i = 0; i < size; i++){
    AddArrayElement(origin[i], cop, size2);
  }
  // cout << "copied array: ";
  printArray(cop, size2);
  cout << endl;
}
// int main(){
//   srand((unsigned)time(NULL));
//   int z[100];
//   int z2[100];
//   int size2 = 0;
//   int size = readPositiveNumber("Original Array size: ");

//   cout << "Original array: ";
//   fillArrayWithRandoms(z, size);
//   printArray(z, size);
//   copyArray2(z, z2, size, size2);
//   return 0;
// }
//Problem #37

//Problem #38
void copyOdd(int origin[100], int cop[100], int &size, int &size2){
  for (int i = 0; i < size; i++){
    if(isOdd(origin[i])){
      AddArrayElement(origin[i], cop, size2);
    }
  }
  printArray(cop, size2);
}
// int main(){
//   srand((unsigned)time(NULL));
//   int z[100];
//   int z2[100];
//   int size2 = 0;
//   int size = readPositiveNumber("Original Array size: ");

//   cout << "Original array: ";
//   fillArrayWithRandoms(z, size);
//   printArray(z, size);
//   cout << "Copied array: ";
//   copyOdd(z, z2, size, size2);
//   return 0;
// }
//Problem #38

//Problem #39
void copyPrime2(int origin[100], int cop[100], int &size, int &size2){
  for (int i = 0; i < size; i++){
    if(isPrime(origin[i])){
      AddArrayElement(origin[i], cop, size2);
    }
  }
  printArray(cop, size2);
}
// int main(){
//   srand((unsigned)time(NULL));
//   int z[100];
//   int z2[100];
//   int size2 = 0;
//   int size = readPositiveNumber("Original Array size: ");

//   cout << "Original array: ";
//   fillArrayWithRandoms(z, size);
//   printArray(z, size);
//   cout << "Copied array: ";
//   copyOdd(z, z2, size, size2);
//   return 0;
// }
//Problem #39

//Problem #40
void copyDistinct(int origin[100], int cop[100], int &size, int &size2){
  for (int i = 0; i < size; i++){
    if(!isFound(cop, origin[i], size2)){
      AddArrayElement(origin[i], cop, size2);
    }
  }
  printArray(cop, size2);
}
//Problem #40

//Problem #41
bool isPalindromeArray(int origin[100],int &size){
int i = 0;
while(size-1-i > i){
  if(origin[i] != origin[size-1 - i]){
    return false;
  }
  i++;
}
return true;
}
//Problem #41

//Problem #42
int countOddInArray(int origin[100],int &size){
  int sOdd = 0;
  for (int i = 0; i < size; i++){
    isOdd(origin[i]) ? sOdd++ : sOdd;
  }
  return sOdd;
}
//Problem #42

//Problem #43
int countEvenInArray(int origin[100],int &size){
  int sEven = 0;
  for (int i = 0; i < size; i++){
    !isOdd(origin[i]) ? sEven++ : sEven;
  }
  return sEven;
}
//Problem #43

//Problem #44
int countPositiveInArray(int origin[100],int &size){
  int sPositive = 0;
  for (int i = 0; i < size; i++){
    isPositive(origin[i]) ? sPositive++ : sPositive;
  }
  return sPositive;
}
//Problem #44

//Problem #45
int countNegativeInArray(int origin[100],int &size){
  int sNegative = 0;
  for (int i = 0; i < size; i++){
    !isPositive(origin[i]) ? sNegative++ : sNegative;
  }
  return sNegative;
}
//Problem #45

//Problem #46
void zAbs(float &num){
  !isPositive(num) ? num = -1*num : num;
}
//Problem #46

//Problem #47
float zRound(float &num){
  int iPart = int(num);
  float fPart = num - iPart;
  zAbs(fPart);
  if(fPart * 10 >= 5){
    isPositive(iPart) ? iPart++ : iPart--;
  }
  fPart = 0;
  return num = fPart + iPart;
}
//Problem #47

//Problem #48
float zFloor(float &num){
  int iPart = int(num);
  float fPart = num - iPart;
  zAbs(fPart);
  if(fPart * 10 >= 5){
    !isPositive(iPart) ? iPart-- : iPart;
  }
  fPart = 0;
  return num = fPart + iPart;
}
//Problem #48

//Problem #49
float zCeil(float &num){
  int iPart = int(num);
  float fPart = num - iPart;
  zAbs(fPart);
  if(fPart * 10 > 0){
    !isPositive(iPart) ? iPart : iPart++;
  }
  fPart = 0;
  return num = fPart + iPart;
}
//Problem #49

//Problem #50
float zsqrt(float &num){
return pow(num, 0.5);
}
//Problem #50