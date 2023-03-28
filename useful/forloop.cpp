//this is a valid declaration for a for loop in cpp

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;


void example(int n, vector<int> ratings,int min_diff){
    int count=0;
for (int i = 0, j = 1; j < n; ) {
        if (ratings[j] - ratings[i] >= min_diff) {
            count++;
            i++;
            j++;
        } else {
            j++;
        }
    }
}
