//is character hashing possible? YES!!!!
//eg. "abcdafc", how many times has a appeared? how many times has c appeared?

//consider only lower case characters, english alphabet has 26 alphabets
//a-->0th index, b-->1st index, etc

//int n=a; 97 will be stored in n
//z--->122
//256 characters in total- unlike numbers there will be no porblem with characters as 256 is max 



#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
    string s;
    cin>>s;

    //precompute
    int hash[26]={0};

    for(int i=0;i<s.size();i++){
        hash[s[i]-'a']++;

    }

    int q;
    cin>>q;
    while(q--){
        char c;
        cin>>c;
        cout<<hash[c-'a']<<endl;


    }



}