#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

//tc is N^m
//sc is O(2n)

bool graphColoring(bool graph[101][101],int m, int N){
    int colour[N]={0};

    if(solve(0,colour,m,N,graph));

    return false;

}

bool solve(int node,int colour[],int m, int N, bool graph[101][101]){
    if(node==N) return true;

    for(int i=1;i<=m;i++){
        if(isSafe(node,colour,graph,N,i)){
            colour[node]=i;
            if(solve(node+1,colour,m,N,graph)) return true;
            colour[node]=0;
        }
    }
    return false;

}

bool isSafe(int node,int colour[],bool graph[101][101], int n,int col){
    for(int k=0;k<n;k++){
        if(k!=node && graph[k][node]==1 && colour[k]==col){
            return false;
        }
    }
    return true;

}