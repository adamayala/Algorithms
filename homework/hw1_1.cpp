/*  Hackerrank Link: https://www.hackerrank.com/contests/cst370-s20-hw1/challenges/common-nums/submissions/code/1320125649
 *  Title: hw1_1.cpp
 *  Abstract: This program determines the similar numbers within two lists provided.
 *  Author: Adam Ayala
 *  ID: 2020
 *  Date: Jan 30, 2020
 */

#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{
  int listSize1, listSize2, temp, max = 0;
  
  cin >> listSize1;
  int firstList[listSize1];
  for(int i = 0; i < listSize1; i++){
    cin >> firstList[i];
  }

  cin >> listSize2;
  int position = 0;

  int ans[listSize1];

  //int secondList[listSize2];
  for(int j = 0; j < listSize2; j++){
    cin >> temp;
    for(int m = 0; m < listSize1; m++){
      if(firstList[m] == temp){
        bool isIn = false;
        for(int n = 0; n < position; n++){
          if(ans[n] == temp){
            isIn = true;
          }
        }
        if(!isIn){
          ans[position] = temp;
          position++;
        }
      }
    }
  }

  int middleman;
  for(int x = 0; x < position - 1; x++){
    for(int y = x + 1; y < position; y++){
      if(ans[x] > ans [y]){
        middleman = ans[x];
        ans[x] = ans[y];
        ans[y] = middleman;
      }
    }
  }

  cout << "Answer:";
  if(position == 0){
    cout << "NONE";
  }
  else{
    for(int k = 0; k < position; k++){
      cout << ans[k] << " ";
    }
  }
  cout << endl;
  // for(int m = 0; m < listSize2; m++){
  //   cout << secondList[m];
  // }
}
