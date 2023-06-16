
//if you actually check for all O(n^2) complexity

//instead, betetr approach is to assume the first word is the prefix, and remove words off it as you iterate throught he array 

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs.front();
        if (prefix == "") {
            return "";
        }
        for (int i = 1; i < strs.size(); i++) {
            if (strs[i] == prefix) {
                continue;
            }
            int iter = 0;
            string nextWord = "";
            while (strs[i][iter] == prefix[iter]) {
                nextWord += strs[i][iter];
                iter++;
            }
            if (nextWord == "") {
                return "";
            }
            prefix = nextWord;
        }
        return prefix;
    }