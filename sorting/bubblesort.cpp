#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void bubblesort(int arr[], int n){
    for(int i=n-1;i>=0;i--){
        int didSwap=0;
        for(int j=0;j<=i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                didSwap=1;
            }
        }
        if(didSwap){
            break;
        }
    }
}
//exact same time complexity as selection sort 