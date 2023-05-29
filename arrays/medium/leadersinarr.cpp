//brute force is O(N^2)

#include<vector>
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

//WHY DOESNT THIS WORK :(((

class Solution{
    
    public:
    vector<int> leaders(int a[], int n){
        int i=0;
        vector<int> ans;
        int r=n-1;
        while(i<n-2){          
            if(i==r){
                ans.emplace_back(a[i]);
                r=n-1;                
                i++;
            }            
            if(a[i]>=a[r]){
                r--;
            }
            else{
                i++;
            }           
        }
        ans.emplace_back(a[n-1]);
        return ans;
    }
};


//correct answer
class Solution{
    
    public:
    vector<int> leaders(int a[], int n){
        vector<int> ans;
        int maxi=INT_MIN;
        for(int i=n-1;i>=0;i--){
            if(a[i]>=maxi){
                ans.emplace_back(a[i]);
                maxi=a[i];
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
        

    }
};

//time complexity O(N)
//time complexity of reverse is O(N)