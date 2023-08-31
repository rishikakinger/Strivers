#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

//if sum of subset 1 is s1 and sum of subset 2 is s2
//s1=s2=s/2
//so if s is odd->not possible
//so if you can find subset of elements with sum s1 then job is done 

//same as prev 


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

bool canPartition(vector<int>& arr,int n){
    int sum=0;
    for(int i=0;i<n;i++)sum+=arr[i];
    if(sum%2!=0)return false;
    vector<vector<int>> dp(n,vector<int>(sum/2+1,-1));
    return f(n,sum/2,arr,dp);

}