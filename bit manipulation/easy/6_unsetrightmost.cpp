
#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

//clear last set bit from the right 

int setBits(int N){
    //check if all bits are set 
    if(!(N &(N+1)))return N;
    
    return (N|(N+1));
}