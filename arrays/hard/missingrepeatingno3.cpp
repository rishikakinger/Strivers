//optimal 2  

//(arr[i])^(1^2^3^4^.....n)=num
//find a differentiating bit in num(first 1 from the right)
//put these into 2 parts and xor them

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<map>
using namespace std;

vector<int> findMissingnRepeatingNo(vector<int> a){
    long long n=a.size();
    int xr=0;
    for(int i=0;i<n;i++){
        xr=xr^a[i];
        xr=xr^(i+1);
    }
    //finding first 1 form the right

    int bitNo=0;
    while(1){
        if(xr &(1<<bitNo)!=0){
            break;
        }
        bitNo++;
    }

    //divide into 2 groups
    int zero=0;
    int one=0;
    for(int i=0;i<n;i++){
        //part of 1 club
        if((a[i]&(1<<bitNo!=0))){
            one=one^a[i];

        }
        //part of 0 club
        else{
            zero=zero^a[i];

        }

    }
    for(int i=1;i<n;i++){
        //part of 1 club
        if((i&(1<<bitNo!=0))){
            one=one^i;

        }
        //part of 0 club
        else{
            zero=zero^i;

        }

    }
    //now you have the 2 no.s
    //but just to confirm which one is which

    int cnt=0;

    for(int i=0;i<n;i++){
        if(a[i]==zero)cnt++;

    }
    if(cnt==2) return {zero,one};
    return{one,zero};


}

//time complexity O(n)
//space complexity O(1)