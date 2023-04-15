//optimal approach 
//2 pointer-greedy approach

#include<bits/stdc++.h>
#include<iostream>
#include<vector>

using namespace std;

string read(int n, vector<int> book, int target)
{
    int left=0, right=n-1;
    while(left<right){
        int sum=book[left]+book[right];
        if(sum==target) return "YES";
        else if(sum>target)right--;
        else left++;
    }
    return "NO";

}
//time complexity is O(N)+O(NlogN)---> traversing+sorting 
//space complexity is O(1), but if interviewer argues that you've changed the array, then O(N)
