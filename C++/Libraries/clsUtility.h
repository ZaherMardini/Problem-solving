#pragma once
#include<iostream>
#include<cmath>
#include<iomanip>
#include"clsDate.h"
using namespace std;
class clsUtility{
public:
//================ Begin ================
// from PSLvl-2
static string readString(const string msg = "Enter a text: ") {
    string userInput;
    // cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear any remaining newline characters in the buffer
    while (true) {
        cout << msg;
        getline(cin >> ws, userInput);// The (cin >> ws) part is used to skip leading whitespaces before reading the actual line.
        if (!userInput.empty()) {
            return userInput; // Return the valid string
        } else {
            cout << "Invalid text try again";
        }
    }
}
static float getFractionPart(float num){
  return num - int(num);
}
static bool isOdd(int num){
  return num % 2 != 0;
}
// static bool isPositive(float num){
//   return num >= 0;
// }
static void swap(int &a, int &b){
  int temp = a;
  a = b;
  b = temp;
}
static void swap(float &a, float &b){
  float temp = a;
  a = b;
  b = temp;
}
static void swap(double &a, double &b){
  double temp = a;
  a = b;
  b = temp;
}
static void swap(char &a, char &b){
  char temp = a;
  a = b;
  b = temp;
}
static void swap(string &a, string &b){
  string temp = a;
  a = b;
  b = temp;
}
static void swap(clsDate &d1, clsDate &d2){
  clsDate temp = d2;
  d2 = d1;
  d1 = temp;
}
// any other swap funcitons should be here

static char readChar(string msg = "Enter a text"){
  char answer;
  cout << msg;
  cin >> answer;
  return answer;
}
static char getLowerCase(char &word){
  return char(tolower(word));
}
static char getUpperCase(char &word){
  return char(toupper(word));
}
static int readPositiveNumber(string msg = "Enter a positive number: "){
  int number = 0;
  do{
  cout << msg;
  cin >> number;
  }while(number < 0);
  return number;
}
static float readfloatNumber(string msg = "Enter a positive number: "){
  float number = 0;
  cout << msg;
  cin >> number;
  return number;
}
static bool isPrime(int num){
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
static void header(){
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
static void printTable(){
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
static void drawing(short num, string sh){
  for (short i = 0; i < num; i++)
  {
    cout << sh;
  }
}
static void screenTitle(string title){
  drawing(10, "---");
  cout << endl;
  tabs(2);
  cout << title << endl;
  drawing(10, "---");
  cout << endl;
}
static void tabs(short num){
  for (short i = 0; i < num; i++)
  {
    cout << "\t";
  }
}
static void primeNumbers(int num){
  for(int i = 1; i <= num; i++){
    if(isPrime(i)){
      cout << "\t" << i << "\t";
    }
  }
}
static bool isPerfect(int num){
  int result = 0;
  for(int i = 1; i < num; i++){
    if(num % i == 0){
      result += i;
    }
  }
  return result == num;
}
static void perfectNumbers(int num){
  for(int i = 1; i <= num; i++){
    if(isPerfect(i)){
      cout << i << endl;
    }
  }
}
static void reverseDigits(int digits){
  int remainder = 0;
  while(digits > 0){
    remainder = digits % 10;
    digits = digits / 10;
    cout << remainder << endl;
  }
}
static int reverseDigits2(int digits){//123 => 3 , 32 , 321
  int remainder = 0;
  int result = 0;
  while(digits > 0){
    remainder = digits % 10;
    digits = digits / 10;
    result = result * 10 + remainder;
  }
  return result;
}
static int sumOfDigits(int d){
  int result = 0;
  int remainder = 0;
  while(d > 0){
    remainder = d % 10;
    result += remainder;
    d = d / 10;
  }
  return result;
}
static int repetitionOfDigit(int number, short digit){
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
static void totalRepetitionOfDigit(int num){
  int duplicate = 0;
  for(int i = 0; i <= 10; i++){
    duplicate = repetitionOfDigit(num, i);
    if(duplicate > 0){
      cout << i << " was repeated: " << duplicate << " time(s)\n";
    }
  }
};
static void printInOrder(int num){
  int rem = 0;
  while(num > 0){
    rem = num % 10;
    num = num / 10;
    cout << rem << endl;
  }
}
static bool isPalindrome(int num = 0){
  return reverseDigits2(num) == num;
}
static void descendingPattern(int num){
  for(int i = num; i > 0; i--){
    for(int j = i; j > 0; j-- ){
      cout << i;
    }
    cout << endl;
  }
}
static void ascendingPattern(int num){
  for(int i = 1; i <= num; i++){
    for(int j = i; j > 0; j-- ){
      cout << i;
    }
    cout << endl;
  }
}
static void descendingLettersPattern(int num){
  for(int i = num + 64; i >= 65; i--){
      //instructor intervals: j=1; j<=num-(num+64-i)
    for(int j = i; j >= 65; j-- ){
      cout << char(i);
    }
    cout << endl;
  }
  //A->Z in ASCII is 65->90 || a->z in ASCII is 97->122
}
static void ascendingLettersPattern(int num){
  for(int i = 65; i < 65 + num; i++){
    for(int j = i; j >= 65; j-- ){
      cout << char(i);
    }
    cout << endl;
  }
}
static void lettersPossibilities(){
  for(int i = 65; i <= 90; i++){
    for(int j = 65; j <= 90; j++){
      for(int k = 65; k <= 90; k++){
        cout << char(i) << char(j) << char(k) << endl;
      }
    }
  }
}
static bool guessWordOf3Characters(){
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
static string encryptDecryptText(){
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
static int randomNumber(int from, int to){
  int result = rand() % (to - from + 1) + from;
  return result;
  //when using rand() function put
  //this in the main() function one time only: srand((unsigned)time(NULL));
}
enum enChar {smallLetter = 1, capitalLetter = 2, digit = 3, special = 4};
static char randomThing(enChar thing){
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
static string generateWord(enChar thing, short length){
  string word = "";
  for(int i = 1; i <= length; i++){
    word += randomThing(enChar::capitalLetter);
  }
  return word;
}
static string generateKey(){
  string key = "";
    for(int j = 1; j <= 4; j++){
      key += generateWord(enChar::capitalLetter, 4);
      j < 4 ? key += "-" : key;
    } 
  return key;
}
static void generateKeys(int num){
  //just to showup
  for(int i = 1; i <= num; i++){
    cout << "Key[" << i << "]: " << generateKey() << endl;
  }
}
static void readArray(int array[], int &size){
  cout << "Enter size: ";
  cin >> size;
  cout << "\nEnter Elements: " << endl;
    for(int i = 0; i < size; i++){
    cout << "Element[" << i+1 << "]: ";
    cin >> array[i];
    }
}
static void printArray(int arr[], int size){
  for(int i = 0; i < size; i++){
    // cout << endl << "Element[" << i + 1 << "]: ";
    cout << arr[i] << " ";
  }
  cout << endl;
}
static void printArray(string arr[], int &size){
  for(int i = 0; i < size; i++){
    cout << "Element[" << i + 1 << "]: ";
    cout << arr[i] << endl;
  }
  cout << endl;
}
static int repetitionInArray(int arr[], int size, short check){
  int reps = 0;
  for(int i = 0; i < size; i++){
    if(arr[i] == check){
      reps++;
    }
  }
  return reps;
}
static void fillArrayWithRandoms(int arr[], int &size){
  for(int i = 0; i < size; i++){
    arr[i] = randomNumber(-100, 100);
  }
}
static int maxInArray(int array[], int &size){
  int max = 0;
  for(int i = 0; i < size; i++){
    if(array[i] > array[max]){
      max = i;
    }
  }
  return array[max];
}
static void fillThenMax(int array[], int &size){
  fillArrayWithRandoms(array, size);
  printArray(array, size);
  cout << "maximum is: " << maxInArray(array, size) << endl;
}
static int minInArray(int array[], int &size){
  int min = 0;
  for(int i = 0; i < size; i++){
    if(array[i] < array[min]){
      min = i;
    }
  }
  return array[min];
}
static void fillThenMin(int array[], int &size){
  fillArrayWithRandoms(array, size);
  printArray(array, size);
  cout << "minimum is: " << minInArray(array, size) << endl;
}
static int fillThensum(int arr[100], int &size){
  int sum = 0;
  fillArrayWithRandoms(arr, size);
  for(int i = 0; i < size; i++){
    sum += arr[i];
  }
  printArray(arr, size);
  return sum;
}
static float fillThenAvg(int arr[100], int &size){
  float avg = (float(fillThensum(arr, size)) / float(size));
  return avg;
}
static void copyArray(int origin[100], int cop[100], int &size){
  for(int i = 0; i < size; i++){
    cop[i] = origin[i];
  }
}
static void copyPrime(int origin[100], int cop[100], int &size, int &size2){
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
static void sumOfTwoArrays(int arr1[100], int arr2[100], int &size){
  int arr3[100];
  for(int i = 0; i < size; i++){
    arr3[i] = arr1[i] + arr2[i];
    cout << arr3[i] << " ";
  }
}
static void shuffleArray(int arr[100], int &size){
  int temp;
  for(int i = 0; i < size; i++){
    int r = randomNumber(0,size - 1);
    swap(arr[i], arr[r]);
  }
}
static void reverseArray(int arr[100], int &size){
  int i = 0;
  while(arr[i] != arr[size-1 - i] && size-1-i > i){
    swap(arr[i], arr[size-1 - i]);
    i++;
  }
}
static void copyArrayInReverse(int origin[100], int cop[100], int &size){
  reverseArray(origin, size);
  copyArray(origin, cop, size);
}
static void fillArrayWithKeys(string arr[100], int &keys){
  for(int i = 0; i < keys; i++){
    arr[i] = generateKey();
  }
}
static short int searchInArray(int arr[100], int target, int &size){
  for(int i = 0; i < size; i++){
    if(arr[i] == target){
      return i;
    }
  }
  return -1;
}
static bool isFound(int arr[100], int target, int &size){
  if(searchInArray(arr, target, size) == -1){
    // cout << "Not found :(" << endl;
    return false; 
  }else{
    // cout << "Number " << target << " is found at index: ";
    // cout << searchInArray(arr, target, size);
    return true;
  }
}
static void semiDynamicArray(int arr[100]){
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
static void AddArrayElement(int Number, int arr[100], int &arrLength) { 
  //its a new element so we need to add the length by 1
  //arrlength must start from zero to only book the necessary size
  arrLength++; 
  arr[arrLength - 1] = Number; 
} 
static void copyArray2(int origin[100], int cop[100], int &size, int &size2){
  for(int i = 0; i < size; i++){
    AddArrayElement(origin[i], cop, size2);
  }
  // cout << "copied array: ";
  printArray(cop, size2);
  cout << endl;
}
static void copyOdd(int origin[100], int cop[100], int &size, int &size2){
  for (int i = 0; i < size; i++){
    if(isOdd(origin[i])){
      AddArrayElement(origin[i], cop, size2);
    }
  }
  printArray(cop, size2);
}
static void copyPrime2(int origin[100], int cop[100], int &size, int &size2){
  for (int i = 0; i < size; i++){
    if(isPrime(origin[i])){
      AddArrayElement(origin[i], cop, size2);
    }
  }
  printArray(cop, size2);
}
static void copyDistinct(int origin[100], int cop[100], int &size, int &size2){
  for (int i = 0; i < size; i++){
    if(!isFound(cop, origin[i], size2)){
      AddArrayElement(origin[i], cop, size2);
    }
  }
  printArray(cop, size2);
}
static bool isPalindromeArray(int origin[100],int &size){
int i = 0;
while(size-1-i > i){
  if(origin[i] != origin[size-1 - i]){
    return false;
  }
  i++;
}
return true;
}
static int countOddInArray(int origin[100],int &size){
  int sOdd = 0;
  for (int i = 0; i < size; i++){
    isOdd(origin[i]) ? sOdd++ : sOdd;
  }
  return sOdd;
}
static int countEvenInArray(int origin[100],int &size){
  int sEven = 0;
  for (int i = 0; i < size; i++){
    !isOdd(origin[i]) ? sEven++ : sEven;
  }
  return sEven;
}
static int countPositiveInArray(int origin[100],int &size){
  int sPositive = 0;
  for (int i = 0; i < size; i++){
    origin[i] > 0 ? sPositive++ : sPositive;
  }
  return sPositive;
}
static int countNegativeInArray(int origin[100],int &size){
  int sNegative = 0;
  for (int i = 0; i < size; i++){
    origin[i] < 0 ? sNegative++ : sNegative;
  }
  return sNegative;
}
static void zAbs(float &num){
  num < 0 ? num = -1*num : num;
}
static float zRound(float &num){
  int iPart = int(num);
  float fPart = num - iPart;
  zAbs(fPart);
  if(fPart * 10 >= 5){
    iPart > 0 ? iPart++ : iPart--;
  }
  fPart = 0;
  return num = fPart + iPart;
}
static float zFloor(float &num){
  int iPart = int(num);
  float fPart = num - iPart;
  zAbs(fPart);
  if(fPart * 10 >= 5){
    iPart < 0 ? iPart-- : iPart;
  }
  fPart = 0;
  return num = fPart + iPart;
}
static float zCeil(float &num){
  int iPart = int(num);
  float fPart = num - iPart;
  zAbs(fPart);
  if(fPart * 10 > 0){
    iPart < 0 ? iPart : iPart++;
  }
  fPart = 0;
  return num = fPart + iPart;
}
static float zsqrt(float num){
return pow(num, 0.5);
}
// from PSLvl-2
// from PSLvl-3
static void fillMatrixWithRandoms(int matrix[3][3], int &rows, int &columns){
  for (int i = 0; i < rows; i++){
    for (int j = 0; j < columns; j++){
      matrix[i][j] = randomNumber(0,10);
    }
  }
}
static void printMatrix(int matrix[3][3], int &rows, int &columns){
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
static void printMatrixInReverse(int matrix[3][3], int rows, int columns){
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
static int rowSum(int matrix[3][3], int &rows, int &columns){
  int sum = 0;
    for (short j = 0; j < columns; j++){
      sum += matrix[rows][j];
    }  
  return sum;
}
static void sumOfRowsInMatrix(int matrix[3][3], int &rows, int &columns){
  for (int i = 0; i < rows; i++)
  {
    cout << "Sum of row" << i+1 << " :"; 
    cout << setw(5) << rowSum(matrix, i, columns) << endl;
    //give me the sum of row number i, the columns are boundries
  }
}
static void AddMatrixElement(int number, int matrix[3][3], int &rows, int &columns){
  matrix[--rows][--columns] = number;
}
static void sumOfRowsInMatrixToArray(int matrix[3][3], int &rows, int &columns, int result[3]){
  for (int i = 0; i < rows; i++){
    result[i] = rowSum(matrix, i, columns);
  }
}
static int colSum(int matrix[3][3], int &rows, int &columns){
  int sum = 0;
  for (short i = 0; i < rows; i++){
    sum += matrix[i][columns];
  }
  return sum;
}
static void sumOfColumnsInMatrix(int matrix[3][3], int &rows, int &columns){
  int sum = 0;
  for (int i = 0; i < rows; i++){
    cout << "Sum of column" << i+1 << " :";  
    cout << setw(3) << colSum(matrix, rows, i) << endl;
    //give me the sum of column number i, the rows are boundries
  }
}
static void sumOfColumnsInMatrixToArray(int matrix[3][3], int &rows, int &columns, int result[3]){
  for (int i = 0; i < columns; i++){
    result[i] = colSum(matrix, rows, i);
  }
}
static void fillMatrixWithOrderedNums(int matrix[3][3], int &rows, int &columns){
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
static void transposeMatrix(int origin[3][3], int trans[3][3], int &rows, int &columns){
  for (short i = 0; i < rows; i++)
  {
    for (short j = 0; j < columns; j++)
    {
      trans[j][i] = origin[i][j];
    }
  }
}
static void multiplyMatricies(int first[3][3], int second[3][3],int result[3][3], int &rows, int &columns){
  for (short i = 0; i < rows; i++){
    for (short j = 0; j < columns; j++){
      result[i][j] = first[i][j] * second[i][j];
    }
  }
}
static void printMidRowCol(int matrix[3][3], int &rows, int &columns){
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
static int sumMatrix(int matrix[3][3], int &rows, int &columns){
  int sum = 0;
  for (short i = 0; i < rows; i++){
    for (short j = 0; j < columns; j++){
      sum += matrix[i][j];
    }
  }
  // cout << "sum of matrix is: " << sum;
  return sum;
}
static bool areEqual(int m1[3][3], int m2[3][3], int &rows, int &columns){
  return sumMatrix(m1, rows, columns) == sumMatrix(m2, rows, columns);
}
static bool areTypical(int m1[3][3], int m2[3][3], int &rows, int &columns){
    for (short i = 0; i < rows; i++){
      for (short j = 0; j < columns; j++){
        if(m1[i][j] != m2[i][j]){
          return false;
        };
      }
    }
  return true;
}
static bool isIdentity(int m[3][3], int &rows, int &columns){
  for (short i = 0; i < rows; i++){
    for (short j = 0; j < columns; j++){
      if((i==j && m[i][j] != 1) || (i != j && m[i][j] != 0)){
        return false;
      }
    }
  }
  return true;
}
static bool isScalar(int m[3][3], int &rows, int &columns){
  for (short i = 0; i < rows; i++){
    for (short j = 0; j < columns; j++){
      if((i==j && m[i][j] != m[0][0]) || (i != j && m[i][j] != 0)){
        return false;
      }
    }
  }
  return true;
}
static short mNumberCount(int num, int m[3][3], int &rows, int &columns){
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
static bool isSparce(int m[3][3], int &rows, int &columns){
  short zeros = mNumberCount(0, m, rows, columns);
  short mSize = rows*columns;
  return zeros > mSize/2;
}
static bool mIsfound(int target, int m[3][3], int &rows, int &columns){
  for (short i = 0; i < rows; i++){
    for (short j = 0; j < columns; j++){
      if(m[i][j] == target){
        return true;
      }
    }
  }
  return false;
}
static void intersected(int m1[3][3], int m2[3][3], int &rows, int &columns){
  cout << "Intersected numbers are: " << endl;
  for (short i = 0; i < rows; i++){
    for (short j = 0; j < columns; j++){
      if(mIsfound(m1[i][j], m2, rows, columns)){
        cout << setw(5) << m1[i][j];
      }
    }
  }
}
static void minMaxMatrix(int m[3][3],int &rows, int &columns){
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
static bool mIsPalindrome(int matrix[3][3], int &rows, int &columns){
  for (int i = 0; i < rows; i++){
    for (int j = 0; j < columns/2; j++){
      if(matrix[i][j] != matrix[i][columns - 1 -j]){
        return false;
      }
    }
  }
  return true;
}
static void fip(short reps){
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
static void fip2(short reps, short n1 = 1, short n2 = 0){
  if(reps > 0){
    short fib;
    fib = n1 + n2;
    n1 = n2; 
    n2 = fib;
    cout << setw(3) << fib;
    fip2(reps - 1, n1, fib);
  }
}
// from PSLvl-3

// from PSLvl-4
string numberToText(int num){
  if(num == 0){
    return "";
  }
  if (num > 0 && num < 20)
  {
    string text[] = {"", "One", "Two", "Three", "Four", "Five",
    "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve",
    "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", 
    "Eighteen", "Nineteen"};
    return text[num] + " ";
  }
  if(num >= 20 && num <= 99){
    string text[] = {"", "", "Twenty", "Thirty", "Fourty", "Fifty",
    "Sixty", "Seventy", "Eighty", "Ninety"};
    return text[num/10] + " " + numberToText(num%10) + " ";
  }
  if(num >= 100 && num < 1000){
    return numberToText(num/100) + "Hundred " + numberToText(num%100);
  }
  if(num >= 1000 && num < 1000000){
    return numberToText(num/1000) + "Thousand " + numberToText(num%1000);
  }
  if(num >= 1000000 && num < 1000000000){
    return numberToText(num/1000000) + "Million " + numberToText(num%1000000);
  }
  if(num >= 1000000000 && num < 1000000000000){
    return numberToText(num/1000000000) + "Billion " + numberToText(num%1000000000);
  }
  return " ";
}
// from PSLvl-4
};