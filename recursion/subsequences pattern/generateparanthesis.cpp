
#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

void fnc(vector<string>&ans,int n,int open, int close, string curr_str ){
    //base case
    if(curr_str.length()==n*2) ans.push_back(curr_str);

    if(open<n)fnc(ans,n,open+1,close,curr_str+'(');
    if(close<open)fnc(ans,n,open,close+1,curr_str+')');

}



vector<string> generateParenthesis(int n){
    //we have to return a vector of strings

    vector<string> ans;
    fnc(ans,n,0,0,"");//initial no of opening and closing brackets
    return ans;

}