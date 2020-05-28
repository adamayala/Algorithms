/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw9/challenges/max-heap-1-2/submissions/code/1323142168
 * Title: hw9_1.cpp
 * Abstract: A program to conduct heap operations.
 * Author: Adam Ayala
 * ID: 2020
 * Date: April 26, 2020
 */
#include <iostream>
#include<string>

using namespace std;

struct Node 
{
    // Data part for a node. 
    int data;
    Node* left;
    Node* right;

    // Constructor for a new node.
    Node(int d) 
    {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

Node* mkTree(int data, Node* left, Node* right)
{
    //Makes a small tree with 2 children, then returns root
    Node* root = new Node(data);
    root->left = left;
    root->right = right;
    return root;
}

int getNumNodes(Node* root)
{
    //Recursive function to determine and return total number of nodes
  if(root == nullptr){
    return 0;
  }
  else{
    return 1 + getNumNodes(root->left) + getNumNodes(root->right);
  }
}

int getHeight(Node* root)
{
    //Recursive function to determine and return height of tree
  if(root == nullptr){
    return 0;
  }
  else{
    return 1 + getHeight(root->left);
  }
}

Node* insertHelper(Node* root, int num, string directions)
{
    //add new node based on "directions" from insert method
  if(directions.length() > 1){
    if(directions[0] == 'L'){
      insertHelper(root->left, num, directions.substr(1));
    }
    else{
      insertHelper(root->right, num, directions.substr(1));
    }
  }
  else{
    if(directions == "L"){
      root->left = new Node(num);
    }
    else{
      root->right = new Node(num);
    }
  }
  return root;
}

Node* insert(Node* root, int num)
{
    //Determines where new element should be placed
  int numNodes = (getNumNodes(root) + 1);
  string directions = "";
  while(numNodes > 1){
    if(numNodes % 2 == 1){
      directions = "R" + directions;
    }
    else{
      directions = "L" + directions;
    }
    numNodes /= 2;
  }
  return insertHelper(root, num, directions);
}

int getLastHelper(Node* root, string directions)
{
  if(directions.length() > 1){
    if(directions[0] == 'L'){
      return getLastHelper(root->left, directions.substr(1));
    }
    else{
      return getLastHelper(root->right, directions.substr(1));
    }
  }
  else{
    if(directions == "L"){
      int last = root->left->data;
      root->left = nullptr;
      return last;
    }
    else{
      int last = root->right->data;
      root->right = nullptr;
      return last;
    }
  }
}

int getLast(Node* root)
{
    //Determines "directions" of where next element should be placed
  int lastValue;
  int numNodes = getNumNodes(root);
  string directions = "";
  while(numNodes > 1){
    if(numNodes % 2 == 1){
      directions = "R" + directions;
    }
    else{
      directions = "L" + directions;
    }
    numNodes /= 2;
  }
  return getLastHelper(root, directions);
}

Node* deleteMax(Node* root)
{
    //Deletes last node and places that value at the root
  int lastValue = getLast(root);
  root->data = lastValue;
  return root;
}

void changeValue(Node* root, int num, int lastValue)
{
    //Recursively finds a value, changes value
  if(root){
    if(root->data == num){
      root->data = lastValue;
    }
    else{
      changeValue(root->left, num, lastValue);
      changeValue(root->right, num, lastValue);
    }
  }
}

Node* findValue(Node* root, int num){
  int lastValue = getLast(root);
  changeValue(root, num, lastValue);
  return root;
}

string getDirections(Node* root, int location)
{
    //Determines and returns "directions" to location
  string directions = "";
  while(location > 1){
    if(location % 2 == 1){
      directions = "R" + directions;
    }
    else{
      directions = "L" + directions;
    }
    location /= 2;
  }
  return directions;
}

Node* updateHelper(Node* root, string directions, int newValue)
{
    //Uses "directions" to place new value
  if(directions.length() > 0){
    if(directions[0] == 'L'){
      return updateHelper(root->left, directions.substr(1), newValue);
    }
    else{
      return updateHelper(root->right, directions.substr(1), newValue);
    }
  }
  else{
    root->data = newValue;
    return root;
  }
}

Node* updateValue(Node* root, int location, int newValue)
{
    //
  string directions = getDirections(root, location);
  root = updateHelper(root, directions, newValue);
  return root;
}

void heapafy(Node* root)
{
    //Reorganizes tree to a proper tree
  int R = NULL;
  int L = NULL;
  if(root != nullptr){
    if(root->left != nullptr){
      heapafy(root->left);
      L = root->left->data;
    }
    if(root->right != nullptr){
      heapafy(root->right);
      R = root->right->data;
    }
    if(L > R && L > root->data){
      int temp = root->data;
      root->data = root->left->data;
      root->left->data = temp;
      heapafy(root->left);
    }
    else if(R > L && R > root->data){
      int temp = root->data;
      root->data = root->right->data;
      root->right->data = temp;
      heapafy(root->right);
    }
  }
}

Node* makeHeap(Node* root, int a[], int size, int currPos){
  int marker = currPos * 2;
  root = new Node(a[currPos]);
  if(currPos > size){}
  else if(marker < size){
    root->left = makeHeap(root->left, a, size, marker);
    root->right = makeHeap(root->right, a, size, marker + 1);
  }
  else if(marker == size){
    root->left = makeHeap(root->left, a, size, marker);
  }
  return root;
}

bool isMaxHeap(Node* root){
  if(root->right != nullptr){
    int D = root->data;
    int LD = root->left->data;
    int RD = root->right->data;

    bool left = isMaxHeap(root->left);
    bool right = isMaxHeap(root->right);
    bool rootB = root->data > root->left->data && root->data > root->right->data;
    return rootB && left && right;
  }
  else if(root->left != nullptr){
    int D = root->data;
    int LD = root->left->data;

    bool left = isMaxHeap(root->left);
    bool rootB = root->data > root->left->data;
    return rootB && left;
  }
  return true;
}

void inorder(Node* root) 
{
    if (root != nullptr)  // Or simply "if (root)"
    {
        inorder(root->left);
        cout << root->data << endl;
        inorder(root->right);
    }
}

void getValues(Node* root, int level){
  if(root == nullptr){
  }
  else if(level > 0){
    getValues(root->left, level - 1);
    getValues(root->right, level - 1);
  }
  else{
    cout << root->data << " ";
  }
}

void display(Node* root){
  int numNodes = getNumNodes(root);
  int a[numNodes];
  int height = getHeight(root);

  for(int i = 0; i < height; i++){
    getValues(root, i);
  }
}

int main(){
  int size, temp, numOps;
  cin >> size;
  int a[size + 1];
  
  for(int j = 1; j <= size; j++){
    cin >> temp;
    a[j] = temp;
  }
  
  Node* root = makeHeap(root, a, size, 1);
  if(isMaxHeap(root)){
    cout << "This is a heap." << endl;
  }
  else{
    cout << "This is NOT a heap." << endl;
    heapafy(root);
  }
  
  cin >> numOps;
  for(int i = 0; i < numOps; i++){
    string temp;
    cin >> temp;
    if(temp == "displayMax"){
      cout << root->data << endl;
    }
    if(temp == "display"){
        display(root);
        cout << endl;
    }
    if(temp == "insert"){
      int num;
      cin >> num;
      root = insert(root, num);
      if(!isMaxHeap(root)){
        heapafy(root);
      }
    }
    if(temp == "deleteMax"){
      root = deleteMax(root);
      if(!isMaxHeap(root)){
        heapafy(root);
      }
    }
    if(temp == "delete"){
      int temp;
      cin >> temp;
      findValue(root, temp);
      if(!isMaxHeap(root)){
        heapafy(root);
      }
    }
    if(temp == "update"){
      int location, newValue;
      cin >> location;
      cin >> newValue;
      updateValue(root, location, newValue);
      if(!isMaxHeap(root)){
        heapafy(root);
      }
    }
  }
}