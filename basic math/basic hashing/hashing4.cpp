//FULL CHARACTER ARRAY

//code for 256 characters 

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
    string s;
    cin>>s;

    //precompute
    int hash[256]={0};

    for(int i=0;i<s.size();i++){
        hash[s[i]]++;//will autocast IMP

    }

    int q;
    cin>>q;
    while(q--){
        char c;
        cin>>c;
        cout<<hash[c]<<endl;


    }

}