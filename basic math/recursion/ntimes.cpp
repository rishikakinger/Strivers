#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
  public:
    void printGfg(int N) {
        if(N<1){
            return;
        }
        cout<<"GFG ";
        printGfg(N-1);
    }
};