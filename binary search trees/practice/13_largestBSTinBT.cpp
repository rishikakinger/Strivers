
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
