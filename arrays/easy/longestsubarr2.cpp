//LONGEST SUBARRAY WITH SUM K(POSITIVES+ZERO)

//optimal if array has positives and negatives 


#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<map>
using namespace std;

int longestSubarrayWithSumK(vector<int> a, long long k){
    map<long long, int> preSumMap;
    int maxlen=0;
    long long sum=0;
    for(int i=0;i<a.size();i++){
        sum+=a[i];

        //for the first subarray
        if(sum==k){
            maxlen=i+1;
        }
        long long rem=sum-k;
        if(preSumMap.find(rem)!=preSumMap.end()){//do not have to iterate over the map again; != end implies rem is found in the map
            int len=i-preSumMap[rem];
            maxlen=max(maxlen, len);
        }

        if(preSumMap.find(sum)==preSumMap.end()){
            preSumMap[sum]=i;

        }
        
    }

    return maxlen;
}