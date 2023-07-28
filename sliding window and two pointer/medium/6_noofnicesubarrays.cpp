#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;


//iterate through whole array and n%2 each element 
//the qs now becomes no of subarrays with sum k

    int numberOfSubstrings(string s) {
        unordered_map<char,int> map;
        int count = 0, start = 0, end = 0;
        int n = s.size();
        while(end<n){
            map[s[end]]++;
            while( map['a'] && map['b'] && map['c'] ){
                count+=n-end;//we can form n - end substrings from the current end pointer to the end of the string.
                map[s[start]]--;
                start++;
            }
            end++;
        }
        return count;
    }

    //find valid window and add till n
    //tc O(2n)
    //sc O(1)(map of size 3)