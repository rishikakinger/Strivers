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

//method1: use hashing
//method2: slow and fast pointer method

/*
METHOD 2
1. find collision point by moving fast by 2 steps and slow by 1 step
2.next take an extra pointer, at the beginning of the linked list, lets call it entry
3. move entry by 1 and slow by 1
4. the point at which entry and slow collide is the entry of the loop

also, if fast pointer reaches null, theres no loop in the linked llst

time complexity O(n)
proof is mathematical 


*/

Node* cycleEntry(Node* head){
    if(head==NULL || head->next==NULL) return NULL;

    Node* fast=head;
    Node* slow=head;
    Node* entry=head;

    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next;
        if(slow==fast){
            while (slow!=entry){
                slow=slow->next;
                entry=entry->next;

            }
            return entry;
        }

    }
    return NULL;

}

//time complexity is NOT O(n^2)