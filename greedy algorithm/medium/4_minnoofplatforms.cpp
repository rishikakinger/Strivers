#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

//find min no of platforms required for the station such that no trian is kept waiting 

//step 1: sort the starting and ending time SEPARATELY 

//tc is 2nlogn to sort 2 arrays+2n for both pointers

//sc is O(1)

int findPlatform(int arr[],int dep[],int n){

    sort(arr,arr+n);
    sort(dep,dep+n);

    int plat_needed=1;
    int result=1;

    int i=1;
    int j=0;

    while(i<n && j<n){
        if(arr[i]<=dep[j]){
            plat_needed++;
            i++;
            result=max(result,plat_needed);

        }
        else if(arr[i]> dep[j]){
            plat_needed--;
            j++;
        }
    }
    return result;



}