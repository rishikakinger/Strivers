#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

//worst case tc is O(v)- 1 rupee coins, but realistically much better
//sc is o(1)

//NOTE: GREEDY DOES NOT ALWAYS WORK
//eg, if denominations were [1,5,6,9], value=11
//greedy gives ans as 9,1,1 but correct ans is 5,6
//greedy works in this case as sum of any 2 is lesser than next third element for sure


vector<int> findMin(int V){
    int deno[]={1,2,5,10,20,50,100,500,1000};
    int n=9;

    vector<int> ans;
    for(int i=n-1;i>=0;i--){
        while(V>=deno[i]){
            V-=deno[i];
            ans.push_back(deno[i]);
        }
    }
    return ans;
}