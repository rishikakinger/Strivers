#include<bits/stdc++.h>
#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
using namespace std;

int leastInterval(vector<char>& tasks, int n){

    if(n==0)return tasks.size();

    priority_queue<pair<int,char>> pq;
    unordered_map<int,int> freq;

    for(int i=0;i<tasks.size();i++){
        freq[tasks[i]]++;
    }//use map to store all frequencies

    for(auto x: freq){
        pq.push({x.second,x.first});

    }

    int ans=0;

    while(pq.size()>0){
        if(pq.top().first==1){
            ans+=pq.size();
            break;
        }

        vector<pair<int,char>> v;
        v.push_back(pq.top());//add it to vector because it cannot be used again
        pq.pop();
        ans+=1;
        for(int i=0;i<n;i++){

            if(pq.size()>0){
                v.push_back(pq.top());
                pq.pop();
            }
            ans++;
        }

        for(auto x:v){
            if(x.first>1)pq.push({x.first-1,x.second});//push back to pq with modified values 
        }

        return ans;


    }

}

/*


Time complexity:O(N * n * Log(N))
Space complexity:O(N)



*/