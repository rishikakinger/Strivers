#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;


//tc O(1)

//xor(R) ^ xor(L-1)

int xortillN(int n) {
    if(n%4==0) return(n);
    if(n%4==1) return(1);
    if(n%4==2) return(n+1);
    if(n%4==3) return(0);

}

int xorToN(int L, int R){
    return xortillN(R)^xortillN(L-1);


}