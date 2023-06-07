/*
Given an array, find a peak element(print anyone, if many are found). A peak element is one such that it is either greater than or equal to its neighbours. For the first and last element, it is enough to look at its only one neighbour.

*/
//NOT A SORTED ARRAY

//brute force: iterate through entire array

#include<iostream>

using namespace std;

int peakEleBruteForce(int arr[], int n) {
  if (arr[0] >= arr[1])
    return arr[0];

  for (int i = 1; i < n - 1; i++)
    if (arr[i] >= arr[i - 1] && arr[i] >= arr[i + 1])
      return arr[i];

  return arr[n - 1];
}

//time complexity O(n)