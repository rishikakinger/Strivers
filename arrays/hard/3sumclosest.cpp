//Given an array A[] of N integers and an integer X. The task is to find the sum of three integers in A[] such that sum is zero

//also, keep in mind that we have to retun UNIQUE triplets(an element may appear more than once so)

//for maintaining uniqueness, a set data structure can be used 


//BRUTE FORCE SOLUTION

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<map>
using namespace std;

vector<vector<int>> triplet(int n, vector<int> &num){
    vector<vector<int>> ans;
    set<vector<int>> st;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(num[i]+num[j]+num[k]==0){
                vector<int> temp={num[i],num[j],num[k]};
                sort(temp.begin(),temp.end());//time complexity not counted as there are hardly 3 elements 
                st.insert(temp);
                //will make sure it is always unique
                }

            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

//time complexity is (3 loops+logn)
//space complexity depends on given array
