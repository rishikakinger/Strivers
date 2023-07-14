//given an array(that may contain duplicates), return all possible subsets (no duplicates)
//tot no of subsets is no longer 2^n


//brute: generate all possible subsets (2^n), put them in a set, convert to vector of vector

//optimisation:everytime you call recursion, you generate a list of size 1, 2, etc
//at last recursion call, you generate a list of size n at owrst case (if there are repitions in the oriignal array, you stop before itself)

//tc is (2^n)*n
//sc is (2^n)*k  (no of subsets*avg length) + n (recursion)

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

void findSubsets(int ind,vector<int>& nums,vector<int>&ds,vector<vector<int>> ans){
    ans.push_back(ds);
    for(int i=ind;i<nums.size();i++){
        if(i!=ind&& nums[i]==nums[i-1]) continue;
        ds.push_back(nums[i]);
        findSubsets(i+1,nums,ds,ans);
        ds.pop_back();
    }

}

vector<vector<int>> subsetsum2(vector<int>& nums){
    vector<vector<int>> ans;
    vector<int> ds;
    sort(nums.begin(),nums.end());
    findSubsets(0,nums,ds,ans);
    return ans;

}