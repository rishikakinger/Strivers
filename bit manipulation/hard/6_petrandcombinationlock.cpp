//peter and combination lock qs on codeforces

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

//sum%360==0

//power set where 0->-, 1->+

bool petr(vector<int>& arr, int n){
    bool flag=false;
    for(int num=0;num<=((1<<n)-1);num++){
        int sum=0;
        for(int bit=0;bit<=(n-1);bit++){
            if(num & (1<<bit)){
                sum+=arr[bit];
            }
            else{
                sum-=arr[bit];
            }
        }
        if(sum%360==0){
            flag=true;
            break;
        }
    }
    if(flag==true)return true;
    return false;

}