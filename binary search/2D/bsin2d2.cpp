

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int>>&matrix, int target){
    
    //if size of matrix is zero, return false
    //how to check if matrix is empty?
    if(!matrix.size()) return false;


    //how to calculate no of rows and colums for 2d matrix
    int n=matrix.size();
    int m=matrix[0].size();

    int lo=0;
    int hi=(n*m)-1;

    while(lo<=hi){
        int mid=(lo+(hi-lo)/2);//avoid overflow
        if(matrix[mid/m][mid%m]==target){
            return true;
        }
        if(matrix[mid/m][mid%m]<target){
            lo=mid+1;
        }
        else{
            hi=mid-1;
        }

    }
    return false;

}

//time complexity O(log(m*n))