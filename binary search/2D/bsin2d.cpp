
//optimal for type 2 but better for type 1


#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

int search2d(vector<vector<int>> mat, int n, int m, int x){
    int i=0,j=m-1;
    while(i<n && j>=0){
        if(i<n && j>=0){
            if(mat[i][j]==x){
                return 1;
                //additionally store index it is found at
            }
            if(mat[i][j]>x) j--;
            else i++;

        }

    }

}