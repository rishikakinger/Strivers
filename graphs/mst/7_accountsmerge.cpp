#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

//at min of 1 email should be the same to merge 
//emails should be sorted 

//disjoint set 

class DisjointSet{
    vector<int> rank,parent,size;
public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }

    int findUltpar(int node){
        if(node==parent[node])return node;
        return parent[node]=findUltpar(parent[node]);
        //path compression


    }
    void unionByRank(int u, int v){
        //attaching trees
        int ulp_u=findUltpar(u);
        int ulp_v=findUltpar(v);
        if(ulp_u==ulp_v)return;//nothing to do
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }

    //union by size much more intuitive 
    void unionBySize(int u, int v){
        //attaching trees
        int ulp_u=findUltpar(u);
        int ulp_v=findUltpar(v);
        if(ulp_u==ulp_v)return;//nothing to do
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];            
        }
    }


};

vector<vector<string>> mergedetails(vector<vector<string>>& details){
//iterate through all emails and put in map
    int n=details.size();
    DisjointSet ds(n);
    unordered_map<string,int> mpp;
    for(int i=0;i<n;i++){
        for(int j=1;j<details[i].size();j++){
            string mail=details[i][j];
            if(mpp.find(mail)==mpp.end()){
                mpp[mail]=i;

            }
            else{
                ds.unionBySize(i,mpp[mail]);

           }

        }
    }
    vector<string> merged[n];
    for(auto it: mpp){
        string mail=it.first;
        int node=ds.findUltpar(it.second);
        merged[node].push_back(mail);

    }
    vector<vector<string>> ans;
    for(int i=0;i<n;i++){
        if(merged[i].size()==0) continue;
        sort(merged[i].begin(),merged[i].end());
        vector<string> temp;
        temp.push_back(details[i][0]);
        for(auto it: merged[i]){
            temp.push_back(it);
        }
        ans.push_back(temp);
    }
    return ans;


}


