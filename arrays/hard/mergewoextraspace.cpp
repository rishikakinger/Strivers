//brute: use extra aux array
//optimal 1



#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<map>
using namespace std;

void merge(long long arr1[], long long arr2[], int n, int m){
     int left=n-1;
     int right=0;

     while(left>=0 && right<m){
        if(arr1[left]>arr2[right]){
            swap(arr1[left], arr2[right]);
            left--;
            right++;

        }
        else{
            break;
        }

     }
     sort(arr1,arr1+n);
     sort(arr2,arr2+n);

}

//time complexity O(m or n)- whichever is smaller +O(nlogn)+O(mlogm)
