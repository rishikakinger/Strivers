//2 no.s appear odd times, find the no.s

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

vector<int> twoOddNum(vector<int> arr){
    int n=arr.size();
        vector<int> ans;
    int xor1=0;
    for(int i=0;i<n;i++){
        xor1=xor1^arr[i];

    }
    
    int count=0;
    while(xor1){
        if(xor1 & 1){
            break;
        }
        count++;
        xor1=xor1>>1;
    }

    int xor2=0;
    int xor3=0;


    for(int i=0;i<n;i++){
        if(arr[i]&(1<<count)){
            xor2=xor2^arr[i];
        }
        else{
            xor3=xor3^arr[i];
        }

    }
    ans.push_back(xor2);
    ans.push_back(xor3);
    sort(ans.rbegin(),ans.rend());
    return ans;
}