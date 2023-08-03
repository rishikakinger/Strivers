#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

//try to perform job with larger deadline as late as possible
//so that one with shorter deadline can be performed before

//tc is nlogn for sorting + n*m for checking which day for each job
//sc is O(m)

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};


bool comparision(Job a, Job b){
    return (a.profit>b.profit);
}


pair<int,int> JobScheduling(Job arr[],int n){

    sort(arr,arr+n,comparision);

    int maxi=arr[0].dead;

    for(int i=1;i<n;i++){
        maxi=max(maxi,arr[i].dead);
    }//to find size of array we have to make

    int slot[maxi+1];

    for(int i=0;i<=maxi;i++){
        slot[i]=-1;
    }

    int countJobs=0;
    int jobProfit=0;

    for(int i=0;i<n;i++){
        for(int j=arr[i].dead;j>0;j--){
            if(slot[j]==-1){
                slot[j]=i;
                countJobs++;
                jobProfit+=arr[i].profit;
                break;
            }
        }
    }

    return make_pair(countJobs,jobProfit);


}