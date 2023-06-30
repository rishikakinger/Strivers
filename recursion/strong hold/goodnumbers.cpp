
//leetcode
//5 ways of filling even pos
//4 ways of filling odd pos
//binary exponentiation 

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

long long power(long long n, long long r){
    if(r==0)return 1;
    long long ans=1;
    long long know=power(n,r/2)%1000000007;
    if(r%2){
         ans=ans*n;
         ans=ans%1000000007;
    }
    return (ans*(know*know)%1000000007)%1000000007;

    

}

//if n is even: 20^n/2
//if n is odd; 20^n/2 * 5 (ones place left out)

int countGoodNumbers(long long n){
    long long ans=power(20,n/2);
    if(n%2){
        ans=(ans*5)%1000000007;
    }
    return ans;

}

// bro coders yt channel is amazing 
