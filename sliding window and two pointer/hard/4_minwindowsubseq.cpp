
#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

//same as prev, except return in order


string minwindowsubs(string str1, string str2){
    int i=0;
    int j=0;
    int k=0;
    
    int res=INT_MAX;
    string str="";

    while(j<str1.length() && k<str2.length()){
        if(str1[j]==str2[k]) k++;

        if(k==str2.length()){
            i=j;
            k=str2.length()-1;
            while(i>=0 && k>=0){
                if(str1[i]==str2[k]){
                    k--;
                }
                i--;
            }
            i++;
            if(res>j-i+1){
                res=j-i+1;
                str=str1.substr(i,j-i+1);
            }
            k=0;
            j=i+1;
        }

        j++;
    }

    return str;

}