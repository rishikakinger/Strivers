//brute force O(n)

//searhc in a sorted array-bs

//implementing lower and upper bound



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

pair<int,int> firstAndLastPosition(vector<int>&arr,int n, int k){
    int lb=lowerBound(arr,n,k);
    if(lb==n||arr[lb]!=k) return {-1,-1};
    return {lb,upperBound(arr,n,k)-1};
}

//time complexity 2*O(logn)
 
