//binary search is not just limited to finding elements in an array, but can be used for any search space which is monotonic in nature

//monotnically increasing functions 

//nth root of m

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

double multiply(double number, int n){
    double ans=1.0;
    for(int i=1;i<=n;i++){
        ans=ans*number;
    }
}

double getNthRoot(int n,int m){
    double low=1;
    double high=m;
    //search space is from [1,......,m]

    double eps=1e-6;

    while((high-low)>eps){
        double mid=(low+high)/2.0;
        if(multiply(mid,n)<m){
            low=mid;
        }

        else{
            high=mid;
        }

    }
    //return either low or high
    return low;

}

//time complexity
//search spae consists of decimals as well and is not simply M

//binary search time is log(Mx10^d)
//where d is no of decimal places

//internally we call multiply function

//time complexity is O(N*log(Mx10^d))