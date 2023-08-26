#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

//at most k jumps a t each step



int helper(int n, int k, vector<int> &heights, vector<int>& dp) {
	if(n == 0) return 0;
    if(dp[n]!=-1)return dp[n];

	int minSteps = INT_MAX;

	for(int j=1; j<=k; j++) {
		int l = INT_MAX;
		if(n-j >= 0)
			l = helper(n-j, k, heights,dp) + abs(heights[n] - heights[n-j]);
		minSteps = min(minSteps, l);
	}
    dp[n]=minSteps;

	return minSteps;
}

//tc is o(n*k)