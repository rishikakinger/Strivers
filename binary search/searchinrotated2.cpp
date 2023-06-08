//may contain duplicates

//if low=mid=high---> problem, logic for checking if sorted wont work anymore
//trim down search space

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

bool searchInARotatedSortedArray(vector<int> &arr,int k){
    int n=arr.size();
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==k) return true;
        if(arr[low]==arr[mid]&&arr[mid==arr[high]]){
            //problem
            low++,high--;
            continue;
        }
        //left side sorted 
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
    return false;

}

//more the duplicated, more the time complexity
//at worst O(n/2)
//avg case is logn only