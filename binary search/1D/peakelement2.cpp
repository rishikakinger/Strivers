//bs is alwys used when we want to eliminate one half



#include<iostream>

using namespace std;

int peakElement(int arr[], int n) {
    int l=0, h=n-1;
    int mid;
    while(l<=h){
        mid=(l+h)/2;
        //if mid=0 or n-1, simply return mid-- v imp point
        if((mid==0||arr[mid-1]<=arr[mid])&& (mid==n-1||arr[mid+1]<=arr[mid])){//imp line to understand
            return mid;
        }
        else if(mid>0&&arr[mid-1]>arr[mid]){
            h=mid-1;
        }
        else l=mid+1;


    }
    return mid;

}

//also note, binary search method works here only bc we have to return any ONE peak element
