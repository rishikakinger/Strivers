
//approach 1: reverse each string, and then reverse every word

//approach 2: store every word in a stack

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

string reverseWords(string S){
    stack<string> st;
    string s="";
    for(int i=0;i<S.size();i++){
        if(S[i]!='.'){
            s+=S[i];
        }
        if(S[i]=='.'){
            st.push(s);
            s="";

        }        
    }
    st.push(s);
    string res="";
    while(!st.empty()){
        string str=st.top();
        st.pop();
        st.pop();
        res+=str+".";
    }
    res.pop_back();
    return res;

}