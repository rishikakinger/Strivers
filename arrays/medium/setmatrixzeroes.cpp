//catch here is that you have to change only for original zeroes, more zeroes might appear once you start changing 
//brute force solution
//-1 concept 
//time complexity is O((n*m)*(n+m)+n*m)

#include<vector>
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

vector<vector<int>> zeroMatrix(vector<vector<int>>&matrix){
    int n = sizeof(matrix)/sizeof(matrix[0]);
    int m = sizeof(matrix[0])/sizeof(matrix[0][0]);
    int col[m]={0};
    int row[n]={0};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==0){
                row[i]=1;
                col[j]=1;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(row[i]||col[j]){
                matrix[i][j]=0;
            }
        }
    }
    return matrix;
    
}
//time complexity O(2nm)
//space complexity O(n)+O(m)