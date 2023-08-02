#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;



vector<int> maxCombinations(int n, int k, vector<int> &a, vector<int> &b){

  //sort the arrays
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());

  priority_queue<pair<int,pair<int,int>>> maxHeap;
  maxHeap.push({a[n-1]+b[n-1],{n-1,n-1}});

  set<pair<int,int>> mySet;//to make sure only unique index pairs

  mySet.insert({n-1,n-1});

  vector<int> result;

  while(k>0){
    pair<int,pair<int,int>> top=maxHeap.top();

    maxHeap.pop();

    int sum=top.first;
    int x=top.second.first;
    int y=top.second.second;

    result.push_back(sum);

    //check if (x,y-1) is present

    if(mySet.find({x,y-1})!=mySet.end()){
      maxHeap.push({a[x]+b[y-1],{x,y-1}});
      mySet.insert({x,y-1});
    }

    if(mySet.find({x-1,y})!=mySet.end()){
      maxHeap.push({a[x-1]+b[y],{x-1,y}});
      mySet.insert({x-1,y});
    }
    
    k--;


  }
  return result;

  
}