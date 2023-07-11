
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

//node at dist k can be up or down
//but in a bt, we cannot travel to parent
//use map to store parents


//one level order iteration will connect all the parents and nodes
//HARD question

void markParents(Node* root,unordered_map<Node*,Node*> &parent_track){
    queue<Node*> queue;
    queue.push(root);

    while(!queue.empty()){
        Node* current=queue.front();
        queue.pop();
        if(current->left){
            parent_track[current->left]=current;
            queue.push(current->left);
        }

        if(current->right){
            parent_track[current->right]=current;
            queue.push(current->right);
        }
    }
}




vector<int> distanceK(Node* root,Node* target, int k){
    unordered_map<Node*,Node*> parent_track;
    markParents(root,parent_track);

    unordered_map<Node*,bool> visited;
    queue<Node*> queue;
    queue.push(target);//push the target first

    //radial traversal
    visited[target]==true;
    int curr_level=0;
    while(!queue.empty()){
        int size=queue.size();
        if(curr_level++==k) break;
        
        for(int i=0;i<size;i++){
            Node* current=queue.front();
            queue.pop();

            if(current->left && !visited[current->left]){
                queue.push(current->left);
                visited[current->left]=true;
            }

            if(current->right && !visited[current->right]){
                queue.push(current->right);
                visited[current->right]=true;

            }
            //upward direction

            if(parent_track[current] && !visited[parent_track[current]]){
                queue.push(parent_track[current]);
                visited[parent_track[current]]==true;
            }
        }


    }
    vector<int> result;
    //whatever is left in queue is the ans
    while(!queue.empty()){
        Node* current=queue.front();
        queue.pop();
        result.push_back(current->data);
    }
    return result;


}