//OPTIMAL APPROACH 
//2 POINTER APPROACH+GREEDY APPROACH 

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<map>
using namespace std;

int longestSubarrayWithSumK(vector<int> a, long long k){
    int left=0,right=0;
    long long sum=a[0];
    int maxlen=0;
    int n=a.size();
    while(right<n){
        while(left<=right&&sum>n){
            sum-=a[left];
            left++;
        }
        if(sum==k){
            maxlen=max(maxlen, right-left+1);
        }
        right++;
        if(right<n)  sum+=a[right];//imp to check
    }
    return maxlen;
}
//TIME COMPLEXITY IS NOT O(N^2), IT IS O(2N)
//use window approach for all consecutive problem qs 