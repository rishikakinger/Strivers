//only one solution for this qs!!! lessgoo!!!



#include<vector>
#include<bits/stdc++.h>
#include<iostream>
using namespace std;


vector<int> spiralMatrix(vector<vector<int>>&mat){
    int n=mat.size();
    int m=mat[0].size();
    int left=0, right=m-1;
    int top=0,bottom=n-1;
    vector<int> ans;

    while(top<=bottom&&left<=right){
    //right
    for(int i=left;i<=right;i++){
        ans.push_back(mat[top][i]);
    }
    top++;
    for(int i=top;i<=bottom;i++){
        ans.push_back(mat[i][right]);
    }
    right--;


    if(top<=bottom){//top has previously been changed so imp to check again
    for(int i=right;i>=left;i--){
        ans.push_back(mat[bottom][i]);

    }
    }
    
    bottom--;


    if(left<=right){//right has been previiously changed so imp to check
    for(int i=bottom;i>=top;i--){
        ans.push_back(mat[i][left]);
    }
    left++;
    }

    }  
    return ans; 

}

//time complexity is of O(NxN)
