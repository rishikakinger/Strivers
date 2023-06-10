//p is array of no of bananas(given)
//h is total no of hours (given)
//to find:k, min eating speed, min no of bananas eaten in 1hr



//len(p)<= h always

/*
BRUTE FORCE 

k can range anywhere from 1 to max(p)
try every one of these 
time complexity will be O(max(P)*no of elements in p)


*/

/*
OPTIMAL 

apply bs on range [1,.....,max(p)]
smart stuff 

*/

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;



int Solve(int n, vector<int>& arr, int H) {
    int low=1;
    int high=*max_element(arr.begin(), arr.end());
    int mid;
    int ans=INT_MAX;

     while(low<=high){
            mid=(low+high)/2;
            double hours=0;
            
            for(int i=0;i<n;i++){
                hours+=ceil((double)arr[i]/mid);
            }
            
            if(hours<=H){
                ans=min(mid,ans);
                high=mid-1;
                
            }
            else{
                low=mid+1;
            }
            
        }
        return ans;
        
    }