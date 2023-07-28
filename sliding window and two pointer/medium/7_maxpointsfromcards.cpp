#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

//MOST ASKED QUESTION IN GOOGLE
//tc is O(k)
//sc is O(1)


int maxScore(vector<int>& cardPoints, int k) {

    int l=0;
    int r=cardPoints.size()-k;

    int totalsum=0;
    for(int i=r;i<cardPoints.size();i++){
        totalsum+=cardPoints[i];
    }

    int res=totalsum;

    while(r<cardPoints.size()){
        totalsum+=cardPoints[l];
        totalsum-=cardPoints[r];

        res=max(res,totalsum);

        l++;
        r++;

    }


    return res;
        
}