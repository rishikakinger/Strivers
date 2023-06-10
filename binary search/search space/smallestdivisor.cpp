#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;


double check(vector<int>&v, int mid){
    double sum=0;
    for(int i=0;i<v.size();i++){
        sum+=ceil((double)(v[i]/mid)); //put brackets around double dumbass
    }
    return sum;


}


int smallestDivisor(vector<int>& v, int k){
    int low=0,high=INT_MAX-1;
    int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(check(v,mid)<=k){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }

    }
    return ans;

}