//{ Driver Code Starts
#include<bits/stdc++.h> 
#include<iostream>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int evenlyDivides(int N){
        int i=0;
        int n=N;
        int a;
        while(N>0){
            a=N%10;
            if(n%a==0){
                i++;
            }
            N=(int)N/10;
            
        }
        return i;
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.evenlyDivides(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends


//PROBLEM: GFG HAS PROB WHEN YOU CHANGE I/P
