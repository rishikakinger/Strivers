#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

//can be solved using dp/greedy

//initially positioned at first index 

//brute force: every possible path , O(n^n),(dp is optimisation)
//COME BACK TO THIS WHEN YOURE DOING DP

//greedy soln O(n)

//observation: if there is no 0, we can always reach the end 

//find max reachable jump for EVERY INDEX 


bool canReach(vector<int>& nums){

    int n=nums.size();
    int reachable=0;

    for(int i=0;i<n;i++){
        if(reachable<i)return false;//IMP

        reachable=max(reachable,i+nums[i]);
    }
    return true;

}