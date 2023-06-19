#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;
  
    // Default constructor
    Node()
    {
        data = 0;
        next = NULL;
    }
  
    // Parameterised Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

//using 2 pointers

    Node* constructLL(vector<int>& arr) {
        Node* head = NULL;
        Node* cur = new Node();
        cur->data = arr[0];
        cur->next = NULL;
        head = cur;
        //curr->tmp
        for (int i = 1; i < arr.size(); i++) {
            Node* tmp = new Node();
            tmp->data = arr[i];
            tmp->next = NULL;
            cur->next = tmp;
            cur = tmp;
        }
        return head;
    }