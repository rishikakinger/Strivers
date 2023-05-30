//brute force soln
//first row->last column
//second row->second last column
//arr[j][n-1-i]=matrix[i][j]



//better solution is to solve it in-place

//transpose and then reverse every row

//while converting to transpose- imp observation is that diagonal elements remain the same

#include<vector>
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void rotateMatrix(vector<vector<int>> &mat){
    int n=mat.size();//gives size of y
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){//from observation
            swap(mat[i][j], mat[j][i]);
        }
    }
    //O(N/2*N/2)

    for(int i=0;i<n;i++){
        reverse(mat[i].begin(),mat[i].end());//runs for N/2
    }

    //O(N*N/2)



}

//DOUBT: HOW TO ROTATE COLUMNS OF A MATRIX?

//    for(int i=0;i<n;i++){
    //    int start = 0;
    //     int end = n- 1;

    //     while (start < end) {
    //         // Swap the element
    //         swap(mat[start][i], mat[end][i]);

    //         // Increment start and decrement
    //         // end for next pair of swapping
    //         start++;
    //         end--;
    //     }
    // }