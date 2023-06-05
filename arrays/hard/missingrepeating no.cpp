
//brute force is to iterate through the entire array
//count no of times the elemtent appears
//if twice it is repeating 
//if 0 then missing 
//O(n^2)


//WHNEVER A COUTNING QS COMES UP, BETTER IS ALWAYS HASHING

//better: hashing 


#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<map>
using namespace std;


vector<int> findMissingNumbers(vector<int> a){
    int n=a.size();
    //initialise hash array
    int hash[n+1]={0};
    for(int i=0;i<n;i++){
        hash[a[i]]++;

    }
    int repeating, missing=-1;

    for(int i=1;i<=n;i++){
        if(hash[i]==2) repeating=i;
        else if(hash[i]==0) missing=i;

        if(repeating!=-1&&missing!=-1){
            break;
        }

    }
    return {repeating, missing};

}

//time complexity O(2n)
//space complexity O(n)