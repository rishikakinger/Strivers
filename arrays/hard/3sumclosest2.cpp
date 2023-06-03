//better approach
//using hashing 
// you know what youre looking for , i.e arr[i]+arr[j]+arr[k]=0
//hence, arr[k]=-(arr[i]+arr[j])
//but alos remeber, arr[k] cannot be equal to arr[i] or arr[j]


//only need to run loop for i and j 


//2 sets, one to make sure it is unique, one to find k



#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<map>
using namespace std;


vector<vector<int>> triplet(int n,vector<int> &num){
    set<vector<int>> st;
    for(int i=0;i<n;i++){
        set<int> hashset;
        for(int j=i+1;j<n;j++){
            int third=-(num[i]+num[j]);
            if(hashset.find(third)!=hashset.end()){
                vector<int> temp={num[i],num[j],third};
                sort(temp.begin(),temp.end());
                st.insert(temp);
            }
            hashset.insert(num[j]);
        }

    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;


}

//time complexity is (n^2logM)
//space complexity is a lot