/*
 *  HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw0/challenges/370-hw0-1/submissions/code/1319799579
 *  Title: hw0_1.cpp
 *  Abstract: This program does 1 of 2 things, adds 2 integers or determines the difference between 2 integers, based on a "key" value.
 *  Author: Adam Ayala
 *  ID: 2020
 *  Date: 01/24/2020
 */

#include <iostream>
using namespace std;

int main() 
{
    int key, num1, num2;
  cin >> key;
  while(key != 9){
    cin >> num1;
    cin >> num2;  
    if(key == 1){
      cout << num1 + num2 << endl;
    }
    else if(key == 2){
      cout << abs(num1 - num2) << endl;
    }
    cin >> key;
  }
}
