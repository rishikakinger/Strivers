#include<bits/stdc++.h>
#include<iostream>
#include<queue>
#include<set>
using namespace std;

void floydwarshall(vector<vector<int>>& matrix){
    //do it in place
    int n=matrix.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]=-1)matrix[i][j]=1e9;
            if(i==j)matrix[i][j]=0;
        }

    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
            }
        }
    }

    //to check for negative cycles

    for(int i=0;i<n;i++){
        if(matrix[i][i]<0) cout<<"-1";
    }



    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]=1e9)matrix[i][j]=-1;
        }

    }

}

//tc n^3
