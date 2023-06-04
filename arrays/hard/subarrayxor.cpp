//consider single elements also 

//brute time complexity O(N^3), 3 nested for loops-----> O(N^2)(better approach)

//better approach-HASHMAP
//x^k=XR
//x=XR^k
//(0,1) inserted initially
//(front XOR,cnt)


#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<map>
using namespace std;


int subarraysWithXorK(vector<int> a, int k){
    int xr=0;
    map<int,int> mpp;
    mpp[xr]++;//inserting {0,1}
    int cnt=0;

    for(int i=0;i<a.size();i++){
        xr=xr ^ a[i];
        int x=xr^k;
        cnt+=mpp[x];
        mpp[xr]++;

    }
    return cnt;
}

//acc to gfg can be done with dynamic programming
