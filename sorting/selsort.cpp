//GFG ques
//int n wasnt being passed to select so how was i supposed to solve?
//THIS IS HOW:
//SMART STUFF
//selection sort can happen from either side 



#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution
{
    public:
    int select(int arr[], int i)
    {
        int max = arr[0], ind = 0;
        for (int j=1; j<=i; j++)
        {
            if (arr[j] > max)
            {
               ind = j;
               max = arr[j];
            }
        }
        return ind;
    }
    
    public:
    void selectionSort(int arr[], int n)
    {
       int i, j;
       for (i = n-1; i >=0; i--)      
       {
            int j = select(arr, i);
            swap(arr[i], arr[j]);
       }
    }
};