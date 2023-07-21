//kth smallest element in a binary search tree



#include<bits/stdc++.h>
#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

//brute: dfs/bfs traversal, sort, kth from beg O(n+nlogn), sc of O(n)

//optimal:property-if you write inorder of bst, it is always in sorted order
//keep counter to avoid O(n) storage

//recursive O(n), O(n)
//morris O(n),O(1)


#include<bits/stdc++.h>
#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};



int getInorder(Node* root,int k){
   
        int count = 0;
        int ans;
        Node* curr = root;
        
        while(curr){
            if(curr->left == NULL){
                count++;
                if(count == k){
                    ans = curr->data;
                }
                
                curr = curr->right;
            }
            else{
                Node* prev = curr->left;
                
                while(prev->right && prev->right != curr){
                    prev = prev->right;
                }
                
                if(prev->right == NULL){
                    prev->right = curr;
                    curr = curr->left;
                }
                else{
                    count++;
                    prev->right = NULL;
                    if(count == k){
                        ans = curr->data;
                    }
                    curr = curr->right;
                }
            }
        }
        
        return ans;
    }

