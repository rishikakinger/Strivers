
#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

int stringToNumber(string str,int last){
    if(last==0){
        return str[last]-'0';
    }

    int smallAns= stringToNumber(str,last-1);

    int a=str[last]-'0';
    return smallAns*10+a;

}



int stringToNumber(string str){
    int len=str.length();
    return stringToNumber(str,len-1);

}