//Two strings str1 and str2 are called isomorphic if there is a one to one mapping possible for every character of str1 to every character of str2 while preserving the order.


//approach 1: use hashing


#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

bool isIsomorphic(string s, string t){
    int len=s.size();
    char seen[128]={};
    for(int i=0;i<len;i++){
        char c=s[i];
        if(!seen[c]){
            //chec if alrady taken
            for(char s:seen)if(s==t[i]) return false;
            seen[c]=t[i];
        }
        else if(seen[c]!=t[i]) return false;
    }
    return true;
}