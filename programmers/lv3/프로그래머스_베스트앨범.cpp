#include <string>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

set<string> myset;
vector<pair<int,string>> v;
map<string,vector<pair<int,int>>> mp;


bool compare(pair<int,int> a, pair<int,int> b) {
    if(a.first==b.first) a.second<b.second;
    else
    return a.first > b.first; // 반환 값이 true면 a를 b보다 앞으로 배치 (내림차순)
}
bool compare2(pair<int,string> a, pair<int,string> b) {
    return a.first > b.first; // 반환 값이 true면 a를 b보다 앞으로 배치 (내림차순)
}

vector<int> solution(vector<string> genres, vector<int> plays) {
        vector<int> answer;
    for(int i=0; i<genres.size(); i++){
        myset.insert(genres[i]);
    }

    for(int i=0; i<genres.size(); i++){
        mp[genres[i]].push_back({plays[i],i});
        sort(mp[genres[i]].begin(),mp[genres[i]].end(),compare);
    }

    for(string s: myset){
        int total=0;
        for(int i=0; i<mp[s].size(); i++){
            total+= mp[s][i].first;
        }
        v.push_back({total,s});
    }
    sort(v.begin(),v.end(),compare2);
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<2; j++){
            if(mp[v[i].second].size()-1>=j)
            answer.push_back(mp[v[i].second][j].second);
        }
    }
    return answer;
}
