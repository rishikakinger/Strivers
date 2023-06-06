//same as coutn inversions except a[i]>2*a[j] instead of a[i]>a[j]


//brute O(n^2)




#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<map>
#define ll long long
using namespace std;

int cnt=0;

void merge(vector<int> &arr,int low,int mid, int high){
    vector<int> temp; //uses temporary array
    int left=low;
    int right=mid+1;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
            left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
            right++;

    }
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }


}

int countPairs(vector<int> &arr,int low,int mid,int high){
    int right=mid+1;
    int cnt=0;
    for(int i=0;i<=mid;i++){
        while(right<=high&&arr[i]>2*arr[right]) right++;
        cnt+=(right-(mid+1));


    }
    return cnt;


}






int ms(vector<int> &arr,int low, int high){
    int cnt=0;
    if(low>=high){
        return cnt;
    }
    int mid=(low+high)/2;
    cnt+=ms(arr,low,mid);
    cnt+=ms(arr,mid+1,high);
    //before merge we have to implement
    cnt+=countPairs(arr,low,mid,high);
    merge(arr,low,mid,high);
}

int pairs(vector<int> &skill,int n){
    return ms(skill,0,n-1);

}

//time complexity is logn*(n+n)
//log is splitting
//n is for merge
//optimization is equivalent of merge as we are visiting each element once like merge
//we are distorting array here 
