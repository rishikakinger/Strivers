//using map instead of array
//more space efficient 

#include<bits/stdc++.h>
#include<iostream>
#include<map>//map library

using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    //NOTE: you can precompute while taking input also, that will save you 1 for loop
    //not saving you much as it is N+N and not N*N


    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    //precompute
    map<int, int> mpp;
    //for maps, dont have declare length- more useful than arrays
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }
    //NOTE: map stores all values in sorted order

    int q;
    cin>>q;
    while(q--){
        int number;
        cin>>number;
        cout<< mpp[number]<<endl;
    }
}