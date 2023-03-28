//containers that are dynamic in nature
//can always change size
//use when size is not known 


#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;


void explainVector(){
    vector<int> v;

    v.push_back(1);//will add 1 to the empty vector
    v.emplace_back(2); //similar to pushabck but faster

    //vector of pair data type
    vector<pair<int,int>> vec;
    vec.push_back({1,2});
    vec.emplace_back(1,2);

    //vector with 100,100,100,100,100
    vector<int> v1(5,100);

    //vector with 5 instances(of 0 by default or garbage value- depends on complier);
    vector<int> v(5);

    //v1 will be a vector also with 5 instances of 100
    vector<int> v2(v1);

    //access is similar to an array eg. v[1], v[0], etc
    cout<<v[0]<<" same as "<<v.at(0);

/***********************************************************************************/

    //iterators

    vector<int>::iterator random=v.begin(); //syntax:  datatype::iterator 
    //points to memory address of first element of v 
    //basically pointer for vector

    cout<<*(random);
    random=random+2;//points to element after the next element

    vector<int>::iterator lastnext= v.end(); //points to whatever is after the last element
    lastnext--;//now points to last element

    //v.rend()---> reverse v and then end
    //v.rbegin()----> reverse v then beginning
    //v.back()----> last element 


}
