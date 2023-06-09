//did not understand jack shit, skipping this question 






// n*m will always be odd

//brute force soltuion: iterate over entire matrix, store elements in a data structure like arr, sort it, find middle element 
//O(nmlognm) time

//monotonic inc function 

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#define MAX 50
using namespace std;


   int median(vector<vector<int>> &matrix, int R, int C)
    {
        int min = INT_MAX, max = INT_MIN;
        for (int i = 0; i < R; i++)
        {
            if (matrix[i][0] < min)
                min = matrix[i][0];
     
            if (matrix[i][C-1] > max)
                max = matrix[i][C-1];
        }
     
        int desired = (R * C + 1) / 2;
        while (min < max)
        {
            int mid = min + (max - min) / 2;
            int place = 0;
            for (int i = 0; i < R; ++i)
                place += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            if (place < desired)
                min = mid + 1;
            else
                max = mid;
        }
        return min;
    }

    //time complexity is O(32 * R * log(C))