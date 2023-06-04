//Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

//brute
//how to generate all subarrays? - revisit kadanes algorithm
//will be of O(n^3)



//optimal approach is to use hashing 
//same as focus on negatives- s=s+0
//DONT INSERT (0,1) INTO THE SET HERE
//little diff than the other qs in general 


#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<map>
using namespace std;

int maxLen(int A[], int n){
    unordered_map<int, int> mpp;
    int maxi=0;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=A[i];
        if(sum==0){//imp
            maxi=i+1;
        }
        else{
            if(mpp.find(sum)!= mpp.end()){
                maxi=max(maxi,i-mpp[sum]);
            }//if subarr found, dont add it to the hashmap
            else{
                mpp[sum]=i;
            }
        }
    }
    return maxi;

}

//time complexity is  O(NlogN)
//space complexity is O(N)