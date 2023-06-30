
//found this a little tricky


#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;


void insertAtBottom(stack<int>& s,int item){//forgot to put & here and it fucked my whole code up :(((
    if(s.empty()){//can become empty gain
        s.push(item);
    }
    else{
        int temp=s.top();
        s.pop();
        insertAtBottom(s,item);
        s.push(temp);
    }

}



void Reverse(stack<int> &s){
    if(!s.empty()){
        int temp=s.top();
        s.pop();
        Reverse(s);
        insertAtBottom(s,temp);
    }

}