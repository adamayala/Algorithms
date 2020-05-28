/*
 * HackerRank link:https://www.hackerrank.com/contests/cst370-s20-hw2/challenges/reverse-number-13/submissions/code/1320396728
 * Title: hw2_1.cpp
 * Abstract: This program takes in a number and reverses the numbers order.
 * Author: Adam Ayala
 * ID: 2020
 * Date: February 5, 2020
 */

#include <iostream>
using namespace std;

int main() 
{
  int num, newNum = 0;
  cin >> num;

  //while the number is greater than 10,
  //the last number will be added to our
  //new number.  Then the new number will
  //be multiplied by 10
  while(num >= 10){
    newNum += num % 10;
    num /= 10;
    newNum *= 10;
  }

  //adding the last digit left of the number
  //to the new number
  newNum += num;
  cout << newNum;
}
