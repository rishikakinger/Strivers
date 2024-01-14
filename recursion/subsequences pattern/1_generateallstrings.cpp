#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

void generateBinaryStrings(int N, string current, vector<string>& result) {
    
    if (current.length() == N) {
        result.push_back(current);
        return;
    }


    generateBinaryStrings(N, current + '0', result);

    if (current.empty() || current.back() != '1') {
        
        generateBinaryStrings(N, current + '1', result);
    }
}

vector<string> generateString(int N) {
    vector<string> result;
    generateBinaryStrings(N, "", result);
    return result;
}

//tc 0(2^n)