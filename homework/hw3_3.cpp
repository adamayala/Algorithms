/*
 *  HackerRank Link: https://www.hackerrank.com/contests/cst370-s20-hw3/challenges/adjacency-list/submissions/code/1320794281
 *  Title: hw3_3.cpp
 *  Abstract: This program converts directed graph data from a user into a corresponding adjacency list format.
 *  Author: Adam Ayala
 *  ID: 2020
 *  Date: Feb 13, 2020
 */

#include <iostream>
#include <set>
using namespace std;

int main() 
{
  int numV, numE;
  cin >> numV;
  cin >> numE;
  int numbers[numV][numE];


  for(int i = 0; i < numE; i++){
    int numA, numB;
    cin >> numA;
    cin >> numB;

    numbers[numA][numB] = 1;
  }

  for(int m = 0; m < numV; m++){
    cout << m;
    for(int n = 0; n < numE; n++){
      if(numbers[m][n] == 1){
        cout << "->" << n;
      }
    }
    cout << endl;
  }
}
