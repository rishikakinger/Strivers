#include <bits/stdc++.h>
#include<iostream>
using namespace std;

//fifo

struct Queue{
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

};