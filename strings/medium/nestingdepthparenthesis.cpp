#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

int maxDepth(string S){
    int current_max=0;
    int max=0;
    int n=S.length();

    for(int i=0;i<n;i++){
        if(S[i]=='('){
            current_max++;
            if(current_max>max){
                max=current_max;
            }
        }
        else if(S[i]==')'){
            if(current_max>0) current_max--;
            else return -1;//unbalanced paranthesis
        }

    }
    if(current_max!=0) return -1;//unbalanced parenthesis
    return max;

}