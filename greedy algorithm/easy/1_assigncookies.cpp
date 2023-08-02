#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

//local optimum solution 

int findContentChildren(vector<int>& g, vector<int> &s){
    sort(s.rbegin(),s.rend());
    sort(g.rbegin(),g.rend());

    int curr=0;//points to max cookie
    int total=0;

    int n=g.size();
    int m=s.size();

    for(int i=0;i<n;i++){
        if(curr<m && g[i]<=s[curr]){
            total++;
            curr++;

        }
        return total;

    }

}