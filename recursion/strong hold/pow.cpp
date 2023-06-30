
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



long long myPowRec(double n, int r){
    if(r==0)return 1;
    long long ans=1;
    long long know=myPowRec(n,r/2)%1000000007;
    if(r%2){
         ans=ans*n;
         ans=ans%1000000007;
    }
    return (ans*(know*know)%1000000007)%1000000007;

    

}