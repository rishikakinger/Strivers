#include<queue>
#include<bits/stdc++.h>
#include<iostream>
#include<set>
#include<unordered_set>
using namespace std;

//at a time, only 1 letter can be changed
//for it to be valid, it has to be in the list 

//brute: take every character in word, change from a-z

//bfs

//searching in set has less tc than searching in vector

//after encountering a word, remove it from wordlist. Why? what if you encounter it again? Ans: pointless as that route will be longer anywyas (watch striver video for further explanation)

//HENCE V IMP TO USE SET IN THIS QS

int wordLadder(string startWord, string targetWord,vector<string>& wordList){
    queue<pair<string,int>> q;
    q.push({startWord,1});
    unordered_set<string> st(wordList.begin(),wordList.end());//how to put entire vector in set
    st.erase(startWord);
    while(!q.empty()){
        string word=q.front().first;
        int steps=q.front().second;
        q.pop();
        if(word==targetWord)return steps;

        for(int i=0;i<word.size();i++){
            char original=word[i];//what we are lookign to change
            for(char ch='a';ch<='z';ch++){
                word[i]=ch;

                //check if it exists in the set
                if(st.find(word)!=st.end()){
                    st.erase(word);
                    q.push({word,steps+1});
                }
            }
            word[i]=original;

        }
    }
    return 0;

}
