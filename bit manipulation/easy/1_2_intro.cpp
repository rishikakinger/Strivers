//xor- even 1's=0, odd 1's=1
//xor of 2 same no.s is 0

//32 bits representation

//swap 2 no.s using XOR
//a=a^b
//b=a^b
//a=a^b


//given N, print xor of all no.s from 1-N(without 0^(n) complexity)
//for all multiples of 4, ans will always be n
//soln is purely based on observation
/*

if(n%4==0) print(n)
if(n%4==1) print(1)
if(n%4==2) print(n+1)
if(n%4==3) print(0)


*/

//bit indexing is from 0

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;


vector<int> bitManipulation(int num, int i){
    vector<int> nums;


    //get bit value at i
    if(num & (1<<(i-1))){
        nums.push_back(1);
    }
    else nums.push_back(0);
    
    //set ith bit
    nums.push_back(num| (1<<i-1));

    //clear ith bit
    nums.push_back(num & (~(1<<i-1)));
    return nums;
}