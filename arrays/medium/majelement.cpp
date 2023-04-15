//Given an array A of N elements. Find the majority element in the array. A majority element in an array A of size N is an element that appears more than N/2 times in the array.
 
 //brute is N^2, better is hashing 
 //MOORE'S VOTING ALGORITHM 

 //time complexity O(2N)
 //space complexity O(1)


#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;


int majorityelement(vector<int> v){
    int cnt=0;
    int el;
    for(int i=0;i<v.size();i++){
        if(cnt==0){
            cnt=1;
            el=v[i];

        }
        else if(v[i]==el){
            cnt++;
        }
        else{
            cnt--;
        }
    }
    //if there is a possibility that no elemnet maybe the majority element 

    int cnt1=0;
    for(int i=0;i<v.size();i++){
        if(v[i]==el)cnt1++;
    }
    if(cnt1>=v.size()/2)return el;
    return -1;
}


