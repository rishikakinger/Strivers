#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countNodes(int i) {
        return pow(2,(i-1));
    }
};

//there is no ^ operator in cpp