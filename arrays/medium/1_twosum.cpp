//find all pairs in array whose sum= target 
//better apporach
//brute is in notes 

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<set>
using namespace std;

string read(int n, vector<int> book, int target)
{
    map<int, int>mpp;
    for(int i=0;i<n;i++){
        int a=book[i];
        int more=target-a;
        if(mpp.find(more)!=mpp.end()){
            return "YES";

        }
        mpp[a]=i;


    } 
    return "NO";
}