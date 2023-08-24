#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

//each time you can either climb one or two stairs
//return no of distinct ways to climb from 0th step to nth step 

/*
how to know its a dp problem
1. count total no of ways
2. lots of ways of doing qs, find min or max output
3. whenever try all possible ways comes in 


*/

/*
tricks for solving dp
1. try to represent the problem in terms of indexes 
2. do all possible stuff on that index acc to the problem statement 
3. if qs says count all ways, sum everything 
if find min-take min
if find max-take max 

also, think about edge cases. for eg. f(x-2) but x=1

*/

/*
BACK TO THE QUESTION
assume stairs to be indexes 
think in terms of recursion 

SAME AS FIBONACCI

*/
