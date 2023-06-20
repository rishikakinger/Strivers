
//it is a sorted doubly linked list

  
#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;


class Node{
public:
    Node* prev;
    int data;
    Node* next;

    Node()
    { 
        prev = NULL; 
        data = 0;
        next = NULL;
    }
    
    Node(int value)
    { 
        prev = NULL; 
        data = value;
        next = NULL;
    }
};
  
  
  
   vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        // code here
        vector<pair<int, int>> result;
        
        Node *start = head, *end=NULL;
        if(!head->next) return {} ;
        
        while(head->next)
         {
             head=head->next;
         }
        end=head;
        
        while(start->data < end->data)
         {
             if (start->data + end->data == target) 
              {
                  result.push_back({start->data, end->data});
                  start=start->next,  end=end->prev;
              }
             else if (start->data + end->data > target)
                 end=end->prev;
             else
                 start=start->next;
         }
        
        return result;
        
    }