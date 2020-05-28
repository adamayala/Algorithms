/*  HackerRank Link: https://www.hackerrank.com/contests/cst370-s20-hw3/challenges/binary-numbs/submissions/code/1320670107
 *  Title: hw3_1.cpp
 *  Abstract: This program creates a binary "language" and shows all possible combinations.
 *  Author: Adam Ayala
 *  ID: 2020
 *  Date: Feb 12, 2020
 */

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() 
{
  //declaring variables
  int num, stopValue;
  cin >> num;
  stopValue = pow(2, num);
  string values[num];
  string binaries[stopValue];

  //storing elements
  for(int i = 0; i < num; i++){
    cin >> values[i];
  }

  //creating an array that holds as many
  //binary numbers as needed for the size
  //of the elements
  for(int m = 1; m < stopValue; m++){
    int tempNum = m;
    string tempStr = "";
    while(tempNum != 1){
      if(tempNum % 2 == 1){
        tempStr = "1" + tempStr;
      }
      else{
        tempStr = "0" + tempStr;
      }
      tempNum /= 2;
    }
    tempStr = "1" + tempStr;
    while(tempStr.length() < num){
      tempStr = "0" + tempStr;
    }
    binaries[m] = tempStr;
  }
  
  //starts by displaying the first
  //empty element
  for(int l = 1; l < num; l++){
    cout << "0";
  }
  cout << "0:EMPTY" << endl;

  //displays all binary numbers and
  //their corresponding elements
  for(int b = 1; b < stopValue; b++){
    cout << binaries[b] << ":";

    for(int v = 0; v < num; v++){
      if(binaries[b][v] == '1'){
        cout << values[v] << " ";
      }
    }
    cout << endl;
  }
}
