#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

//partition an array into 2 subsets such that the absolute diff btw their sum is min

//minimal diff is 0, i.e same as prev qs

//qs solved using tabulation 

//if we check for a target k, we cna derive every possible target between 1 and k 

int minSubsetSumDifference(vector<int>& arr, int n){
    int totsum=0;
    for(int i=0;i<n;i++)totsum+=arr[i];

    vector<vector<bool>> dp(n,vector<bool>(totsum+1,0));
    for(int i=0;i<n;i++)dp[i][0]=true;
    if (arr[0]<=totsum)dp[0][arr[0]]=true;

    for(int ind=1;ind<n;ind++){
        for(int target=1;target<=totsum;target++){
            bool nottake=dp[ind-1][target];
            bool take=false;
            if(arr[ind]<=target)take=dp[ind-1][target-arr[ind]];
            dp[ind][target]=take| nottake;
        }
    }

    int mini=1e9;

    for(int s1=0;s1<=totsum/2;s1++){
        if(dp[n-1][s1]==true){
            mini=min(mini,abs(totsum-s1)-s1);
        }
    }
    return mini;


}
