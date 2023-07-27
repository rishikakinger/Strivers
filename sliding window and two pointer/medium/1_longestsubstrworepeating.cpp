

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

//brute: use kadane's to find all substrings, use set to hash
//tc O(n^3)--> O(n^2)
//sc O(n)


//sliding window approach 
//tc O(2n)
//sc O(n)(uses a set)


//optimal:use a map 
//optimise on worst case, eg. asdfghjj
//tc is O(n)
//sc is O(n)

int lengthOfLongestSubstring(string s){
    map<char,int> mpp;

    int left=0,right=0;
    int n=s.size();
    int len=0;

    while(right<n){
        if(mpp[s[right]]!=-1) left=max(mpp[s[right]]+1,left);//if it lies to left, no need to update

        mpp[s[right]]=right;//update map

        len=max(len,right-left+1);
        right++; 

    }
    return len;

}

