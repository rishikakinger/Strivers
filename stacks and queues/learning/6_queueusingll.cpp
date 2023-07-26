
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


struct Queue {
   Node* front;
   Node* rear;
   void push(int);
    int pop();
    
    Queue() {
        front = rear = NULL;
    }
  };
  
 
void Queue::push(int x) {
    // Creating a dummy node
    Node* tempNode = new Node(x);
    
    if(front == NULL) {
        // Assigning both 'front' and 'rear' to 'tempNode'
        front = rear = tempNode;
    }
    else {
        // Assigning the 'next' of rear to 'tempNode'
        // and assigning 'rear' to rear->next
        rear -> next = tempNode;
        rear = rear -> next;
    }
}



int Queue::pop() {
    // Creating a dummy node
    Node* tempNode = front;
    
    // Queue is empty
    if(tempNode == NULL) {
        return -1;
    }
    
    // Initialising the variable 'ans'
    int ans = tempNode -> data;
    
    if(tempNode -> next != NULL) {
        // Shifting 'front'
        tempNode = tempNode -> next;
        delete(front);
        front = tempNode;
    }
    else {
        // Making both 'rear' and 'front' as NULL
        delete(front);
        front = rear = NULL;
    }
    
    return ans;
}
