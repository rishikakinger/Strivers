#include <bits/stdc++.h>
#include<iostream>
using namespace std;

int arr[5];

int top=-1;

void push(int x){
    arr[++top]=x;

}

void pop(){
    top--;
}

int topelement(){
    return arr[top];
}

int size(){
    return top+1;

}

bool isEmpty(){
    return top==-1;
}