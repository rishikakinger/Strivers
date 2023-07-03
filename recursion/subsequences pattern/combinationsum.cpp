#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

//pick non-pick mentality
//tc is exponenetial 2^ something 
//tc is 2^k+t
//sc is non predictable, depends on no of combinations 

//dont use sum variable, instead ask what are we missing?


void findCombination(int ind, int target, vector<int>&arr,vector<vector<int>>&ans,vector<int>& ds){
    if(ind==arr.size()){
        if(target==0){
            ans.push_back(ds);
        }
        return;

    }

    //pick up the element
    if(arr[ind]<=target){//imp condition
        ds.push_back(arr[ind]);
        findCombination(ind,target-arr[ind],arr,ans,ds);//same index repitition allowed
        ds.pop_back();

    }
    //not pick up the element
    findCombination(ind+1,target,arr,ans,ds);

}





vector<vector<int>> combinationSum(vector<int>& candidates, int target){
    vector<vector<int>> ans;
    vector<int> ds;
    findCombination(0,target,candidates,ans,ds);
    return ans;

}