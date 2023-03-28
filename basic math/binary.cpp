//kanthi said use bitwise operator

#include<bits/stdc++.h>
#include<iostream>
using namespace std;



#include <bits/stdc++.h>
using namespace std;
 
  void bin(long n)
  {
    long i;
    cout << "0";
    for (i = 1 << 30; i > 0; i = i / 2) //i/2 is done to shift it right
    {
      if((n & i) != 0)
      {
        cout << "1";
      }
      else
      {
        cout << "0";
      }
    }
  }
 
// Driver Code
int main(void)
{
    bin(7);
    cout << endl;
    bin(4);
}