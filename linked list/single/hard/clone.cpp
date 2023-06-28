
//brute force solution is using extra space (hashmap)

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;


class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};



Node* copyRandomListBrute(Node* head) {
    unordered_map<Node* , Node*> m;
    Node *ptr = head;
    while(ptr)
    {
        m[ptr] = new Node(ptr->val);
        ptr = ptr->next;
    }
    ptr = head;
        
    while(ptr)
    {
        m[ptr]->next = m[ptr->next];
        m[ptr]->random = m[ptr->random];
        ptr=ptr->next;
    }
    return m[head];
}


Node* copyRandomListOptimal(Node* head) {
        if(head==NULL) return NULL;


        // Step 1: 
        // Create a copy of each node 
        // keep next ptr and random ptr of new node equal to random ptr of equivalenmt old node

        Node* newhead = NULL;
        Node* cur = head;
        Node* cur1 = head;

        while(cur!=NULL){
            Node* temp = new Node(cur->val);
            temp->random = cur->random;
            temp->next = cur->random;
            cur->random = temp;
            if(newhead == NULL){
                newhead = temp;
            }
            cur = cur->next;
        }


        // Step 2:
        // Change the value of random ptr of new node with the equivalent newly created nodes ptr
        cur = head;
        while(cur!=NULL){
            if(cur->random->random!=NULL)
                cur->random->random = cur->random->random->random;
            cur = cur->next;
        }


        // Step 3:
        // Till now new linked list are isolated and are not linked 
        // Random ptr of old LL contains the address of new head
        // Next ptr of new node contains the actual random ptr of old LL
        // Now, traverse old LL and restoore the random ptr from new LL and link the new LL whose next address is present in the random ptr of next node of old LL
        cur = head;
        cur1 = newhead;

        while(cur->next!=NULL){
            Node* temp = cur->next->random;
            cur->random = cur1->next;
            cur1->next = temp;
            cur = cur->next;
            cur1 = cur1->next;
        }

        cur->random = cur1->next;
        cur1->next = NULL;

        return newhead;
    
}