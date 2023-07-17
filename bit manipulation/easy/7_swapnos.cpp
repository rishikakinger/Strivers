#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

void swapNumber(int &a, int &b) {
	a=a^b;
	b=a^b;
	a=a^b;
}