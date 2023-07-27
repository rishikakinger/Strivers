
#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

//find min element in stack in constant time

//M1: using pairs 
//store {vale, min element till then}
//tc O(1) sc O(2n)

class MinStack {
public:
    vector< pair<int,int> > s;
	
    MinStack() { }
    
    void push(int val) {
        if(s.empty())
            s.push_back({val,val});
        else
            s.push_back({val,min(s.back().second,val)});    
    }
    
    void pop() { s.pop_back(); }
    
    int top() { return s.back().first; }
    
    int getMin() { return s.back().second; }
};


//optimal uses complex math

class MinStack{
    stack<long,long> st;//mathematical operations might make int overflow
    long long mini;

    public:

    MinStack(){
        while(st.empty()==false)st.pop(); //not required
        mini=INT_MAX;
    }

    void push(int value){
        long long val=value;//store it in long long
        if(st.empty()){
            mini=val;
            st.push(val);

        }
        else{
            if(val<mini){
                st.push(2*val*1LL-mini);
                mini=val;
            }
            else{
                st.push(val);
            }
        }

    }
    void pop(){
        if(st.empty()) return;

        long long el=st.top();
        st.pop();

        if(el<mini){
            mini=2*mini-el;
        }
    }

    int top(){
        if(st.empty()) return -1;

        long long el=st.top();
        if(el<mini)return mini;
        return el;
    }

    int getMin(){
        return mini;
    }

    
};

//tc O(1)
//sc O(n)