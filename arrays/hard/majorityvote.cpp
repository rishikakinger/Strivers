//MAJORITY VOTE
//MORE THAN N/3 TIMES

//an important observation is that at max, ans can consist of 2 elements 
//so as soon as you get 2 elements, you can stop the iteration

/*
BRUTE FORCE SOLUTION 

ls=[]
for(i=0 to n-1){
    if(ls.size()!=0|| ls[0]!=nums[i]){
        cnt=0;
        for(j=0 to n-1){
            if(nums[j]==nums[i]){
                cnt++;
            }
        }
        if(cnt>n/3){
            ls.add(nums[i]);
        }
    }
    if(ls.size()==2) break;
}

time complexity is O(n*n)
space complexity O(1)


*/




/*

BETTER SOLUTION
-take hashmap

no need to iterate throught the list first and then hashmap


ls=[]
mm=floor(n/3)+1
for(i=0 to n-1){
    mpp[arr[i]]++;
    if(mpp[arr[i]]==mm){
        ls.add(arr[i])
    }
}


time complexity is O(n+logn/1/n)
space complexity is O(n) at worst



*/

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<map>
using namespace std;


vector<int> majorityElement(vector<int> v){
    vector<int> ls;
    map<int, int> mpp;
    int n=v.size();
    int mini=(int) (n/3)+1; //imp:how to take floor
    for(int i=0;i<n;i++){
        mpp[v[i]]++;
        if(mpp[v[i]]==mini){
            ls.push_back(v[i]);
        }
        if(ls.size()==2)break;

    }
    if(ls.size()==0)ls.push_back(-1);
    return ls;

}