//Given a sorted array arr[] of size N. Find the element that appears only once in the array. All other elements appear exactly twice

//in general, in qs be careful if qs says return inde or the element itself 

//brute force is O(n)

//either left or right has to be equal to the element, check separately for first and last index

//(even, odd)->element is on right
//(odd,even)->element is on left





#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

int singleNonDuplicate(vector<int> &arr){
    int n=arr.size();
    if(n==1) return arr[0];
    if(arr[0]!=arr[1]) return arr[0];
    if(arr[n-1]!=arr[n-2]) return arr[n-1];
    int low=1, high=n-2; //search spce successfully trimmed down
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]!=arr[mid+1]&&arr[mid]!=arr[mid-1]){
            return arr[mid];
        }

        //we are in left 
        if((mid%2==1 && arr[mid]==arr[mid-1])||(mid%2==0 && arr[mid]==arr[mid+1]) ){
            low=mid+1;

        }
        //we are on right

        else{
            high=mid-1;
        }

    }
    return -1;

}