/*

Also, there are lots of edge cases which you should clarify in an interview. The questions like:

Should tweets of a person be included in the getNewsFeed function?
Are all of the queries valid?
Is it possible that there is a query to unfollow without preceding follow function? The same values for followerId and followeeId etc. (see 2)



*/

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

class Twitter {

private:
    unordered_map<int,set<int,int>> fo;
    //set insertion and deletion is O(logn)
    //no duplicate elements allowed in set
    
    long long time;//to keep track of posting time

    unordered_map<int,vector<pair<int,int>>> t;
    //for feed
    //userID---->{time of tweet 1, tweet Id 1}, {time of tweet 2, tweed Id2}, {time of tweet 3, user Id 3}, etc....


public:
    Twitter() {

        
        
    }
    
    void postTweet(int userId, int tweetId) {
        t[userId].push_back({time++,tweetId});
        
    }




    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> maxheap;

        //first put all of user's own tweets
        for(auto it=t[userId].begin();it!=t[userId].end();it++){
            maxheap.push(*it);
        }


        for(auto it1=fo[userId].begin(); it1!=fo[userId].end();it1++){
            int user=*it1;

            for(auto it2=t[user].begin();it2!=t[user].end();it2++){
                maxheap.push(*it2);
            }
        }

        vector<int> res;

        while(maxheap.size()>0){
            res.push_back(maxheap.top().second);
            if(res.size()==10) break;
            maxheap.pop();
        }
        return res;

        
    }
    






    void follow(int followerId, int followeeId) {
        //follower is following followee 

        if(followeeId!=followerId){
            fo[followerId].insert(followeeId);

            //person1----> people he is following
        }
        
    }
    
    void unfollow(int followerId, int followeeId) {
        fo[followerId].erase(followeeId);
        
    }

    
};
