//v hard google question, 8 points in gfg

//You have N books, each with A[i] number of pages. M students need to be allocated contiguous books, with each student getting at least one book. Out of all the permutations, the goal is to find the permutation where the student with the most pages allocated to him gets the minimum number of pages, out of all possible permutations.

//similar to aggressive cows 

//first solutiont that might come into your head is recursion but its tc is exponential 
//dynamic programming will take O(n^2)


//min of search space is min(arr)
//max in search space is sum(arr)

//NOTE: it is not necessary that the array will be sorted



#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;


bool isPossible(int barrier, int n, int arr[],int M){
    int allocatedstudents=1;//index counting starts from zero but objects irl starts from 1

    int pages=0;
    for(int i=0;i<n;i++){
        if(arr[i]>barrier)return false;
        if(pages+arr[i]>barrier){
            allocatedstudents++;
            pages=arr[i];
        }
        else{
            pages+=arr[i];
        }

    }
    if(allocatedstudents>M) return false;
    return true;

}









int findPages(int arr[], int n, int M){
    int low=*min_element (arr, arr+n);//each student has to be allocated at least something
    int high=0;
    int res=-1;
    if(n<M)return -1;
    for(int i=0;i<n;i++){
        high+=arr[i];
    }
    while(low<=high){
        int mid=(low+high)>>1;
        if(isPossible(mid, n, arr, M)){
            res=mid;
            high=mid-1;

        }
        else{
            low=mid+1;

        }
    }
    return res;

}