#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

//all houses arranged in a circle 
//first and last are now adjacent 
//whatever the ans is , it cannot contain first and last 
//leave out last element or first element and compute
//get 2 answers
//one of them will be the final ans 
//max of (ans1, ans2) is ans 



long long int solve(long long int i,vector<int> &v1,vector<long long> &dp){
    if(i == 0)    return v1[i];
    if(i < 0)     return 0;
    if(dp[i]!=-1)	return dp[i];
    
    long long int left = INT_MIN;
    long long int right = INT_MIN;

    left = solve(i-2,v1,dp)+v1[i];
    right = solve(i-1,v1,dp);

    return dp[i] = max(left,right);
}
long long int houseRobber(vector<int>& valueInHouse){
	long long int n = valueInHouse.size();
    vector<long long> dp(n,-1),dp1(n,-1);
    
    if(n==1)	return valueInHouse[n-1];
    
    long long int ans1 = solve(n-2,valueInHouse,dp);
    reverse(valueInHouse.begin(),valueInHouse.end());
    long long int ans2 = solve(n-2,valueInHouse,dp1);
    
    return max(ans1,ans2);
}