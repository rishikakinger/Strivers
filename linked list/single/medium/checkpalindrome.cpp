//no of nodes can e 10^5 hence cant store in var or anything 
//have to traverse only

//time complexity is n/2+n/2+n/2


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


Node* reverseList(Node* head){
    Node* pre=NULL;
    Node* next=NULL;
    while(head!=NULL){
        next=head->next;
        head->next=pre;
        pre=head;
        head=next;
    }
    return pre;

}





bool isPalindrome(Node* head){
    if(head==NULL || head->next==NULL) return true;

    Node* slow=head;
    Node* fast=head;

    //step 1: find middle
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    slow->next=reverseList(slow->next);
    slow=slow->next;

    while(slow!=NULL){
        if(head->data!=slow->data){
            return false;

        }
        head=head->next;
        slow=slow->next;
    }
    return true;


}