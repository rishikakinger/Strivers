//Much more optimised than insertion, bubble and selection sort.
//based on principle of divide and merge 
//instead of making new arrays each time, smarter to play with indexes and keep low, high pointers

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;


void merge(vector<int> &arr,int low,int mid, int high){
    vector<int> temp; //uses temporary array
    int left=low;
    int right=mid+1;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
            left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
            right++;

    }
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }




}






void ms(vector<int> &arr,int low, int high){
    if(low>=high){
        return;
    }
    int mid=(low+high)/2;
    ms(arr,low,mid);
    ms(arr,mid+1,high);
    merge(arr,low,mid,high);
}

