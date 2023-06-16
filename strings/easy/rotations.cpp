
//left rotating x times is equivalent to right rotating (n-x) times

//check if length of s1 and s2 are same

//using KMP string matching algorithm
//do s3=s1+s1, search for s2 in s3


#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

 bool rotateString(string s, string goal) {
        
        if(s.length()!=goal.length())
            return false;

        string str = s + s;
        size_t found = str.find(goal);
       
        if(found != string::npos){//npos means no position
            return true;
        }
        else{
            return false;
        }
 }
