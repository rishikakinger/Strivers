#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

//makes use of heapify 

void heapify(int arr[],int n,int i){
    int largest=i;
    int left=2*i;//2i+1 for 0 based indexing
    int right=2*i+1;//2i+2 for 0 based indexing

    if(left<n && arr[largest]<arr[left]){
        largest=left;

    }
    if(right<n && arr[largest]<arr[right]){
        largest=right;
    }

    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }

}//tc O(logn)

void heapifyMain(int arr[], int n){
    for(int i=n/2;i>0;i--){//check from bottom
        heapify(arr,n,i);
    }//tc O(n)

}




void heapsort(int arr[],int n){

    int size=n;

    while(size>1){
        swap(arr[size],arr[1]);
        size--;
        heapify(arr,size,1);
    }

}//tc O(nlogn)