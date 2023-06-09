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

//time complexity is O(logn)

//OVERFLOW CASE

/*


if high=INT_MAX;

if low also becomes equal to INT_MAX;
mid=(INT_MAX+INT_MAX)/2
which CANNOT be stored in an integer!!!

take long long or mid=low+(high-low)/2

*/