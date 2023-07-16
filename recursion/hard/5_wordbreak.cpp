
//popular question

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

bool wordBreak(string s,vector<string> wordDict){
    if(find(wordDict.begin(),wordDict.end(),s)!=wordDict.end()){
        return true;
    }

    for(int i=1;i<=s.length();i++){
        string left=s.substr(0,i);
        if(find(wordDict.begin(),wordDict.end(),left)!=wordDict.end() && wordBreak(s.substr(i),wordDict)){
            return true;
        }
    }
    return false;

}

//using dp 

unordered_map<string,bool> mpp;

bool wordBreak1(string s,vector<string> wordDict){
    if(find(wordDict.begin(),wordDict.end(),s)!=wordDict.end()){
        return true;
    }

    if(mpp.find(s)!=mpp.end()) return mpp[s];

    for(int i=1;i<=s.length();i++){
        string left=s.substr(0,i);
        if(find(wordDict.begin(),wordDict.end(),left)!=wordDict.end() && wordBreak1(s.substr(i),wordDict)){
            mpp[s]=true;
            return true;
        }
    }
    mpp[s]=false;
    return false;

}