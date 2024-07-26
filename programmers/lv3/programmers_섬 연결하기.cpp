#include <string>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
vector<pair<int,pair<int,int>>> v;
int ret;
int parents[100];

int findp(int node){
    if(parents[node]==node) return node;
    else{
    int parent = findp(parents[node]);
        return parent;
    }
}

void unionp(int now, int next){
    now= findp(now);
    next =findp(next);
    parents[next]=now;
    return;
}


int solution(int n, vector<vector<int>> costs) {
    for(int i=0; i<costs.size(); i++){
        v.push_back({costs[i][2],{costs[i][0],costs[i][1]}});
    }
    sort(v.begin(),v.end());
    for(int i=0; i<n; i++){
        parents[i]=i;
    }
    int cnt=0;
    for(int i=0; i<v.size(); i++){
        int now= v[i].second.second;
        int next= v[i].second.first;
        int cost= v[i].first;
        if(findp(now)==findp(next)) continue;
        else{
            unionp(now,next);
            ret+=cost;
            cnt++;
        }
        if(cnt==n-1) break;
    }
    
    int answer = ret;
    return answer;
}
