//include negative nos as well


//brute force is to generate all subarrays O(n^2)

//optimal
/*

1. all +ve ---> just take product of all
2. even -ve---> take product of all
3. odd -ve---> eliminate one -ve and then take product

whihc one to eliminate?

but if they are zeroes, split it based on zeroes 

*/

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<map>
using namespace std;

int subarrayWithMaxProduct(vector<int> &arr){
    int pre=1,suff=1;
    int ans=INT_MIN;
    int n=arr.size();
    for(int i=0;i<n;i++){
        if(pre==0) pre=1;
        if(suff==0) suff=1;
        pre=pre*arr[i];
        suff=suff*arr[n-i-1];//move from the back
        ans=max(ans,max(pre,suff));
    }
    return ans;

}

//time complexity O(n)