//optimal approach

//2 pointer approach

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

vector<int> findArrayIntersection(vector<int> &A, int n, vector<int> &B, int m){
    int i=0;
    itn j=0;
    vector<int> ans;
    while(i<n && j<m){
        if(A[i]<B[j]){
            i++;

        }
        else if(A[i]>B[j]){
            j++;
        }
        else{
            ans.push_back(A[i]);
            i++;
        }

    }
    return ans;

}

//worst case is when there are no elements in common and i and j keep moving 
//worst case time complexity is O(n+m)
//space complexity is O(1)