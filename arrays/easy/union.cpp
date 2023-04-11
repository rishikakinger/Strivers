//use sets - helps with unique
#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<set>
using namespace std;



class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        
        set<int> final;
        for(int i=0;i<n;i++){
            final.insert(arr1[i]);
        }
        for(int i=0;i<m;i++){
            final.insert(arr2[i]);
        }
        vector<int> ret(final.begin(), final.end());
        return ret;
        
    }
};