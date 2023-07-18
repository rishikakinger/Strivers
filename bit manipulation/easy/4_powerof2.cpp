
//all power of 2 no.s have only 1 bit set

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

bool isPowerOfTwo(int n)
{
    /* First x in the below expression is for the case when
     * x is 0 */
    int cnt = 0;
    while (n > 0) {
        if ((n & 1) == 1) {
            cnt++;
        }
        n = n >> 1; // keep dividing n by 2 using right
                    // shift operator
    }
 
    if (cnt == 1) { // if cnt = 1 only then it is power of 2
        return true;
    }
    return false;
}