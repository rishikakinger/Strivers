//Given two sorted arrays arr1 and arr2 of size N and M respectively and an element K. The task is to find the element that would be at the kth position of the final sorted array


#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

int kthElement(int arr1[], int arr2[],int n,int m, int k){
    if(n>m){//if first array is larger
        return kthElement(arr2,arr1,m,n,k);
        //making sure binary search is always applied on the smaller one
    }
    int low=max(0,k-m);//low signifies min no of elements you can take from the arr
    int high=min(k,n);//max signifies max no of elements you can take from the arr

    while (low<=high)
    {
        int cut1=(low+high)>>1;//bit operations are faster
        int cut2=k-cut1;
        int l1=cut1==0?INT_MIN : arr1[cut1-1];
        int l2=cut2==0?INT_MIN : arr2[cut2-1];
        int r1= cut1==n? INT_MAX : arr1[cut1];
        int r2=cut2==m? INT_MAX : arr2[cut2];
        //set to int min and max so that validity doesnt fail 

        if(l1<=r2 && l2<=r1){
            return max(l1,l2);

        }
        else if(l1>r2){
            high=cut1-1;

        }
        else{
            low=cut1+1;
        }

        //manipulating cut1 only

    }
    return -1;//never executed but have to return somehting int
    

}