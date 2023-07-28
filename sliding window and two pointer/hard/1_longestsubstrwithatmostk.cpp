
#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

int kDistinctChars(int k, string &str)
{
    int longest=0;
   
    int left=0;
    int right=0;
    unordered_map<char,int> distinctchars;
    while(right<str.size()){
        //add rightmost in map
        distinctchars[str[right]]++;

        while(distinctchars.size()>k){
            if(distinctchars.count(str[left])==1){
                distinctchars[str[left]]--;
                if(distinctchars[str[left]]==0){
                    distinctchars.erase(str[left]);
                }
            }
            left++;
        }
        longest=max(longest,right-left+1);
        right++;

    }




    return longest;
}
