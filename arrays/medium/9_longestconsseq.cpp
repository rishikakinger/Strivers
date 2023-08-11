//GOOGLE INTERVIEW QUESTION!!!

//brute force is O(N^2), try coding not that easy also 

//better

//have 3 variables, count, longest, lastsmaller 

#include<vector>
#include<bits/stdc++.h>
#include<iostream>
using namespace std;


class Solution{
  public:

    int findLongestConseqSubseq(int nums[], int n)
    {
        sort(nums, nums+n);
        int lastsmaller=INT_MIN;
        int longest=1;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]-1==lastsmaller){
                cnt++;
                lastsmaller=nums[i];
                
            }
            else if(lastsmaller!=nums[i]){
                cnt=1;
                lastsmaller=nums[i];
            }
            longest=max(longest,cnt);
        }
        
        return longest;
      
      
    }
};


//NlogN+N is still N complexity 