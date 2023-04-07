//HASHING FOR NUMBERS

//if max no we can go till is 12, need array of 13, ie n+1 so we can store n element also

//in normal searching, time complexity is O(QN) where Q is no of queries 


#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
    int n;//array size
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int hash[13]={0};//dont have to iterate and intialize everything to zero
    for(int i=0;i<n;i++){
        hash[arr[i]]+=1;
    }


    //taking input for query
    int q;
    cin>>q;
    while(q--){
        int number;
        cin>>number;
        //fetch
        cout<<hash[number]<<endl;


    }



    

}