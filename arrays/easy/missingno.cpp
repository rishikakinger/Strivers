//brute force solution is using 2 for loops O(N^2)
//better solution is using hashing, O(2N), but space will be O(N)
//optimal solution can be 2: 1. sum method, 2. XOR method 
//XOR is better than sum 
//XOR of the same numbers is always zero 
//XOR of zero with the nuumber is the number itself 
//2^2=0
//0^2=2
//with sum method, time complexity is O(2N), but with xor it is O(N)

//additionally, xor method is better as the biggets no it can store at once is N , but in sum it will be of the order of N^2

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

int misingnumber(vector<int> &a, int N){
    int xor1=0, xor2=0;
    int n=N-1;
    for(int i=0;i<n;i++){
        xor2=xor2^ a[i];
        xor1=xor1^(i+1);
    }
    xor1=xor1^N;
    return xor1^xor2;
}


/* if array range is [0,n]


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            ans^=nums[i];
            ans^=i+1;
        }
        return ans;
    }
};






*/
