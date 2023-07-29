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


//heapify
//only need to process 1 to n/2 as rest are leaf nodes 

void heapify(int arr[],int n,int i){
    int largest=i;
    int left=2*i;//2i+1 for 0 based indexing
    int right=2*i+1;//2i+2 for 0 based indexing

    if(left<n && arr[largest]<arr[left]){
        largest=left;

    }
    if(right<n && arr[largest]<arr[right]){
        largest=right;
    }

    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }

}//tc O(logn)

void heapifyMain(int arr[], int n){
    for(int i=n/2;i>0;i--){//check from bottom
        heapify(arr,n,i);
    }//tc O(n)

}

