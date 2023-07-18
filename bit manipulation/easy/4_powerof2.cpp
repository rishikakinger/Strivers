
//all power of 2 no.s have only 1 bit set

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

bool isPowerOfTwo(int n)
{
    if(n &(n-1)==0)return true;
    return false;
}