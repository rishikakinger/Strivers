/*

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.


*/

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

//tc is (nlogk)

//2 approaches: one is minheap and other is merge sort(refer merge 2 sorted linked lists-medium)



//APPROACH 1: MIN HEAP


struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> q;
        int n = lists.size();
        for(int i=0; i<n; i++){
            ListNode* temp = lists[i];
            while(temp){
                q.push(temp->val);
                temp = temp->next;
            }
        }
        if(!q.size())return NULL;
        ListNode* head = new ListNode(q.top());
        q.pop();
        ListNode* temp = head;
        while(!q.empty()){
            temp->next = new ListNode(q.top());
            q.pop();
            temp = temp->next;
        }
        return head;
    }
};




//APPROACH 2: merge sort 

class Solution {
public:
    // Sort and merge two linked lists
    ListNode* merge(ListNode* left, ListNode* right){
        ListNode* merged = new ListNode(0);
        ListNode* temp = merged;
        while(left && right){
            if(left->val < right->val){
                temp->next = left;
                left = left->next;
            }
            else{
                temp->next = right;
                right = right->next;
            }
            temp = temp->next;
        }
        while(left){
            temp->next = left;
            left = left->next; 
            temp = temp->next;
        }
        while(right){
            temp->next = right;
            right = right->next;
            temp = temp->next;
        }
        return merged->next;
    }

    // Merge sort recursively
    ListNode* mergeSort(vector<ListNode*>& lists, int st, int end){
        if(st >= end)
            return lists[st];
        int mid = st + (end-st)/2;
        ListNode* left = mergeSort(lists, st, mid);
        ListNode* right = mergeSort(lists, mid+1, end);
        return merge(left, right);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)return NULL;
        return mergeSort(lists, 0, lists.size()-1);
    }
};