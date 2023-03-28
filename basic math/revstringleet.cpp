#include<bits/stdc++.h>
#include<iostream>
using namespace std;


class Solution {
public:
   string lower(string s){
        for(int i=0;i<s.length();i++){
            if(s[i]>='A'&&s[i]<='Z')
                s[i]=s[i]-'A'+'a';
        }
        return s;
    }
    string remove(string s){
        string temp;
        for(int i=0;i<s.length();i++){
            if(s[i]>='a'&&s[i]<='z'||s[i]>='0'&&s[i]<='9'){
                temp+=s[i];
            }
        }
        s=temp;
        return s;
    }
    bool isPalindrome(string s) {
        
        s=lower(s);
        cout<<s<<endl;
        
        s=remove(s);
        cout<<s;
       
        int st=0;
        int e=s.length()-1;
        while(st<e){
            if(s[st]!=s[e])
                return false;
            st++;
            e--;
        }
        return true;
    }
};