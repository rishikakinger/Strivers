#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

// no of subsets is 2^n
//write decimal notation from 0-(2^n)-1
//convert to binary

    vector<vector<int>> subsets(vector<int>& arr) {
            vector<vector<int>> ans;
            int n=arr.size();

    for(int num=0;num<=((1<<n)-1);num++){
        vector<int> ds;
        for(int bit=0;bit<=(n-1);bit++){
            if( num & (1<<bit)){
                ds.push_back(arr[bit]);

            }
        }
        ans.push_back(ds);
    }


    return ans;
        
    }

    //tc is ((2^n)*n)
    //only acceptable when n is around 16-17