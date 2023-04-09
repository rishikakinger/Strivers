// similar time complexity as merge sort, but doesnt use any extra array
// i.e it is an in-place algorithm!

// step1: given an array, pick a pivot element(can be any element)
// doesnt matter as youre placing it in its correct pos
// use the rule:smaller on the left, larger on the right
// take all smaller elements, put them on left; take all larger elements, put on right
//  repeat for all pivots


//in general, low-high pointers are used to avoid creating new arrays each time and preserve space complexity 

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;


int partition(vector<int> &arr, int low, int high){
    int pivot=arr[low];
    int i=low;
    int j=high;
    while(i<j){
        while(arr[i]<=pivot&&i<=high-1){
            i++;
        }
        while(arr[j]>pivot&&j>=low+1){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
        
    }
    swap(arr[low],arr[j]);
    return j;


}



void qs(vector<int> &arr,int low, int high){
    if(low<high){//for splitting the array
    int pIndex=partition(arr,low,high);
    qs(arr,low, pIndex-1);
    qs(arr,pIndex+1, high);

    }
}






vector<int> quickSort(vector<int> arr){
    qs(arr,0,arr.size()-1);
    return arr;
}