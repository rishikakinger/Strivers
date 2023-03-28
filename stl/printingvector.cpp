#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;


void iterator(vector<int>v){


/***********************************************************************************/

    //iterating through vector

    for(vector<int>::iterator it=v.begin(); it!=v.end();it++){
        cout<<*(it);
    }

    //short form for vector<int>::itertaor is auto 
    //ALTERNATIVE:

    for(auto it=v.begin(); it!=v.end();it++){
        cout<<*(it);
    }
    //NOTE: auto automatically assigns datatype

    //ALTERNATIVE USING FOR EACH LOOP

    for(auto it:v){
        cout<<it;
    }
}