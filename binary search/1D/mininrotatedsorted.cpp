//brute: O(N)

//find sorted and unsorted halfs, compare with lowest of sroted part
//sorted part is now useless
//move to unsorted and repeat the steps


#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;


int findMin(vector<int>&arr){
    int low=0,high=arr.size()-1;
    int ans=INT_MAX;
    while(low<=high){
        int mid=(low+high)/2;
        //if left side is sorted
        if(arr[low]<=arr[mid]){
            ans=min(ans,arr[low]);
            low=mid+1;

        }

        //right side is sorted
        else{
            ans=min(ans,arr[mid]);
            high=mid-1;
        }

    }
    return ans;

}