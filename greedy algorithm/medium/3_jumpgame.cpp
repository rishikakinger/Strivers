#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

//return min no of jumps to reach end 

int jump(vector<int>& nums){

    int ans=0;//keeps track of jumps
    int n=nums.size();

    int currEnd=0;//keeps track of no of jumps remainign of prev
    int currFar=0;//keeps track of farthest you can reach 

    if(nums[0]==0)return 0;

    for(int i=0;i<n-1;i++){
        currFar=max(currFar, nums[i]+i);

        if(currEnd==i){
            ans++;
            currEnd=currFar;
        }
    }
    return ans;


}

//NOTE: assume you can reach end everytime 
