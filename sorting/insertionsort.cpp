#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void insertionsort(int arr[], int n){
    for(int i=0;i<=n-1;i++){
        int j=i;
        while(j>0&&arr[j-1]>arr[j]){
            int temp=arr[j-1];
            arr[j-1]=arr[j];
            arr[j]=temp;
            j--;
        }
    }
}

//worst case is when a reverse soted array is given, time complexity is of O(n^2), avg too
//best case->loop is already sorted, inner while loop never runs, hence O(n)