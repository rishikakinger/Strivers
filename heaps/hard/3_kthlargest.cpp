//also easy
//sorting tc will be nlogn
//instead of that use heap to make tc nlogk

//for kth largest, use minheap
//for kth smallest, use maxheap

//imp logic: watch ayushi sharma yt video 

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

class KthLargest{

    priority_queue<int, vector<int>,greater<int>> pq;
    int size;

    KthLargest(int k, vector<int> nums){

        
        
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            if(pq.size()>k){
                pq.pop();
            }
        }

        size=k;//because k is local to this constructor and add wont be able to access it


    }

    int add(int val){
        pq.push(val);
        if(pq.size()>size){
            pq.pop();
        }

        return pq.top();


    }


};