#include<bits/stdc++.h>
#include<iostream>
#include<queue>
using namespace std;

//implementation using set

//set stores unique values and smallest at the top 

//pq cannot erase but set can 
//set.erase() takes logn 
//else, exactly the same
//so it cant explicitely be said which method is better than the other pq or set

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S){
    set<pair<int,int>> st;
    vector<int> dist(V, 1e9);

    st.insert({0,S});
    dist[S]=0;

    while(!st.empty()){
        auto it=*(st.begin());
        int node=it.second;

        int dis=it.first;
        st.erase(it);

        for(auto it: adj[node]){
            int adjNode=it[0];
            int edgeWt=it[1];

            if(dis+edgeWt<dist[adjNode]){

                if(dist[adjNode]!=1e9)st.erase({dist[adjNode],adjNode});
                dist[adjNode]=dis+edgeWt;
                st.insert({dist[adjNode],adjNode});


            }
        }

    }
    return dist;

}