//count no of set bits

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

int noOfSetBits(int n){
    int count=0;
    while(n!=0){
        if(n&1==1){
            count++;
        }
        n=n>>1;
    }
    return count;

}

//tc is O(MSB)

//optimal-not much better, just slightly 

int noOfSetBitsOptimal(int n){
    int count=0;
    while(n!=0){
        n=n&(n-1);
        count++;
    }
    return count;

}