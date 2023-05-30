//optimal solution 

//over here, we optimize space complexity
//time cannot be optimized further, since it is a 2d array, it will take minimum O(N^2)

#include<vector>
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

vector<vector<int>> zeroMatrix(vector<vector<int>>&matrix){
    int n = sizeof(matrix)/sizeof(matrix[0]);
    int m = sizeof(matrix[0])/sizeof(matrix[0][0]);
    // int col[m]={0}; => matrix[0][..]
    // int row[n]={0}; => matrix[..][0]
    int col0=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==0){
            //mark ith row
            matrix[i][0]=0;
            //mark jth column
            if(j!=0){
                matrix[0][j]=0;
            }
            else{
                col0=0;
            }

            }
        }
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(matrix[i][j]!=0){
                if(matrix[0][j]==0|| matrix[i][0]==0){
                    matrix[i][j]=0;
                }
            }
        }
    }
    if(matrix[0][0]==0){
        for(int j=0;j<m;j++){
            matrix[0][j]=0;
        }
    }
    if(col0==0){
        for(int i=0;i<n;i++){
            matrix[i][0]=0; 
        }
    }


    return matrix;
    
}

//space complexity-> only 1 variable 
