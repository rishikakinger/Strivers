//if max no we can go till is 12, need array of 13, ie n+1 so we can store n element also

//in normal searching, time complexity is O(QN) where Q is no of queries 


#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
    int n;//array size
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    //precompute
    int hash[13]={0};//initialize all to zero


}