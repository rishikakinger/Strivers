//original approach thought of was complicated 

//easy apporach: iterate from end, stop at first odd no and return string from beginning

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;



    string largestOddNumber(string num) {
        int n=num.size();
        int r;
        bool flag=false;
        for(int i=n-1;i>=0;i--)
        {
            if(num[i]%2!=0)
            {
                r=i;
                flag=true;
                break;
            }
        }
        if(flag)
            return num.substr(0,r+1);
        else
            return "";
    }

    //.substr() fnc----imp