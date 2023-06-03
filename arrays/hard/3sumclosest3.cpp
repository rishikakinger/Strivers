//optimal approach- 2 pointer approach
//sort the array first


#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<map>
using namespace std;

vector<vector<int>> triplet(int n,vector<int> &num){

    vector<vector<int>> ans;
    for(int i=0;i<n;i++){
        if(i>0&&num[i]==num[i-1]) continue;
        //continue ensures it goes back to for loop, to the next i
        int j=i+1;
        int k=n-1;
        while(j<k){
            int sum=num[i]+num[j]+num[k];
            //3 conditions 

            if(sum>0){
                k--;
            }
            else if(sum<0){
                j++;
            }
            else{
                vector<int> temp={num[i],num[j],num[k]};
                //already in sorted order
                ans.push_back(temp);
                j++;
                k--;
                while(j<k && num[j]==num[j-1]) j++;
                while(j<k && num[k]==num[k-1]) k--;

            }
        }
    }
    return ans;
}

//nlogn to sort
//n for entire
//n for while
//O(n*n+nlogn)


