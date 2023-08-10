//brute force is O(N^2)

#include<vector>
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

    vector<int> leaders(int a[], int n){
        vector<int> ans;
        int greatest=a[n-1];
        for(int i=n-1;i>=0;i--){
            if(a[i]>=greatest) ans.push_back(a[i]);
            greatest=max(greatest,a[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
//time complexity O(N)
//time complexity of reverse is O(N)