
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


//brute: first find if it is valid, then find no of nodes, O(n^2)

//optimal: if largest on LST is smaller than root and smallest on RST is greater than root

//postorder traversal
//why?
//imp logic

//if not BST- size=max(left,right), max=INT MAX, min=INT MIN
//if NULL- size=0, max=INT_MIN, min=INT_MAX

//tc O(n)
//sc O(1)


class NodeValue{
    public:
    int minNode, maxNode, maxSize;

    //constructor
    NodeValue(int minNode,int maxNode, int maxSize){
        this->maxNode=maxNode;
        this->minNode=minNode;
        this->maxSize=maxSize;

    }
};

class Solution{
    private:

    NodeValue largestBSTSubtreeHelper(Node* root){
        if(!root){
            return NodeValue(INT_MAX,INT_MIN, 0);
        }

        //first get values from left and right

        auto left=largestBSTSubtreeHelper(root->left);
        auto right=largestBSTSubtreeHelper(root->right);

        if(left.maxNode<root->data && root->data<right.minNode){
            //it is a BST
            return NodeValue(min(root->data,left.minNode),max(root->data,right.maxNode),left.maxSize+right.maxSize+1);

        }
        return NodeValue(INT_MIN,INT_MAX,max(left.maxSize,right.maxSize));
        




    }


    public:
    int largestBSTSubtree(Node* root){
        return largestBSTSubtreeHelper(root).maxSize;

    }



};