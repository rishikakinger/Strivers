
//given list of integers, print sums of all subsets in it, in inc order

//brute: generate all subsets(power set)

//better: pick, not pick

//tc is 2^n+2^nlog2^n

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

void func(int ind,int sum,vector<int>& arr,int N,vector<int>& subSum){
    if(ind==N){
        subSum.push_back(sum);
        return;
    }

    func(ind+1,sum+arr[ind],arr,N,subSum);
    func(ind+1,sum,arr,N,subSum);

}


vector<int> subsetSum(vector<int> arr,int N){
    vector<int> subSum;
    func(0,0,arr,N,subSum);
    sort(subSum.begin(),subSum.end());
    return subSum;

}