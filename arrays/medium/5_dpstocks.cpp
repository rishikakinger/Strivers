//space optimization is imp for dp stocks

//if you are selling the stock on ith day, you will buy it on the min element in 1st to (i-1)th day 

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

int maximumProfit(vector<int> &prices){
    int mini=prices[0];
    int maxProfit=0;
    int n=prices.size();
    for(int i=1;i<n;i++){
        int profit=prices[i]-mini;
        maxProfit=max(profit,maxProfit);
        mini=min(mini,prices[i]);

    }
    return maxProfit;
}