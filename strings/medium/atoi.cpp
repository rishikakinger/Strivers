
//last character of string is null by default

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

int atoi(string str)
{
    
    int result=0;   
    int i=0;    
    int sign = 1;   
    if(str[i]=='-') //in case it is negative
    {
        sign = -1;
        i++;
    }
    
    while(str[i])//cond for traversing through string-->imp
    {
        //If any character is not an integer 
        if(!(str[i]-'0'>=0 && str[i]-'0'<=9))
            return -1;
        
        result = result*10 + str[i]-'0';
        i++;
    }
    return result*sign;
}