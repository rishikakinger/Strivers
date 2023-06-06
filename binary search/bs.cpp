

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;




int binarysearch(int a[], int n, int k) {
        int low, high, mid;
        low=0;
        high=n-1;
        
        while(low<=high){
            mid=(low+high)/2;
            if(a[mid]==k){
                return mid;
                
            }
            else if(a[mid]<k){
                low=mid+1;
            }
            else{
               high= mid-1;
            }
        }
        
        return -1;
}