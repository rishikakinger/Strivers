/*

Solution 2: Space-optimized iterative method

Approach: Unlike the previous method we use the same array to obtain the result. Follow the steps below.

1.Keep a pointer p1  at the first index and another p2 at the last index of the array. 
2.Swap the elements pointed by p1 and p2, Post swapping increment p1 and decrement p2.
3.This process is repeated for only the first n/2 elements where n is the length of array.

Note: Swapping all the n elements instead of n/2 elements leaves the array unaltered.

*/

#include <iostream>

using namespace std;
//Function to print array
void printArray(int arr[], int n) {
   cout << "The reversed array is:- " << endl;
   for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
   }
}

//Function to reverse array 
void reverseArray(int arr[], int n) {
   int p1 = 0, p2 = n - 1;//pointer doesnt mean actual pointer
   while (p1 < p2) {//IMP CONDITION
      swap(arr[p1], arr[p2]);//The function std::swap() is a built-in function in the C++ Standard Template Library (STL) which swaps the value of two variables. can swap str and other datatypes also
      p1++; p2--;
   }
   printArray(arr, n);
}
int main() {
   int n = 5;
   int arr[] = { 5, 4, 3, 2, 1};
   reverseArray(arr, n);
   return 0;
}