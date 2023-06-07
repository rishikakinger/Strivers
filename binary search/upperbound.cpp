
//smallest index such that arr[ind]>n

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;


int lowerBound(vector<int> arr,int n,int x){
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
//time complexity O(log2n)
/*

C++ HACK

lb=upper_bound(arr.begin(),arr.end(),x);



*/