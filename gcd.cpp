#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
  int size;
  cin >> size;
  for (int i = 0; i < size; i++) {
    int a,b,c;
    cin >> a >> b >> c;
    int final = pow(a,(b-a))+pow(b,(b-a));
    int result = gcd(c,final);
    cout <<  result << endl;
  }
  return 0;
}
