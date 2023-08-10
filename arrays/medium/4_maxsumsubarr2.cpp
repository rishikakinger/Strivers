//print the indexes as well

#include<bits/stdc++.h>
#include<iostream>
#include<vector>

using namespace std;

long long maxSubarraySum(int arr[], int n){
    long long sum=0, maxi=LONG_MIN, start, ansStart, ansEnd;
    for(int i=0;i<n;i++){
        if(sum==0) start=i;
        sum+=arr[i];

        if(sum>maxi){
            maxi=sum;
            ansStart=start;
            ansEnd=i;

        }


        if(sum<0){
            sum=0;
        }
    }
}