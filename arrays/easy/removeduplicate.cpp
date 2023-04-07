
#include<bits/stdc++.h>
#include<iostream>
using namespace std;



class Solution{
public:
    int remove_duplicate(int a[],int n)
    {
        /*No use of extra space */
        int i=0;

        for(int j=1;j<n;j++)
        {
            if(a[j]!=a[i]){
                i++;
                a[i]=a[j];
            }
        }
        return i+1;
    }
};