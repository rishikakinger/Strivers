#include <unordered_set>
#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

int findMaxFruits(string &str, int n) {
    int maxFruits = 0;

    // Finding maximum length of substring having atmost 2 distinct characters
    for (int i = 0; i < n; i++) {
        // Store distinct characters
        unordered_set<char> distinctChar;

        // Finding maximum length of substring start from 'i' and having atmost 2 distinct characters.
        for (int j = i; j < n; j++) {
            distinctChar.insert(str[j]);
            if (distinctChar.size() > 2) {
                break;
            }
            // Update maxFruits.
            maxFruits = max(maxFruits, j - i + 1);
        }
    }

    return maxFruits;
}