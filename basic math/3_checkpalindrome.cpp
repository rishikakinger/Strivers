//palindrome numbers are ones with N=rev(N)
//all single digit nos are palindrome

#include<bits/stdc++.h>
#include<iostream>
using namespace std;


string is_palindrome(int n){
			
	string s="";
	// Store the digits of number in string
	while(n > 0){
		s = s + char((n%10) + '0');
		n /= 10;
			
	}
	
	string t = s;
	// reverse the string
	reverse(t.begin(), t.end());
	// Check if equal then palindrome otherwise not.
	if(s == t)return "Yes";
	return "No";
}

//int may overflow, use char to store no.s