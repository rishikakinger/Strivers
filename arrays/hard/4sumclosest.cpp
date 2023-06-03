//sum 4 diff indexes to get target value

/*
BRUTE FORCE: try out all quads, return ones that give target

*/

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<map>
using namespace std;


vector<vector<int>> fourSum(vector<int>&nums, int target){
    int n=nums.size();
    set<vector<int>> st;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                for(int l=k+1;l<n;l++){
                    long long sum=nums[i]+nums[j];
                    sum+=nums[k];
                    sum+=nums[l];
                    //add it like this to avoid overflow
                    if(sum==target){
                        vector<int> temp={nums[i],nums[j],nums[k],nums[l]};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);//HAVE TO USE ST.INSERT() NOT ST.PUSH_BACK();
                    }
                }
            }
        }
    }
    vector<vector<int>>ans(st.begin(),st.end()); 

}

//time complexity O(n^4)

