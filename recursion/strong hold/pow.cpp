
//log2(n) 

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

double myPow(double x, int n){
    double ans=1.0;
    long long nn=n;
    if(nn<0) nn=-1*nn;//handling negative powers (edge case)
    while(nn){
        if(nn % 2){
            ans=ans*x;
            nn=nn-1;
        }
        else{
            x=x*x;
            nn=nn/2;
        }
    }
    if(n<0) ans= (double)(1.0)/ (double)(ans);
    return ans;

}

//dont know if this is right or wrong

double myPowRec(double x, int n){
    if(n==0)return 1;

    if(n<0){
        if(-1*n % 2){
            return 1/(x*myPowRec(x,n-1));
        }
        else{
            return myPowRec(x*x,n/2);
        }
    }
    else{
        if(n%2) return x*myPowRec(x,n-1);
        else return myPowRec(x*x,n/2);
    }

}