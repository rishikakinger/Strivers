//count no of bits to be flipped to convert one no into anothe

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

int noOfBitsToFlip(int n1, int n2){

    int xor1=n1^n2;

    int count=0;
    while(xor1){
        if(xor1 & 1){
            count++;
        }       
        xor1=xor1>>1;
    }
    return count;

}



