#include<bits/stdc++.h>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> pq;
    const int n = nums.size();
    for(int i=0;i<n;++i){pq.push(nums[i]);}
    while(--k){
        pq.pop();
    }
    return pq.top();
}