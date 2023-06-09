
//peak element in 2d is element strictly greater than all of its adjacent neighbours to left,right,top,bottom



#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

vector<int> findPeakGrid(vector<vector<int>>& mat){
    int startCol=0,endCol=mat[0].size()-1;
    
    while(startCol<=endCol){
        //find mid col
        int maxRow=0, midCol=startCol+(endCol-startCol)/2;
        //initially, assume maxRow is 0

        //find max element in that mid column
        for(int row=0; row<mat.size();row++){

            maxRow=mat[row][midCol]>=mat[maxRow][midCol]? row: maxRow;

        }
        //since it is the max in the column it is already greater than top and bottom

        bool leftIsBig=midCol-1>=startCol&& mat[maxRow][midCol-1]>mat[maxRow][midCol];
        bool rightIsBig=midCol+1<=endCol&& mat[maxRow][midCol+1]>mat[maxRow][midCol];


        if(!leftIsBig && !rightIsBig){
            return vector<int>{maxRow,midCol};
        }

        else if(rightIsBig){
            startCol=midCol+1;
        }
        else{
            endCol=midCol-1;
        }
    }
    return vector<int>{-1,-1};

}
//time complexity O(nlogm)