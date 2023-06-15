
#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;


string removeOuterParenthesis(string S){
    int cnt=0;
    string ans="";

    bool flag=true;

    for(int i=0;i<S.size();i++){

        if(S[i]=='(')cnt++;
        else if(S[i]==')') cnt--;

        if(cnt==1&&flag==true){
            flag=false;
            continue;
        }
        if(cnt==0&&flag==false){
            flag=true;
            continue;
        }

        ans+=S[i];

    }

    return ans;

}
