//You are given an array consisting of n integers which denote the position of a stall. You are also given an integer k which denotes the number of aggressive cows. You are given the task of assigning stalls to k cows such that the minimum distance between any two of them is the maximum possible.
//no of cows given
//dist given
//to find: largets minimal distance


//brute force soln: O(n^2)- one for loop for distnce, other for loop for checking


//search space starts from 1 
//ends at max(arr)-min(arr)



#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

//array might be unsorted- sort it 


bool canPlaceCows(int mid, vector<int> stalls,int n, int k){

    int noofcows=1;
    //greedy way is to place the first cow at arr[0]
    int coord=stalls[0];//most recent coord

    for(int i=0;i<n;i++){
        if(stalls[i]-coord>=mid){
            noofcows++;
            coord=stalls[i];
        
        }
        if(noofcows==k) return true;
    }
    return false;


}





int solve(int n, int k, vector<int> &stalls) {
    sort(stalls.begin(),stalls.end());
    int low=1;
    int high=stalls[n-1]-stalls[0];
    int res=1;
    while(low<=high){
        int mid=(low+high)>>1;
        if(canPlaceCows(mid,stalls,n,k)){
            res=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }

    }
    return res;
}

//tc is O(NlogN)