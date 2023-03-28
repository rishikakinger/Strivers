#include<bits/stdc++.h>
#include<iostream>
using namespace std;


int count(int n){
    int c=0;
    while(n>0){
        //no need for n%10
        c++;
        n=n/10;
    }
    return c;
}

//general formula for counting no of digits is log10(n)+1

int count2(int n){
    int cnt=(int)(log10(n)+1);
    return cnt;
}


/*IMP TIME COMPLEXITY HACK

IF MAIN STEP IS DIV AND DIV IS BY A CONSTANT A 
TIME COMPLEXITY= O(LOGA(N))

EG IN THIS CASE, TIME COMPLEXITY= 0(LOG10(N))

USE WHEN:
NO OF ITERATIONS DEPENDS ON DIVISION AND DIVISION IS BY A


*/



int main()
{

}