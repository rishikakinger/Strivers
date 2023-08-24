#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

//suppose you are to compute f(5)
//at max- f(0) to f(5)
//memoization array of size 6(0-5)

//step 1: declare dp array 
//step 2: always store ans to subprobelms 
//step 3: check if prob has been previosuly solved, if yes, return early 

int f(int n,vector<int>& dp){
    if(n<=1)return n;
    if(dp[n]!=-1)return dp[n];
    return dp[n]=f(n-1,dp)+f(n-2,dp);

}


int fib(int n){
    vector<int> dp(n+1,-1);
    return f(n,dp);
}

//tc is o(n)
//sc is o(n) for rec stack space+ o(n) for array


//TABULATION FORMAT:BOTTOM UP APPROACH
//recursion is top down 

//tc is o(n)
//sc is o(n)- better than memoization since no rec stack space
/*
dp[0]=0;
dp[1]=1;

for(int i=2;i<=n;i++){
    dp[i]=dp[i-1]+dp[i-1];
}


*/