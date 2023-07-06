//insane qs


//any array questions that involve recursion- will be one of the 2 methods:
//1.pick/non pick method
//2.subsequence method(optimal for this question)




//each no may only be used once 
//no duplicate combinations
//return them in lexicogrphic order

//to make sur duplicate elements are not stored, create a set and then convert it to list of list



#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

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
        findCombination(ind+1,target-arr[ind],arr,ans,ds);//same index repitition not allowed
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
//slight modification in this code- store in set and then convert it to list of list 
//tc becomes (2^n)*k*logn



//OPTIMAL CODE 




//tc is 2^n and k for putting every combination in ds
//tc is (2^n)*k


//NOTE: sort the array first and then pass it

void findCombination(int ind,int target, vector<int>& arr,vector<vector<int>>&ans,vector<int>&ds){

    //base case
    if(target==0){
        ans.push_back(ds);
        return;
    }
    for(int i=ind;i<arr.size();i++){
        if(i>ind && arr[i]==arr[i-1])continue;//not the first element and repeated
        if(arr[i]>target)break;//since it is a sorted array
        ds.push_back(arr[i]);
        findCombination(i+1,target-arr[i],arr,ans,ds);
        ds.pop_back();

    }


}