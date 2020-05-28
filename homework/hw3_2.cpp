/*
 *  HackerRank Link: https://www.hackerrank.com/contests/cst370-s20-hw3/challenges/equal-groups/submissions/code/1320761111
 *  Title: hw3_2.cpp
 *  Abstract: This program partitions n positive integers into two disjoint sets with the same sum.
 *  Author: Adam Ayala
 *  ID: 2020
 *  Date: Feb 13, 2020
 */

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <set>
using namespace std;

int main() 
{
  int num, lowestNum, lowestNumLoc = 0, sumNums = 0, middle, searchKey = 0;;
  bool found = false;
  cin >> num;

  int digits[num];
  int binary[num];
  for(int i = 0; i < num; i++){
    binary[i] = 0;
    cin >> digits[i];
    sumNums += digits[i];
    if(i == 0){
      lowestNum = digits[0];
    }
    else if(digits[i] < lowestNum){
      lowestNum = digits[i];
      lowestNumLoc = i;
    }
  }

  if(binary[lowestNumLoc] == 1){
    searchKey = 1;
  }

  middle = sumNums / 2;

  while(binary[num - 1] != 1 && !found){
    int addingNums = 0;
    for(int m = 0; m < num; m++){
      if(binary[m] == 1){
        binary[m] = 0;
      }
      else if(binary[m] == 0){
        binary[m] = 1;
        m = num;
      }
    }

    for(int j = 0; j < num; j++){
      if(binary[j] == 1){
        addingNums += digits[j];
      }
      if(j == num - 1 && addingNums == middle){
        found = true;
      }
    }
  }

  set <int> solutions;
  cout << "Equal Set:";
  if(!found || sumNums % 2 == 1){
    cout << " 0" << endl;
  }
  else{
    for(int b = 0; b < num; b++){
      if(binary[b] == searchKey){
        solutions.insert(digits[b]);
      }
    }
    for (auto it = solutions.begin(); it != solutions.end(); ++it)
      cout << ' ' << *it;
  }
}