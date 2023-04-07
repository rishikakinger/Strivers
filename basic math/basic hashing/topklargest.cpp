
#include<bits/stdc++.h>
#include<iostream>
#include<climits>
using namespace std;

//errors with my code- didnt account for INT_MIN/ what happened to negative no.s?
//array should have atleast 2 elements no



class Solution{
public:
	// Function returns the second
	// largest elements
	int print2largest(int arr[], int n) {
	    int i, first, second;

	    // There should be at least two elements
	    if (n < 2) {
	        return -1;
	    }
        first=second=-1;

	    
	    for (i = 0; i < n; i++) {

	        // If current element is greater
	        // than first then update both
	        // first and second
	        if (arr[i] > first) {
	            second = first;
	            first = arr[i];
	        }

	        // If arr[i] is in between first
	        // and second then update second
	        else if (arr[i] > second && arr[i] != first) {
	            second = arr[i];
	        }
	    }
	    if (second == -1)
	        return -1;
	    else
	        return second;
	}
};