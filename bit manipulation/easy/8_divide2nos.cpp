#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

int divide(int divident, int divisor){

    //acc to qs
    if(divident==1<<31 && divisor==-1)return INT_MAX;

    bool sign=(divident>=0)==(divisor>=0)? true: false;

    divident=abs(divident);
    divisor= abs(divisor);
    int res=0;
    

    while(divident-divisor>=0){
        int count=0;

        while(divident-(divisor<<1<<count)>=0){
            count++;
        }
        res+=(1<<count);
        divident-=divisor<<count;


    }
    if(sign) return res;
    return -1*res;


}