
#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node()
    {
        data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

bool detectLoop(Node* head){
    Node* temp=head;
    unordered_map<Node*,int> umap;

    while(temp){
        if(umap.find(temp)!=umap.end()){
            return true;
        }



        umap[temp]++;
        temp=temp->next;
    }
    return false;
}
//imp part here is hash the entire NODE, as duplicate values may exist 


//optimal 

//use fast and slow pointers, at some point fast is bound to catch up with slow 
//no space complexity and time is O(N)

//if you move slow by 1 and fast by 2 THEY WILL MEET NO MATTER WHAT


bool detectLoopOptimal(Node* head){
    if(head==NULL || head->next==NULL) return false;

    Node* fast=head;
    Node* slow=head;

    while(fast->next!=NULL && fast->next->next!=NULL){//imp to understand this condition
    fast=fast->next->next;
    slow=slow->next;
    if(fast == slow){
        return true;
    }

    }
    return false;



}