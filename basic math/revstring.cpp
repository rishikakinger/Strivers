#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution{
public:	
	
	
	int isPalindrome(string S)
	{
	    int beg=0;
	    int end=S.length()-1;
	    while(beg<end){
	        if(S[beg]==S[end]){
	            
	            beg++;
	            end--;
	        }
	        else{
	            break;
	    }
	    }
	    if(beg<end){
	        return 0;
	    }
	    return 1;
	    
	}

};