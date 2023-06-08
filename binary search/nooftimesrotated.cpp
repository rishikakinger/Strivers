//find out no of times an array has been right rotated
//nothing but index of min element

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;


int findMin(vector<int>&arr){
    int low=0,high=arr.size()-1;
    int ans=INT_MAX;
    int index=-1;
    while(low<=high){
        int mid=(low+high)/2;
        //if left side is sorted

        if(arr[low]<=arr[high]){
            //already sorted
            //rotated by 0
            if(arr[low]<ans){
                index=low;
                ans=arr[low];

            }
            break;
        }





        if(arr[low]<=arr[mid]){
            if(arr[low]<ans){
                index=low;
                ans=arr[low];

            }
            low=mid+1;

        }

        //right side is sorted
        else{
                if(arr[mid]<ans){
                index=mid;
                ans=arr[mid];

            }

            high=mid-1;
        }

    }
    return index;

}