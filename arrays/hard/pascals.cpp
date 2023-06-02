//TYPE 1: GIVEN ROW AND COLUMN NUMBER, FIND OUT THE ELEMENT AT THAT POS

/* ANSER IS (R-1)C(C-1)

HOW TO COMPUTE NCR? THERE IS A SHORTCUT HERE, REFER TO YT VIDEO

int nCr(int n,int r){
    long long res=1;
    for(int i=0;i<r;i++){
        res=res*(n-i);
        res=res/(i+1);
    }
    return res;

}

//time complexity is O(r)

//for factorial problems, it is always better to take the datatype as long long 



*/



//TYPE 2: PRINT ROW


/*

nth row has n elements

BRUTEFORCE: apply r-1Cn-1 for each element in row
time complexity will be (n*r)


OPTIMIZATION:
int ans=1;
print(ans);
for(int i=1;i<n;i++){
    ans=ans*(n-i);   row-col
    ans=ans/i;
    print(ans);

}

time complexity is O(n)


*/



//TYPE 3: PRINT ENTIRE PASCAL'S TRIANGLE 

/*

BRUTE: use nCr formula, time complexity is O(n*n*r) 
OPTIMAL: use type 2 optimization, time complexity O(n*n)

*/





#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<map>
#define ll long long
using namespace std;


class Solution{
public:
    vector<ll> nthRowOfPascalTriangle(int n) {
        vector<ll> ans;
        long long res=1;
        ans.push_back(res);
        
        for(int i=1;i<n;i++){
            res=res*(n-i);
            res=res/i;
            ans.push_back(res);
        }
              
        return ans;
    }
};