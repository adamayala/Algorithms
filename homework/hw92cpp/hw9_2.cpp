/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw9/challenges/alien-alphabet/submissions/code/1323146146
 * Title: hw9_2.cpp
 * Abstract: A program that displays the alphabetical order of characters for an alien language.
 * Author: Adam Ayala
 * ID: 2020
 * Date: April 26, 2020
 */
 
#include <iostream>
#include<string>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;

bool contains(vector<char> letters, char str){
  for(int i = 0; i < letters.size(); i++){
    if(letters[i] == str){
      return true;
    }
  }
  return false;
}

bool contains(string str, char ch){
  for(int i = 0; i < str.length(); i++){
    if(str[i] == ch){
      return true;
    }
  }
  return false;
}

int main(){
  int size;
  cin >> size;
  string str[size];
  vector<char> letters;

  for(int i = 0; i < size; i++){
    string temp;
    cin >> temp;
    str[i] = temp;
    for(int j = 0; j < temp.size(); j++){
      if(!contains(letters, temp[j])){
        letters.push_back(temp[j]);
      }
    }
  }

  int position = 0;
  string edges[letters.size()];
  for(int i = 0; i < size - 1; i++){
    for(int j = i + 1; j < size; j++){
      for(int k = 0; k < str[i].length(); k++){
        if(str[i][k] != str[j][k]){
          position = 0;
          while(str[j][k] != letters[position]){
            position++;
          }
          if(!contains(edges[position], str[i][k])){
            edges[position] += str[i][k];
          }
          k = str[i].length();
        }
      }
    }
  }

  int pointers[letters.size()];
  for(int i = 0; i < letters.size(); i++){
    pointers[i] = edges[i].length();
  }

  bool works = false;
  for(int j = 0; j < letters.size(); j++){
    if(pointers[j] == 0){
      works = true;
    }
  }

  if(!works){
    cout << "Invalid input." << endl;
  }
  else{
    string output = "";
    int position = 0;
    for(int i = 0; i < letters.size(); i++){
      string takeout = "";
      for(int j = 0; j < letters.size(); j++){
        if(pointers[j] == 0 && !contains(output, letters[j])){
          output = output + letters[j] + "->";
          takeout = takeout + letters[j];
        }
      }
      position = 0;
      while(takeout.length() != 0){
        while(takeout[0] != letters[position]){
          position++;
        }
        for(int k = 0; k < letters.size(); k++){
          if(contains(edges[k], letters[position])){
            edges[k].erase(remove(edges[k].begin(), edges[k].end(), letters[position]));
          }
        }
        for(int r = 0; r < letters.size(); r++){
          pointers[r] = edges[r].length();
        }
        position = 0;
        takeout = takeout.substr(1);
      }
    }
    cout << output.substr(0, output.length() - 2) << endl;
  }  
}