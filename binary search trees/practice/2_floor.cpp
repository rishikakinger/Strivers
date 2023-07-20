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

int floorInBST(Node* root, int key){
    int floor=-1;
    while(root){

        if(root->data==key){
            floor=root->data;
            return floor;
        }

        if(key>root->data){
            floor=root->data;
            root=root->right;

        }
        else{
            root=root->left;
        }


    }
    return floor;

}