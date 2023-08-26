#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

//pick non pick concept 

int f(int n, vector<int> nums,vector<int>& dp){
    if(n==0)return nums[n];
    if(dp[n]!=-1)return dp[n];
    if(n<0)return 0;

    int pick=f(n-2,nums,dp)+nums[n];
    int notpick=f(n-1,nums,dp);



    return dp[n]=max(pick,notpick);

}

int maxNonAdjSum(vector<int>& nums){
    int n=nums.size();
    vector<int> dp(n,-1);
    return f(n-1,nums,dp);

}

