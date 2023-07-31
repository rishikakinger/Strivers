
//easy qs only
//why is this in hard lol


#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

int minCost(int arr[], int n){

    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
    }

    int ans=0;
    while(pq.size()>1){
        int first=pq.top();
        pq.pop();
        int second=pq.top();
        pq.pop();
        int sum=first+second;
        ans+=sum;
        pq.push(sum);
    }
    return ans;

}
