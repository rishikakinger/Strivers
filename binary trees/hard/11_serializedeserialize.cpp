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

string serialize(Node* root){
    if(!root)return "";
    string s="";
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* currNode=q.front();
        q.pop();

        if(currNode==NULL)s.append("#,");
        else s.append(to_string(currNode->data)+',');

        if(currNode!=NULL){
            q.push(currNode->left);
            q.push(currNode->right);
        }
        return s;
    }
}


//stringstream and getline is ued to iterate over the string

Node* deserialize(string data){

    if(data.size()==0) return NULL;

    stringstream s(data);
    string str;
    getline(s,str,',');
    Node* root=new Node(stoi(str));
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* node=q.front();
        q.pop();

        getline(s,str,',');
        if(str=="#"){
            node->left=NULL;
        }
        else{
            Node* leftNode= new Node(stoi(str));
            node->left=leftNode;
            q.push(leftNode);//imp step
        }


        getline(s,str,',');

        if(str=="#"){
            node->right=NULL;
        }
        else{
            Node* rightNode=new Node(stoi(str));
            node->right=rightNode;
            q.push(rightNode);
        }


    }
    return root;

}

//tc is O(n)
//sc is O(n)