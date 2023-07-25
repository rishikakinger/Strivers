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

//have to be 2 integers only

//m1: take inorder, store in array, it is now a normal 2 sum problem
//tc O(2n) sc O(n)

//use next() from prev qs


stack<Node*> myStack;


/*before function


int before(){
    Node* tempNode=myStack.top();
    myStack.pop();
    pushAll(tempNode->left);
    return tempNode->data;
}
void pushAll(Node* node){
    for(;node!=NULL;myStack.push(node),node=node->right);

}

*/

//tc is O(N)
//sc is O(2H)


class BSTIterator{

    stack<Node*> myStack;
    bool reverse=true;//it is before, not next
public:
BSTIterator(Node* root,bool isReverse){
    reverse=isReverse;
    pushAll(root);

}

int next(){
    Node* temp=myStack.top();
    myStack.pop();
    if(!reverse)pushAll(temp->right);
    else{
        pushAll(temp->left);
    }
    return temp->data;
}



bool hasNext(){
    return !myStack.empty();
}

private:
void pushAll(Node* node){
    while(node!=NULL){
        myStack.push(node);
        if(reverse==true){
            node=node->right;
        }
        else{
            node=node->left;
        }
    }

}
};

class Solution{
public:
    bool findTarget(Node* root,int k){
        if(!root)return false;
        BSTIterator left(root,false);
        BSTIterator right(root,true);

        int i=left.next();
        int j=right.next();

        while(i<j){
            if(i+j==k)return true;

            else if(i+j<k)i=left.next();
            else j=right.next();
        }
        return false;


    }


};