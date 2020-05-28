/*
* HackerRank link:https://www.hackerrank.com/contests/cst370-s20-hw10/challenges/radix-sort-4-1/submissions/code/1323258712
* Title: hw10_1.cpp
* Abstract: A program to conduct radix sort.
* Author: Adam Ayala
* ID: 2020
* Date: May 1, 2020
*/

#include <iostream>
#include <stdio.h>
#include <array>
#include <cmath>
using namespace std;


int getNumDigits(int numbers[], int size){
  int num = 1;
  int max = numbers[0];
  for(int i = 1; i < size; i++){
    if(numbers[i] > max){
      max = numbers[i];
    }
  }

  while(max > 9){
    num++;
    max /= 10;
  }
  
  return pow(10, num);
}

void radixSort(int numbers[], int size, int numDigits, int current){
  int counter[10] = {0};
  int sorted[size];

  for(int i = 0; i < size; i++){
    if(numbers[i] < current){
      counter[0]++;
    }
    else{
      counter[(numbers[i] / current) % 10]++;
    }
  }

  for(int j = 1; j < 10; j++){
    counter[j] += counter[j - 1];
  }

  for(int k = size - 1; k >= 0; k--){
    sorted[(counter[(numbers[k] / current) % 10]) - 1] = numbers[k];
    counter[(numbers[k] / current) % 10]--;
  }
  
  for(int k = 0; k < size; k++){
    cout << sorted[k] << " ";
  }
  cout << endl;

  current *= 10;
  if(current < numDigits){
    radixSort(sorted, size, numDigits, current);
  }
}

int main() {
  int size, numDigits;
  cin >> size;

  int numbers[size];
  for(int i = 0; i < size; i++){
    cin >> numbers[i];
  }

  numDigits = getNumDigits(numbers, size);

  radixSort(numbers, size, numDigits, 1);
}