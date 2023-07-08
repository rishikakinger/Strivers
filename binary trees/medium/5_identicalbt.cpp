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

//traverse trees, both should be same
//inorder/postorder/preorder

bool isSameTree(Node* p,Node* q){
    if(p==NULL||q==NULL) return (p==q);

    return (p->data==q->data)&&isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
    

}

//tc is O(n)
//sc is O(n)