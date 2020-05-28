/*
 * HackerRank link:https://www.hackerrank.com/contests/cst370-s20-hw5/challenges/palindrome-check-10/submissions/code/1321578135
 * Title: hw5_1.cpp
 * Abstract: This program checks if an input string is a palindrome or not.
 * Author: Adam Ayala
 * ID: 2020
 * Date: March 6, 2020
 */
#include <iostream>
#include <ctype.h>
#include <string>
#include <bits/stdc++.h>
#include <ctype.h>
#include <stdio.h>
using namespace std;

bool palindrome(string str){
  while(!isalnum(str[0]) || str[0] == ' ' || !isalnum(str[str.length() - 1]) || str[str.length() - 1] == ' '){
    if(!isalnum(str[0]) || str[0] == ' '){
      str = str.substr(1, str.length() - 1);
    }
    if(!isalnum(str[str.length() - 1]) || str[str.length() - 1] == ' '){
      str = str.substr(0, str.length() - 1);
    }
  }
  if(str.length() <= 1){
    return true;
  }
  else if(tolower(str[0]) == tolower(str[str.length() - 1])){
    if(str.length() == 2){
      return true;
    }
    return palindrome(str.substr(1, str.length() - 2));
  }
  return false;
}

int main() 
{
  string str;
  getline(cin, str);
  if(palindrome(str)){
      cout << "TRUE";
  }
    else{
        cout << "FALSE";
    }
}