//find no appearing odd no of times

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

int missingNumber(int n, vector<int> &arr){
    int xor1=0;
    for(int i=0;i<n;i++){
        xor1=xor1^arr[i];

    }
    return xor1;
}