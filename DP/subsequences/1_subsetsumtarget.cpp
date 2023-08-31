#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

//subsequence-can be non contiguous 
//BUT NEEDS TO FOLLOW ORDER 


int f(int ind, int target,vector<int> a,vector<vector<int>>& dp){
    if(target==0)return true;
    if(ind==0)return (a[0]==target);
    if(dp[ind][target]!=-1)return dp[ind][target];

    bool nottake=f(ind-1,target,a,dp);
    bool take=false;
    if(target>=a[ind]){
        take=f(ind-1,target-a[ind],a,dp);
    }
    return dp[ind][target]=take|nottake;//we are ok wiht any 1 path


}

//recursion 
//tc is 2^n
//sc is n 

//dp 
//tc nxtarget
//sc is nx target+ n 

