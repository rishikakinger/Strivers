//nothing but first occurence-last occurence+1
#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;


//copy paste lower bound and upper bound code

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

int upperBound(vector<int> arr,int n,int x){
    int low=0, high=n-1;
    int ans=n;//default ans
    while(low<=high){
        int mid=(low+high)/2;
        //maybe an answer
        if(arr[mid]>x){//only small change in this line
            ans=mid;
            high=mid-1;

        }
        else{
            low=mid+1;//look for right
        }

    }
    return ans;

}

//main code

int noOfOccurences(vector<int>&arr,int n, int k){
    int lb=lowerBound(arr,n,k);
    if(lb==n||arr[lb]!=k) return -1;
    return upperBound(arr,n,k)-1-lb+1;
}
