//FIND NO THAT APPEARS ONCE
//brute force approach:iterate again and again O(N^2)
//better soln is to use hashing. but for that, you will need max element in array
//but hashing isnt possible for negative no.s and max data is 10^9
//instead use map<long long, int>
// in a map, storing N/2+1 elements 


//time complexity is O((NlogM)+(N/2+1))

//optimal solution- xor all elements 


#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;


class Solution{
public:	
	int search(int A[], int N){
	    int xor1=0;
	    for(int i=0;i<N;i++){
	        xor1=xor1^A[i];
	    }
	    return xor1;
	    
	}
};