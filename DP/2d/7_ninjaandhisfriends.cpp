#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

//3D DP QUESTION 

//fixed starting position
//variable ending point 
//can move down, bottom left and bottom right 


//greedy doesnt work 

//cant call recurrence only for alice and then call it only for bob and add- they can intersect also 

//for base case- always write out of bounds case first 

//both will reach destination at the same time- only allowed to go downwards
//hence, only need to store i; i1 and i2 not required 


int f(int i, int j1, int j2, int n, int m,vector<vector<int>> a,vector<vector<vector<int>>>& dp){
    if(j1<0 || j1>=m || j2<0 || j2>=m)return -1e8;

    if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];

    if(i==n-1){
        if(j1==j2)return a[i][j1];
        return a[i][j1]+a[i][j2];

    }
    //BIG QUESTION: HOW TO MAKE THEM MOVE TOGETHER???
    //FOR EVERY MOVEMENT OF ALICE, BOB CAN MOVE IN 3 DIRECTIONS 
    //total 9 combinations of path have to try

    int maxi=-1e8;

    for(int dj1=-1;dj1<=1;dj1++){
        for(int dj2=-1;dj2<=1;dj2++){
            if(j1==j2)maxi=max(a[i][j1]+f(i+1,j1+dj1,j2+dj2,n,m,a,dp),maxi);
            else{
                maxi=max(maxi,a[i][j1]+a[i][j2]+f(i+1,j1+dj1,j2+dj2,n,m,a,dp));
            }

        }
    }
    return dp[i][j1][j2]=maxi;

}

//recursion 
//tc is 3^n  x 3^n
//sc is n 

//memoization 
//tc is of nxmxmx9
//note in all the other cases the last x3, x2 part was ignored as it was small, but 9 is a large no and hence we should consider it 
//sc is of nxmxm+n
