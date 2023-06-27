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

//brute force soln is to take the last node and put it in the first pos, k times 
//tc is O(k x N)


//optimal
//convert it to a circular linked list!
//tc is O(N)


Node* rotateRight(Node* head, int k){

    //edge cases 
    if(!head || !head->next || k==0) return head;

    //computing the length
    Node* curr=head;
    int cnt=0;
    while(head){
        cnt++;
        curr=curr->next;
    }

    //make is a circular linked list
    curr->next=head;

    //traversing till that node
    k=k%cnt;
    k=cnt-k;

    while(k--) curr=curr->next;

    head=curr->next;
    curr->next=NULL;

    return head;

}