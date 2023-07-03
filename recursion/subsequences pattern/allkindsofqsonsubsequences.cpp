#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

void printsum(int ind,vector<int>& ds,int s,int sum, int arr[],int n){

    if(ind==n){
        if(s==sum){
            //print the subseq
        }
        return;
    }

    ds.push_back(arr[ind]);
    s+=arr[ind];

    printsum(ind+1,ds,s,sum,arr,n);
    s-=arr[ind];
    ds.pop_back();

    printsum(ind+1,ds,s,sum,arr,n);

}

//what if e have to return only one such subsequence?

bool printsum2(int ind,vector<int>& ds,int s,int sum, int arr[],int n){

    if(ind==n){
        if(s==sum){
            //print the subseq
            return true;
        }
        return false;
    }

    ds.push_back(arr[ind]);
    s+=arr[ind];

    if(printsum2(ind+1,ds,s,sum,arr,n)==true){
        return true;
    }
    s-=arr[ind];
    ds.pop_back();

    if(printsum2(ind+1,ds,s,sum,arr,n)) return true;
    return true;

}

//what if we just want the count of subsequences?

int printsum3(int ind,int s,int sum, int arr[],int n){//dont need the data structure anymore

    if(ind==n){
        if(s==sum){
            //print the subseq
            return 1;
        }
        return 0;
    }

    
    s+=arr[ind];

    int l= printsum3(ind+1,s,sum,arr,n);
    s-=arr[ind];
   
    int r=printsum3(ind+1,s,sum,arr,n);
    return l+r;

}