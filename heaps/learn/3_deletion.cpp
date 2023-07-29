
#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

//algorithm: swap last node with root, delete 

class heap{
    public:
    int arr[100];
    int size;

    heap(){
        arr[0]=-1;
        size=0;
    }

    void insert(int val){
        size++;
        int index=size;
        arr[index]=val;

        while(index>1){
            int parent=index/2;

            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
            }
            else{
                return;
            }


        }

    }

    void del(){
        if(size==0)return;
        arr[1]=arr[size];
        size--;

        //take root node to its current pos
        int i=1;
        while(i<size){
            int leftIndex=2*i;
            int rightIndex=2*i+1;

            if(leftIndex<size && arr[i]<arr[leftIndex]){
                swap(arr[i],arr[leftIndex]);
                i=leftIndex;
            }

            else if(rightIndex<size && arr[rightIndex]<arr[i]){
                swap(arr[i],arr[rightIndex]);
                i=rightIndex;

            }
            else{
                return;
            }
        }

    }
    //tc O(logn)

    



};