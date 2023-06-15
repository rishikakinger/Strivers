

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;


bool isPossible(int barrier, int n, vector<int> arr,int M){
    int allocatedstudents=1;//index counting starts from zero but objects irl starts from 1

    int pages=0;
    for(int i=0;i<n;i++){
        if(arr[i]>barrier)return false;
        if(pages+arr[i]>barrier){
            allocatedstudents++;
            pages=arr[i];
        }
        else{
            pages+=arr[i];
        }

    }
    if(allocatedstudents>M) return false;
    return true;

}

int splitArray(vector<int>& arr, int M) {
    int low=*min_element(arr.begin(), arr.end()); 
    int n=arr.size();
    int high=0;
    int res=-1;
    if(n<M)return -1;
    for(int i=0;i<n;i++){
        high+=arr[i];
    }
    while(low<=high){
        int mid=(low+high)>>1;
        if(isPossible(mid, n, arr, M)){
            res=mid;
            high=mid-1;

        }
        else{
            low=mid+1;

        }
    }
    return res;

    }