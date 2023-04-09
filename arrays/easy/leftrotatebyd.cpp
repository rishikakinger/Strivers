//LEFT ROTATE ARRAY BY D PLACES 

//means, take first k places, put them in the end, then left rotate the rest 

//if k=arr.size(), resulting array will be the original array only
//eg. n=7, k=8=7+1, hence, effectively one rotation
//multiple of 7 will always bring you back to the original array 
//k=k%7

//in prev, we took temp as one int, here, take temp to be an array of size k
//ith index ends up in i-kth index in resulting array

//put back from temp to array, n-kth position onwards 

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

void leftRotate(int arr[], int n, int d){
    d=d%n;

    int temp[d];
    for(int i=0;i<d;i++){
        temp[i]=arr[i];
    }

    for(int i=d;i<n;i++){
        arr[i-d]=arr[i];
    }

    for(int i=n-d;i<n;i++){
        arr[i]=temp[i-(n-d)];
    }

}