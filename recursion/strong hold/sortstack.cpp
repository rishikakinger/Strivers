
#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

void sorted(stack<int> &s,int n){
    if(n<=1) return;

    int topele=s.top();//what you have to insert
    s.pop();
    sorted(s,n-1);
    stack<int> dummy;
    while(!s.empty() && s.top()>topele){
        dummy.push(s.top());
        s.pop();
    }
    s.push(topele);
    while(dummy.size()){
        s.push(dummy.top());
        dummy.pop();
    }
    return;

}
//tc is O(n^2)
//sc is O(n)