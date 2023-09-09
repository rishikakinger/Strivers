#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

//count subsets with sum k 

int f(int ind, int sum, vector<int> arr,vector<vector<int>> &dp){
    if(sum==0)return 1;
    if(ind==0)return (arr[ind]==sum);
    if(dp[ind][sum]!=-1)return dp[ind][sum];

    int notpick=f(ind-1,sum,arr,dp);
    int pick=0;
    if(arr[ind]<=sum)pick=f(ind-1,sum-arr[ind],arr,dp);
    return dp[ind][sum]=pick+notpick;
    
}

//wo memoization
//tc is 2^n (pick/not pick)
//sc is n

//memoization 
//dp[n][sum+1]
//tc o(nxsum)
//sc is o(nxsum)+n

//accoridng to question, array does not have any zeroes

//if zeroes are also present, final ans=pow(2,n)xoriginal ans returned by fnc, where n= no of zeroes 

//use following code if zeroes are also present 


int f1(int ind, int sum, vector<int> arr,vector<vector<int>> &dp){
    
    if(ind==0){
        
    }
    if(dp[ind][sum]!=-1)return dp[ind][sum];

    int notpick=f(ind-1,sum,arr,dp);
    int pick=0;
    if(arr[ind]<=sum)pick=f(ind-1,sum-arr[ind],arr,dp);
    return dp[ind][sum]=pick+notpick;
    
}
