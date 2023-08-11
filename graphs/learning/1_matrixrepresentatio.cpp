#include<bits/stdc++.h>
#include<iostream>
using namespace std;

//ADJACENCY MATRIX REPRESENTATION
//costly

int main(){
    int n,m;
    cin>>n>>m;
    int adj[n+1][m+1];

    //getting i/p
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;        
    }//o(n)


    return 0;
}