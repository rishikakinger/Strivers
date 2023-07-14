
#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

void letterCombinations(string digits,vector<string>& ans,string& temp,vector<string>& options,int index){
    if(index==digits.size()){
        ans.push_back(temp);
        return;
    }

    string value=options[digits[index]-'0'];

    for(int i=0;i<value.size();i++){
        temp.push_back(value[i]);
        letterCombinations(digits,ans,temp,options,index+1);
        temp.pop_back();
    }



}

vector<string> letterCombinations(string digits){
    vector<string> ans;
    if(digits.empty()){
        return ans;
    }

    vector<string> options={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    string temp;

    letterCombinations(digits,ans,temp,options,0);

    return ans;

}