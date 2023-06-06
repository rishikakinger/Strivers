
//no of pairs where left element is greater than right 
//this qs is hard



/*
BRUTE FORCE

cnt=0;
for(i=0 to n-1){
    for(j=i+1;j<n;j++){
        if(a[i]>a[j]){
            cnt++;
        }

    }
    
}

*/



//optimal is to use merge sort
//in process you end up soritng the array as well



//low, mid;mid+1,high
//IN INTERVIEWS IT IS HIGHLY DISCOURAGED TO USE GLOBAL VARIABLES


#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<map>
using namespace std;




//copy paste merge sort code

int merge(vector<int> &arr,int low,int mid, int high){
    vector<int> temp; //uses temporary array
    int left=low;
    int right=mid+1;
    
    int cnt=0;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }

        else{
            temp.push_back(arr[right]);
            //right is smaller
            cnt+=(mid+left-1); //no need to iterate again
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
    return cnt;


}


int mergeSort(vector<int> &arr,int low, int high){
    int cnt=0;
    if(low>=high){
        return cnt;
    }
    int mid=(low+high)/2;
    cnt+=mergeSort(arr,low,mid);
    cnt+=mergeSort(arr,mid+1,high);
    cnt+=merge(arr,low,mid,high);
    return cnt;
}

int numberOfInversions(vector<int> &a, int n){
    return mergeSort(a,0,n-1);
    
}

//time complexity is nlogn
//space is n, but you are altering the array