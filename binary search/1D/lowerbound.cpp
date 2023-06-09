
//implement lower bound
//smallest index, i.e if there are multiple, take the first appearing
//array is sorted and expected time complexity is O(logN)-- use bs


//eliminate right search space

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
//C++ HACK

/*

lb=lower_bound(arr.begin(),arr.end(),x)-arr.begin();


(returns iterator, to get index subrtract arr.begin())


*/


//time complexity is O(log2n)