//optimal solution 2 
//using gap method 
//gap method has been derived from shell sorting technique


#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<map>
using namespace std;


void swapIfGreater(long long arr1[],long long arr2[], int ind1, int ind2){
    if(arr1[ind1]>arr2[ind2]){
        swap(arr1[ind1],arr2[ind2]);

    }

}


void merge(long long arr1[], long long arr2[], int n, int m){
    int len=n+m;
    int gap=(len/2)+(len%2);//for getting upper cieling
    while(gap>0){
        int left=0;
        int right=left+gap;
        while(right<len){
            //comparing arr1 and arr2 elements
            if(left<n&&right>=len){
                swapIfGreater(arr1,arr2,left,right-n);

            }
            //comparing arr2 and arr2 elements
            else if(left>=n){
                swapIfGreater(arr2,arr2,left-n,right-n);

            }
            //comparing arr1 and arr1 elements
            else{
                swapIfGreater(arr1,arr1,left,right);

            }
            left++,right++;

        }
        if(gap==1) break;
        gap=(gap/2)+(gap%2);
    }
}

//time complexity
// log2(n+m)
//O(n+m)