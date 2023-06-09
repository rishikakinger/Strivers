//rotated sorted array given 

//brute force:linear search

//search and sorted keywords tell you that you probably have to use binary search


/*
optimal

1.identify the sorted and unsorted parts
2.first check for sorted part and then unsorted

*/


//NOTE: in binary search, elimination is key

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

int search(vector<int>&arr,int n, int k){
    int low,mid,high;
    int low=0;
    int high=n-1;
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]==k) return mid;

        //if left side is sorted

        if(arr[low]<=arr[mid]){
            if(arr[low]<=k&&k<=arr[mid]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        else{
            if(arr[mid]<=k&&k<=arr[high]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
    }
    return -1;


}