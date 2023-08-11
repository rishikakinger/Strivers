//optimal solution 
//unordered set



#include<vector>
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution{
  public:

    int findLongestConseqSubseq(int nums[], int n)
    {
        if(n==0) return 0;
        int longest=1;
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        
        for(auto it:st){
            if(st.find(it-1)==st.end()){
                int cnt=1;
                int x=it;
                while(st.find(x+1)!=st.end()){
                    x++;
                    cnt++;
                    
                }
                longest=max(longest,cnt);
            }
        }
        
        
        
        
        return longest;
    }
};