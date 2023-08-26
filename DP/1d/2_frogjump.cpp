#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

//greedy does not work 

//try all possible ways- recursion 

//tc is O(n)
//sc is O(2n)

int f(int ind,vector<int>& heights,vector<int>& dp){
    if(ind==0)return 0;
    if(dp[ind]!=-1)return dp[ind];

    int left=f(ind-1,heights,dp)+abs(heights[ind]-heights[ind-1]);
    int right=INT_MAX;
    if(ind>1)int right=f(ind-2,heights,dp)+abs(heights[ind]-heights[ind-2]);
    return dp[ind]=min(left,right);
}



int frogJump(int n,vector<int>& heights){
    vector<int> dp(n+1,-1);
    return f(n-1,heights,dp);
}

//tabulation method- answer is always stored at last index 

int frogJump(int n,vector<int>& heights){
    vector<int> dp(n,0);
    dp[0]=0;
    for(int i=1;i<n;i++){
        int fs=dp[i-1]+abs(heights[i]-heights[i-1]);
        int ss=INT_MAX;
        if(i>1)ss= dp[i-2]+abs(heights[i]-heights[i-2]);
        dp[i]=min(fs,ss);
    }
    return dp[n-1];
}

//NOTE: if there is something like index-1 and index-2 in your code, there will always be a space optimization 

//optimization 

int frogJump(int n,vector<int>& heights){
    
    int prev=0;
    int prev2=0;
    
    for(int i=1;i<n;i++){
        int fs=prev+abs(heights[i]-heights[i-1]);
        int ss=INT_MAX;
        if(i>1)ss= prev2+abs(heights[i]-heights[i-2]);
        int curi=min(fs,ss);
        prev2=prev;
        prev=curi;

    }
    return prev;
}