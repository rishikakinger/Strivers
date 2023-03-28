//sum of first n numbers using parameterized recursion
//usually parameterised is used to print things and functional is used to return things.


//this is functional
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int rec(int n){
    if(n==1){
        return 1;
    }
    int sum=n+rec(n-1);
    return sum;

}