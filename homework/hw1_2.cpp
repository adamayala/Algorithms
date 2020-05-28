/*  Hacker Link: https://www.hackerrank.com/contests/cst370-s20-hw1/challenges/max-events/submissions/code/1320129075
 *  Title: hw1_2.cpp
 *  Abstract: This program determines the maximum number of events happening concurrently.
 *  Author: Adam Ayala
 *  ID: 2020
 *  Date: Jan 30, 2020
 */

#include <iostream>
#include <cstdlib>
using namespace std;

int main() 
{
  int numEvents, numTimes, temp, middleman, count = 0, maxCount = 0;
  cin >> numEvents;
  numTimes = numEvents * 2;

  int eventTimes[numTimes];

  for(int i = 0; i < numTimes; i++){
    cin >> temp;
    if(i % 2 == 1){
      eventTimes[i] = -1 * temp;
    }
    else{
      eventTimes[i] = temp;
    }
  }

  for(int j = 0; j < numTimes - 1; j++){
    for(int k = j + 1; k < numTimes; k++){
      if(abs(eventTimes[j]) > abs(eventTimes[k])){
        middleman = eventTimes[j];
        eventTimes[j] = eventTimes[k];
        eventTimes[k] = middleman;
      }
    }
  }

  for(int m = 0; m < numTimes - 1; m++){
    if(abs(eventTimes[m]) == abs(eventTimes[m + 1]) && eventTimes[m] < 0 && eventTimes[m + 1] > 0){
      middleman = eventTimes[m];
      eventTimes[m] = eventTimes[m + 1];
      eventTimes[m + 1] = middleman;
    }
  }
  for(int x = 0; x < numTimes; x++)

  for(int n = 0; n < numTimes; n++){
    if(eventTimes[n] > 0){
      count++;
      if(count > maxCount){
        maxCount = count;
      }
    }
    else{
      count--;
    }
  }

  cout << maxCount << endl;
}
