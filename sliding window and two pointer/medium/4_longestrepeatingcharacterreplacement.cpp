#include <unordered_set>
#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

int findMaxValueInMap(map<char, int>& myMap) {
    int maxValue = numeric_limits<int>::min(); // Initialize with the smallest possible integer

    for (const auto& pair : myMap) {
        if (pair.second > maxValue) {
            maxValue = pair.second;
        }
    }

    return maxValue;
}


int characterReplacement(string nums, int k) {
    map<char,int> mpp;
    int res=0;

    int l=0;
    for(int r=0;r<nums.size();r++){
        mpp[nums[r]]++;

        while((r-l+1)-findMaxValueInMap(mpp)>k){
            mpp[nums[l]]--;
            l++;
        }

        res=max(res,r-l+1);

    }






    return res;


}