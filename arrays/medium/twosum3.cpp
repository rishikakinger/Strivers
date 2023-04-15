//gfg question
//when there are 2 diff arrays 

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;



class Solution{
    public:
        vector<pair<int,int>> allPairs(int A[], int B[], int N, int M, int X){
    
        unordered_map<int, int> mp2;
        vector<pair<int, int>> vp;
        sort(A,A+N);
    	    
        for(int i = 0;i<M;i++)
            mp2[B[i]]++;
        
        for(int i = 0;i<N;i++){
            if(mp2[X-A[i]] >= 1){
                vp.push_back({A[i],X-A[i]});
            }
        }
        return vp;
    }
};