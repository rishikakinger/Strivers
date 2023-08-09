/*M1:
iterate all nos till n, check if divisible---> unecessary, not as efficient, O(n)


M2:
beyond sqrt(n), nos are repeating
only catch is that it wont print them in order

*/

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

void div(int n){
    vector<int> ls;
    for(int i=0;i<=sqrt(n);i++){ //IMP NOTE: sqrt() is a fnc that will be called everytime and make code slow, use i*i<=n
        if(n%i==0){           
            ls.push_back(i);
            if((n/i)!=i){
                ls.push_back(n/i);//to avoid repitive 
            }
        }
    }
    //for loop is of O(sqrt(n)) 



    sort(ls.begin(),ls.end()); //IMP:HOW TO SORT A VECTOR 

    //internal sorting is of O(nlogn)-- where n is no of factors

    //Now, printing the vector list
    for(auto it:ls){
        cout<<it<<" ";

    }
    //printing list is of O(n)-- where n is no of factors
     
}

//what if i want the elemnts in sorted order?--- using vectors 


