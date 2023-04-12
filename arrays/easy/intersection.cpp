//repition of elements in the ifnal array is allowed 

//brute force approach 

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

vector<int> findArrayIntersection(vector<int> &A, int n, vector<int> &B, int m){
    vector<int> ans;
    int vis[m]={0};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i]==B[j] && vis[j]==0){
                ans.push_back(A[i]);
                vis[j]=1;
                break;
            }

            if(B[j]>A[i]) break;
        
        }
    }
    return ans;



}

//time complexity is O(nxm)
//space complexity is O(m)-> geenrally second array is taken smaller so that space complexity is less
