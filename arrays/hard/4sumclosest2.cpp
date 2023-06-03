//better approach
//trim down on the last for loop
//num[l]=-(num[i]+num[j]+num[k])
//everything between j and k goes into the set


#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<map>
using namespace std;


vector<vector<int>> fourSum(vector<int> &nums,int target){
    int n=nums.size();
    set<vector<long long>> st;
    for(int i=0;i<n;i++){
        for(int j=i+1;i<n;j++){
            set<long long> hashset;
            for(int k=j+1;k<n;k++){
                long long sum=nums[i]+nums[j];
                sum+=nums[k];
                long long fourth=target-sum;
                if(hashset.find(fourth)!=hashset.end()){
                    vector<long long> temp={nums[i],nums[j],nums[k],fourth};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);

                }
                hashset.insert(nums[k]);

            }
        
        }

    }

}

//n^3
//logm (1/n)

//ectra hashset used 