#include<bits/stdc++.h>
#include<iostream>
#include<queue>
using namespace std;

/*
WHY PQ AND NOT NORMAL Q WHEN WE STILL GET ANS?

leads to duplicate paths 
it keeps going to all paths 
more of a brute force 
unecessary exploration of paths 
if it isnt the lowest, wont even be counted in the end


*/

/*

WHY IS TC ELOGV WHERE E IS TOTAL NO OF EDGES AND V IS NO OF VERTICES

tc will be O(V x (pop vertex from minheap+no of edges on each vertexx push into PQ))

refer strivers video


*/