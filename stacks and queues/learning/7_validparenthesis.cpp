
#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;


bool isValid(string s) {
        stack<int> myStack;
        for(int i=0;i<s.size();i++){
            if(myStack.empty()){
                myStack.push(s[i]);
                continue;

            }
            if((myStack.top()=='('&& s[i]==')')||(myStack.top()=='['&& s[i]==']') || (myStack.top()=='{'&& s[i]=='}'))myStack.pop();
            else{
                myStack.push(s[i]);
            }
        }
        return myStack.empty();
    }

    //tc O(n) sc O(n)