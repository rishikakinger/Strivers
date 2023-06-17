
//Given a string of lowercase alphabets, count all possible substrings (not necessarily distinct) that have exactly k distinct characters. 

/*brute force approach:
if length of substring is n, there can be n*(n+1)/2 possible substrings
O(n^3)-> to generate and check
*/ 

/*
optimal- use hash table
check no of unique chracters using hash table
O(n^2)
remove check step
*/

  
#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

int countkdist(string str,int k){
    int n=str.length();
    int res=0;
    int cnt[26];//store all characters from 'a' to 'z'

    for(int i=0;i<n;i++){
        int dist_cnt=0;

       //initialize array with zero
       memset(cnt,0,sizeof(cnt));//note: cnt.size() wont work, only way to initialize, mug it ip

       for(int j=i;j<n;j++){
        if(cnt[str[j]-'a']==0) dist_cnt++;
       
       cnt[str[j]-'a']++;

       if(dist_cnt==k) res++;
       }


    }
    return res;

}