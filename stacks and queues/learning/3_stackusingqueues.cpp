#include <bits/stdc++.h>
#include<iostream>
using namespace std;

/*
PUSH OPERATION

1. add x to Q2
2. add all elements from Q1 to Q2
3. add all elements in Q1
tc O(n)
sc O(n)(2n)


POP OPERATION
1. remove the top of Q1 

*/

struct Stack{
    int arr[5];
int count=0;
int n;
int front=-1;
int rear=0;

void push(int x){
    if(count==n) return; //do nothing
    arr[rear%n]=x;
    rear++;
    count++;

}
void pop(){
    if(count==0) return;
    arr[front%n]=-1;
    front++;
    count--;
}

int top(){
    if(count==0)return -1;
    return arr[front%n];
}
    queue<int> Q1;
    queue<int> Q2;

    //ACTUAL SOLUTION STARTS HERE---------

    void push(int x){
        Q2.push(x);

        while(!Q1.empty()){
            Q2.push(Q1.front());
            Q1.pop();

        }

        swap(Q1,Q2);

    }

    void pop(){
        Q1.pop();
    }

    int top(){
        return Q1.front();
    }

    //IMPLEMENT STACK USING SINGLE QUEUE---------

    //push element
    //push other n-1 again

    void push(int x){
        Q1.push(x);
        for(int i=0;i<Q1.size()-1;i++){
            Q1.push(Q1.top());
            Q1.pop();
        }
    }
    void pop(){
        Q1.pop();
    }
    int top(){
        Q1.top();
    }

    
    
};


    



