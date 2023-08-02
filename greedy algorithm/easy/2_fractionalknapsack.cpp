#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

//we have to maximise value 

//find item which gives value per weight max 

//1. sort items wrt value per wt 
//value per wt mgiht be decimal so use float, for no loss of precision 


//tc nlogn for sorting+n for iterating 
//sc is o(1)

struct Item{
    int value;
    int weight;
};

//comparator- discussed in striver stl video

bool comp(Item a, Item b){
    double r1=(double)a.value/(double)a.weight;
    double r2=(double)b.value/(double)b.weight;

    return r1>r2;

}



double fractionalKnapsack(int W, Item arr[], int n){

    sort(arr,arr+n,comp);

    int curWeight=0;
    double finalvalue=0;

    for(int i=0;i<n;i++){
        if(curWeight+arr[i].weight<=W){
            curWeight+=arr[i].weight;
            finalvalue+=arr[i].value;
        }
        else{
            int remain=W-curWeight;
            finalvalue+=(arr[i].value/(double)arr[i].weight)*(double)remain;
            break;
        }
    }
    return finalvalue;

}