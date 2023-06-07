//recursive code

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

int bs(vector<int> &nums, int low, int high, int target){
    if(low>high) return -1;
    int mid=(low+high)/2;
    if(nums[mid]==target)return mid;
    else if(target>nums[mid]) return bs(nums,mid+1,high,target);
    return bs(nums,low,high-1,target); 


}

