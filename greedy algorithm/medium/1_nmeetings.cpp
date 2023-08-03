#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;


//the sooner the meeting ends, more chances of holding more meetings in the room
//sort in inc order of ending time 

//tc n(for traversing & putting it into ds)+nlogn for sorting+ n for traverse in ds

//sc is n

struct meeting{
    int start;
    int end;
    int pos;

};

bool comparator(struct meeting m1, struct meeting m2){
    if(m1.end<m2.end)return true;

    else if(m1.end>m2.end)return false;
    else if(m1.pos<m2.pos)return true;//NOTE: SOLN WORKS ONLY IF YOU TAKE FIRST INDEX THAT COMES FIRST
    return false;
}


void maxMeeting(int s[],int e[],int n){
    //array of meetings 

    struct meeting meet[n];
    for(int i=0;i<n;i++){
        meet[i].start=s[i],meet[i].end=e[i],meet[i].pos=i+1;//meetings are 1 based indexing 

    }

    sort(meet,meet+n,comparator);

    vector<int> ans;//stores all pos of meeting possible

    int limit=meet[0].end;
    ans.push_back(meet[0].pos);

    for(int i=1;i<n;i++){//1 already selected
        if(meet[i].start>limit){
            limit=meet[i].end;
            ans.push_back(meet[i].pos);
        }


    }



}