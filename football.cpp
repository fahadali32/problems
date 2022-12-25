#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
  int size;
  cin >> size;
  int a,b;
  char ch;
  for (int i = 0; i < size; i++) {
    cin >> a >> b;
    ch = b+96;
    char final = toupper(ch);
    if (a == 1) {
      cout << "Unmarried-" << ch << endl;
    }else {
      cout << "Married-" << final << endl;
    }
  }
  return 0;
}
