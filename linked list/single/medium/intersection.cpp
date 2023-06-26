//leetcode qs
//linked lists are Y linked lists 
//check if nodes are same NOT VALUES


//brute force is O(m*n)


//better: use hashing 
//HASH ADDRESSES NOT VALUES
//O(n+m)

//optimal: 2 approaches possible 
//1
//find length of the two LLs, subract, use dumm1 and dummy 2
// if they dont intersect, dummy 1 and 2 will return NULL at the same time
//O(2M)


//2
//intuition is insane
//O(2M)
//smaller and concise code


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


Node* getInt(Node* head1, Node* head2){
    if(head1==NULL || head2==NULL) return NULL;

    Node* a=head1;
    Node* b=head2;

    while(a!=b){
        a=a==NULL? head2: a->next;
        b=b==NULL? head1: b->next;
    }
    return a;

}