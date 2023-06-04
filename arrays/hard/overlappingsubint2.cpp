//why are you traversing every element twice?



#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<map>
using namespace std;

vector<vector<int>>mergeOverlappingIntervals(vector<vector<int>> &arr){
    int n=arr.size();
    sort(arr.begin(),arr.end());//first sort the entire array
    //sorting is done accoridng to the first index, if tie then second index 

    vector<vector<int>> ans;
    for(int i=0;i<n;i++){
        if(ans.empty()||arr[i][0]>ans.back()[1]){
            ans.push_back(arr[i]);
        }
        else{
            ans.back()[1]=max(ans.back()[1],arr[i][1]);
        } 
        }

    return ans;

}
//nlogn+n
