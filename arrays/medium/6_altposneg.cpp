//NOTE:N/2 are positive, other N/2 are negative 

//brute force takes time complexity O(N+N/2) and space as O(N)

//time complexity in optimal is O(N), instead of O(2N), and hence, better 



#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

vector<int> rearrangeArray(vector<int> &nums){
    int n=nums.size();
    vector<int> ans(n,0);
    int posIndex=0, negIndex=1;
    for(int i=0;i<n;i++){
        if(nums[i]<0){
            ans[negIndex]=nums[i];
            negIndex+=2;
        }
        else{
            ans[posIndex]=nums[i];
            posIndex+=2;

        }
    }
    return ans;
}