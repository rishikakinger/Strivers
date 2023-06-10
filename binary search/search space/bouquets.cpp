/*

To make one bouquet we need K adjacent flowers from the garden.
Here the garden consists of N different flowers, 
the ith flower will bloom in the bloomDay[i]. 
Each flower can be used inside only one bouquets. 
We have to find the minimum number of days need to wait to make M bouquets from the garden. 
If we cannot make m bouquets, then return -1.

*/



#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;


bool check(vector<int>&v, int m,int k, int mid){
    int totbouquets=0;
    int cnt=0;
    for(int i=0;i<v.size();i++){

        if(v[i]<=mid){
            cnt++;  
            if(cnt==k){
                totbouquets++;
                cnt=0;
            }          
        }
        else{
            cnt=0;//we are looking only for consecutive flowers
        }
    }
    if(totbouquets>=m) return true;
    return false;

}



int minDays(vector<int>& bloomDay, int m, int k){
    int low=0,high=INT_MAX-1;
    int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(check(bloomDay,m,k,mid)){
            ans=mid;
            high=low-1;

        }
        else{
            low=mid+1;
        }
    }
    return ans;

}

