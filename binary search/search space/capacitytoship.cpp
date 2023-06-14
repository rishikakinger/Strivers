//form where to where will capacity range?
//min capacity for ship is max(weight)
//max capacity will be sum(weights)
//now we have our search space



//brute force solution is O(n^2)

//how to know if it is a binary search problem?
//qs has capacity that has lower bound
//ask yourself-does it have upper bound? if ans is yes, youve got your search space!



#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;


class Solution {
  public:
  
  
    bool check(int arr[],int n, int mid, int D){
            int days=1;//imp: start days with 1 
            int currcapacity=0;
            for(int i=0;i<n;i++){
                if(currcapacity+arr[i]<=mid){//imp:check before adding
                    currcapacity+=arr[i];
                }
                else if(arr[i]<=mid){
                    days++;
                    currcapacity=arr[i];
                }
                else{
                    return false;
                }
            }
            return days<=D;
    }
    
    int leastWeightCapacity(int arr[], int n, int D) {
        int high=0;
        for(int i=0;i<n;i++){
            high+=arr[i];
        }
        int low=*max_element (arr, arr+n);
        int ans=INT_MAX;

        
        while(low<=high){
            int mid=(high+low)/2;
            
            //check if it satisfies cond
            if(check(arr,n,mid,D)){
                ans=min(mid,ans);
                high=mid-1;
            }
            else{
                low=mid+1;
            }
            
        }
        return ans;
    }
};













//time complexiy is O(nxlogM)
//M is sum of the input array