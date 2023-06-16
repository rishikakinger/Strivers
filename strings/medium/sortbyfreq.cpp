
//NOTE(IMP): A MAP IN CPP IS ALWAYS SORTED BASED ON INC ORDER OF KEY, NOT VALUE AND THERE IS NO WAY TO SORT BASED ON VALUE




#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

string frequencySort(string s){
    string ans="";
    unordered_map<char,int> charFrequency;

    for(int i=0;i<s.size();i++){
        charFrequency[s[i]]++;
    }

    //store the characters and their frequenices in  a vector of pairs

    vector<pair<int,int>> freqPairs;

    for(auto it: charFrequency){
        freqPairs.push_back({it.second,it.first});
    }

    sort(freqPairs.begin(),freqPairs.end());

    for(auto x:freqPairs){
        int a=x.first;
        while(a--){
            ans+=x.second;
        }
    }
    return ans;


}