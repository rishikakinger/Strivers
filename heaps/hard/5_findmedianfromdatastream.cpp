#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

class MedianFinder{
    priority_queue<int> large;
    priority_queue<int, vector<int>,greater<int>> small;

    public:

    void addNum(int num){
        small.push(num);
        large.push(small.top());
        small.pop();

        if(small.size()<large.size()){
            small.push(large.top());
            large.pop();
        }
    }

    double findMedian(){
        return small.size()>large.size()? small.top(): (small.top()-large.top())/2.0;
    }



};