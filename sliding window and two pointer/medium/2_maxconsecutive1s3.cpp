#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

int longestOnes(vector<int>& nums, int k){
    int i=0;
    int j=0;
    int n=nums.size();
    int countZeroes=0;
    int ans=INT_MIN;

    while(j<n){
        if(nums[j]==0){
            countZeroes++;
        }
        while(countZeroes>k){
            if(nums[i]==0){
                countZeroes--;
            }
            i++;

        }

        ans=max(ans,j-i+1);
        j++;
    }

    return ans;

}