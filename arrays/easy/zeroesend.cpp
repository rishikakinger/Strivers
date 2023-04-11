//brute force approach:iterate, store all non zero nos separately, add then fill remaining places with zero 
//for brute force time complexity is O(N), space is also O(N)->bad

//no better solution, next solution is optimal
//optimal: use 2 pointer and swapping 
//optimal time complexity is O(N) and space complexity is O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	void pushZerosToEnd(int arr[], int n) {
	    int j=-1;
	    for(int i=0;i<n;i++){
	        if(arr[i]==0){
	            j=i;
	            break;
	        }
	    }
	    if(j!=-1){
		    
	    for(int i=j+1;i<n;i++){
	        if(arr[i]!=0){
	            swap(arr[i],arr[j]);
	            j++;
	        }
	    }
        }	   	    
	}
};

