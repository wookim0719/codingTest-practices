#include<bits/stdc++.h>
using namespace std;
const int INF =987654321;
typedef pair<int,int> pp;
vector<pair<int,int>> v[50001];
int g[50001];
int su[50001];
int visited[50001];
int dist[50001];
int ret=INF;
int res=-1;

void disjk(int node){
    fill(dist,dist+50001,INF);
    priority_queue<pp,vector<pp>,greater<pp>> pq;
    pq.push({0,node});
    while(pq.size()){
        auto f= pq.top();
        pq.pop();
        int now= f.second;
        int value= f.first;
        if(g[now]){
            ret= min(ret,value);
        }
        for(auto next: v[now]){
            if(!su[next.first]){
                int vvv= max(next.second,value);
                if(dist[next.first]>vvv&&vvv<ret){
                 dist[next.first]=vvv;
                 pq.push({vvv,next.first});
                }
            }
        }
    }
}


vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    for(int i=0; i<paths.size(); i++){
        int s= paths[i][0];
        int l= paths[i][1];
        int w= paths[i][2];
        v[s].push_back({l,w});
        v[l].push_back({s,w});
    }
    sort(summits.begin(),summits.end());
    for(int i=0; i<gates.size(); i++){
        g[gates[i]]=1;
    }
    for(int i=0; i<summits.size(); i++){
        su[summits[i]]=1;
    }
    
    for(int i=0; i<summits.size(); i++){
        int before = ret;
        disjk(summits[i]);
        for(int i: gates){
            ret=min(dist[i],ret);
        }
        if(before>ret) {
            res=summits[i];
        }
    }
    vector<int> answer;
    answer.push_back(res);
    answer.push_back(ret);
    
    return answer;
};
