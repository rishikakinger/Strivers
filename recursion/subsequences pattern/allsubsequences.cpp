//print all subsequences
/*
eg.
[3,1,2]
3,2 is valid
3,2,1 is not valid
*/

//definition of subsequence- continguous/non contiguous sequences which followd the order.
//empty string is also a subsequence 


//power set method
//number of substrings that can be geenrated is 2^n
//eg n=3, no of substrings =8
//write binary of digits from 0-7
//ie, 0 to 2^n-1
//2^n is equivalent to (1<<n)-1
/*
s="abc"
for(num=0 to 2^n-1){
    sub=""
    for(i=0 to n-1){
        if(num&(1<<i)) sub+=s[i]
    }
    print(sub)
}
*/

//recursive method 

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;


void printallsubsequences(int ind, vector<int>&ds, int arr[],int n){
    if(ind==n){
        //print the vector
        return;
    }

    ds.push_back(arr[ind]);
    printallsubsequences(ind+1,ds,arr,n);

    //if element is not picked
    ds.pop_back();
    printallsubsequences(ind+1,ds,arr,n);

}

//tc is (2^n)*n for printing
//depth of recusion at max is n
//sc is O(n)