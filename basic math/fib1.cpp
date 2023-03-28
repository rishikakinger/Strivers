//didnt get this qs- imp
#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

class Solution
{
    public:
    
    vector<long long> printFibb(int n) 
    {
        
        vector<long long> ans;
        
        long long int a=1,b=1;
        
        //pushing 1 once in the list if n>=1 and again if n>=2----- imp
        if(n>=1)
            ans.push_back(1);
        if(n>=2) 
            ans.push_back(1);
            
        
        for(int i = 2 ; i < n ; ++ i ) 
        {
            //pushing sum of a and b in the list.
            ans.push_back(a+b);
            long long int c=a+b;            
            //updating a as b and b as c(sum of a and b).
            a=b;
            b=c;
        }
        
        //returning the list.
        return ans;
    }
};