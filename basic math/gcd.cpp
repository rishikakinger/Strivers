
//NOTE: gcd and hcf are the same thing
//for any 2 given numbers, there will always be a gcd as there will alwaybe be 1 in common that can divide boht of them
//gcd(9,12)=3
//gcd(11,13)=1
//gcd(20,40)=20 gcd can be one of the nos also

//start iterating from rev of array, best case is better than iterating from beg but worst case is the same

//euclidian algorithm : gcd(a,b)=gcd(a-b,b)
//euclids algorithm: gcd(a,b)=gcd(b,a mod b)
//both of them are the same, stop whne one no becomes zero, the other is the ans
//without swapping: gcd(a,b)=gcd(a%b,b), where greater%smaller

#include<bits/stdc++.h>
#include<iostream>
using namespace std;


int gcd(int a, int b){
    while(a>0 && b>0){
        if(a>b){
            a=a%b;
        }
        else{
            b=b%a;
        }
    }

    if(a==0){
        return b;
    }
    return a;
}