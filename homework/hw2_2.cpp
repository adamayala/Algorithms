/*
 *  HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw2/challenges/time-difference-2/submissions/code/1320397437
 *  Title: h2_2.cpp
 *  Abstract: This program takes in two times and determines the difference in the two times.
 *  Author: Adam Ayala
 *  ID: 2020
 *  Date: February 5, 2020
 */

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() 
{
  //all variables needed
  string firstTime, secondTime;
  int fHour, fMin, fSec, sHour, sMin, sSec;

  cin >> firstTime;
  cin >> secondTime;

  //seperating the individual units of time
  //into int variables
  fHour = stoi(firstTime.substr(0,2));
  fMin = stoi(firstTime.substr(3,2));
  fSec = stoi(firstTime.substr(6,2));

  sHour = stoi(secondTime.substr(0,2));
  sMin = stoi(secondTime.substr(3,2));
  sSec = stoi(secondTime.substr(6,2));
  
  //basic arithmetic of "borrowing" digits
  //for subtraction
  if(sSec < fSec){
    sSec += 60;
    sMin -= 1;
  }
  if(sMin < fMin){
    sMin += 60;
    sHour -= 1;
  }
  if(sHour < fHour){
    sHour += 24;
  }

  //displaying the awswer but putting in
  //a leading zero if needed
  if(sHour - fHour < 10){
    cout << "0" << sHour - fHour << ":";
  }
  else{
    cout << sHour - fHour << ":";
  }
  if(sMin - fMin < 10){
    cout << "0" << sMin - fMin << ":";
  }
  else{
    cout << sMin - fMin << ":";
  }
  if(sSec - fSec < 10){
    cout << "0" << sSec - fSec;
  }
  else{
    cout << sSec - fSec;
  }
}
