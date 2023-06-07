//why does this remind me of insertion sort

/*

Given a sorted array Arr[](0-index based) consisting of N distinct integers and an integer k, the task is to find the index of k, if its present in the array Arr[]. Otherwise, find the index where k must be inserted to keep the array sorted.


*/


//sorted array, expected complexity logN-- binary search

//equivalent to finding lower bound


#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

//same code as lower bound!!

int lowerBound(vector<int> arr,int n,int x){
    int low=0, high=n-1;
    int ans=n;//default ans
    while(low<=high){
        int mid=(low+high)/2;
        //maybe an answer
        if(arr[mid]>=x){
            ans=mid;
            high=mid-1;

        }
        else{
            low=mid+1;//look for right
        }

    }
    return ans;

}