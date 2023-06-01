//difference between subarray and subsequence 
//brute is to generate all subarrays and check summation, O(N^3), O(N^2)
//watch sum of positives and negatives again (arrays-easy)

/*


☆。*。☆。
★。＼｜／。★
*Focus on thenegative*
★。／｜＼。★
☆。*。☆。


*/

#include<vector>
#include<bits/stdc++.h>
#include<iostream>
using namespace std;


int findAllSubarraysWithGivenSum(vector<int>& arr,int k){
    unordered_map<int,int> mpp;
    mpp[0]=1;//imp step
    int preSum=0, cnt=0;

    for(int i=0;i<arr.size();i++){
        //first add, then check
        preSum+=arr[i];
        int remove=preSum-k;
        cnt+=mpp[remove];//if index doesnt exist, wont add
        mpp[preSum]+=1;

    }


    return cnt;

}
//time complexity 
//O(N) for the loop
//O(1) for unordered map, O(N) if tooo many collisions 
//O(logN) for map