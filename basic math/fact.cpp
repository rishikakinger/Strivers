
#include<bits/stdc++.h> 
#include<iostream>
#include<vector>
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    vector<long long> factorialNumbers(long long N)
    {
        vector<long long> ans;
        long long fact=1;
        int i=1;
        while(fact*i<=N){
            fact*=i;//IF YOURE PERFORMING SOME OPERATION ON VARIABLE AS A CONDN IN THE WHILE LOOP, BE CAREFUL
            
            cout<<i<<" ";
            i++;
            
        }
        return ans;
        
        
    }
};

//{ Driver Code Starts.
int main()
{

        Solution ob;
        vector<long long> ans=ob.factorialNumbers(3);
        
    
    return 0;
}
// } Driver Code Ends