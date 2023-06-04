//brute solution



#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<map>
using namespace std;


vector<vector<int>>mergeOverlappingIntervals(vector<vector<int>> &arr){
    int n=arr.size();
    sort(arr.begin(),arr.end());//first sort the entire array
    //sorting is done accoridng to the first index, if tie then second index 

    vector<vector<int>> ans;
    for(int i=0;i<n;i++){
        int start=arr[i][0];
        int end=arr[i][1];
        if(!ans.empty()&&end<=ans.back()[1]){
            continue;
        }//if already in interval completely
        for(int j=i+1;j<n;j++){
            if(arr[j][0]<=end){
                end=max(end,arr[j][1]);

            }//in interval but not completely
            else{
                break;
            }
        }//if not in interval
        ans.push_back({start,end});       
        }

    return ans;

}

//diff btw continue and break
//break exists loop entirely- current iteration and next ones
//continue terminated only current iteration


//time complexity 
//nlogn for sorting 
//every element is being traversed twice because of the innner loop
//nlogn+2n
//O(2N)