
#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

//tc O(nlogn*w)
//sc O(n)

bool isNStraightHand(vector<int>& hand,int groupSize){
    if(hand.size()%groupSize!=0)return false;

    int curr=0;
    int prev=-1;

    priority_queue<int, vector<int>, greater<int>> pq;

    for(auto h:hand){
        pq.push(h);//push all elements in vector into the pq
    }

    vector<int> temp;

    while(!pq.empty()){

        int t=pq.top();
        pq.pop();

        //only add if the group is new or if the next number is consecutive, eg. 2, 2

        if(prev=-1 || t-prev==1){
            prev=t;
            curr++;
        }

        else{
            temp.push_back(t);
        }

        if(curr==groupSize){
            curr=0;
            prev=-1;
            for(auto e: temp){
                pq.push(e);
            }
            temp={};
        }
    }

    return curr?false:true;


}