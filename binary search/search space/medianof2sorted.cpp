
//Median of 2 Sorted Arrays of Different Sizes
//if even length, take the 2 medians and return their avg
//leetcode HARD problem!!!

//kth of 2 sorted arrays can be used here- go through it once


//brute:merge 2 the two sorted arrays, find median (merge sort)
//time complexity O(n1+n2)
//space complexity O(n1+n2)---> can be optimised to O(1)


//the minute you see 2 sorted arrays-think of binary search

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
    if(nums2.size()< nums1.size()) return findMedianSortedArrays(nums2,nums1);

    int n1=nums1.size();
    int n2=nums2.size();

    int low=0, high=n1;

    while(low<=high){
        int cut1=(low+high)/2;
        int cut2=(n1+n2+1)/2-cut1;

        int left1= cut1==0? INT_MIN:nums1[cut1-1];
        int left2= cut2==0? INT_MIN:nums2[cut2-1];

        int right1= cut1==n1? INT_MAX:nums1[cut1];
        int right2= cut2==n2? INT_MAX:nums2[cut2];

        if(left1<=right2 && left2<=right1){
            if((n1+n2)%2==0){
                return (max(left1,left2)+min(right1,right2))/2.0;

            }
            else{
                return max(left1,left2);
            }

        }

        else if(left1>right2){
            high=cut1-1;
        }
        else{
            low=cut1+1;

        }
        

    }
    return 0.0;

}

//time complexity is log(min(n1,n2))