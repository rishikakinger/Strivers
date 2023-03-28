#include<bits/stdc++.h>
#include<iostream>
#include<utility>
using namespace std;

void explainpair(){

    //pairs lie in the utility library

    pair<int,int> p={1,3};
    cout<< p.first<<" "<<p.second;
    
    //nested property of pair 
    pair<int, pair<int, int>> q={1,{3,4}};
    cout<<p.first<<" "<<q.second.second<<" "<<q.second.first;

    pair<int, int> arr[]={{1,2},{2,5},{5,1}}; //called pair array
    cout<< arr[1].second;

    
}