//optimal solution 1


//find sum of all elements and subract from sum of all natural nos till n 
//if x->repeating, y->missing 
//this difference will give you x-y(take it as eqn 1)
//sum up the squares and take diff 
//x^2-y^2=(x+y)(x-y)




#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<map>
using namespace std;



vector<int> findMissingRepeatingNumber(vector<int> a){
    long long n=a.size();

    //pls take everything as long long-may exceed boundaries as we take square and stuff

    //S-Sn
    //S2-S2n

    long long SN=(n*(n+1))/2;
    long long S2N=(n*(n+1)*(2*n+1))/6;

    long long S=0,S2=0;
    for(int i=0;i<n;i++){
        S+=a[i];
        S2+= (long long)a[i]*(long long)a[i];

    }
    long long val1=S-SN;//x-y
    long long val2=S2-S2N;
    val2=val2/val1;//x+y
    long long x=(val1+val2)/2;
    long long y=x-val1;
    return{(int)x,(int)y};

}
//time complexity O(N)
//space complexity O(1)