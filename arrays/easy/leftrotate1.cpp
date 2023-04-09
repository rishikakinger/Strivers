//LEFT ROTATE BY 1 PLACE
//time complexity O(N)
//space complexity O(1)
//space being used IN the algorithm is O(N)

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

vector<int> rotateArray(vector<int> &arr, int n){
    int temp=arr[0];
    for(int i=1;i<n;i++){
        arr[i-1]=arr[i];
    }
    arr[n-1]=temp;
    return arr;

}