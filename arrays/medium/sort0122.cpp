//optimal approach 
//DUTCH NATIONAL FLAG ALGORITHM 

//3 pointers: low, mid, high
//3 rules 



#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;


void sortArray(vector<int>& arr, int n){
    int low=0, mid=0, high=n-1;
    while(mid<=high){//till we have unsorted section
        if(arr[mid]==1){
            mid++;
        }
        else if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            mid++;
            low++;
        }
        else{
            swap(arr[high], arr[mid]);
            high--;
        }


    }

}


//time complexity is O(N)
//space complexity O(1)