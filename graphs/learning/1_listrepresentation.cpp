#include<bits/stdc++.h>
#include<iostream>
using namespace std;

//cheap

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];//this is a list
    //if weighted graphs, store pairs
    
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }//o(2*e)


}