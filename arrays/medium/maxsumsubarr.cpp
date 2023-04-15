//brute, better same as prev 
//KADANE'S ALGORITHM 

//-3>-5, dont be stupid 
//works for negatives as well


#include<bits/stdc++.h>
#include<iostream>
#include<vector>

using namespace std;

long long maxSubarraySum(int arr[], int n){
    long long sum=0, maxi=LONG_MIN;
    for(int i=0;i<n;i++){
        sum+=arr[i];

        if(sum>maxi){
            maxi=sum;
        }


        if(sum<0){
            sum=0;
        }
    }
}

//time complexity O(N), space comeplexity O(1)