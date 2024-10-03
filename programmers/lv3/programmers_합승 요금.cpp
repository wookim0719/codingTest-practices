#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> pp;
const int INF =987654321;
int n,s,a,b;
vector<pair<int,int>> v[201];
int disto[201];
int dist[201];
int ret=INF;

void base_go(int num){
    disto[num]=0;
    priority_queue<pp,vector<pp>,greater<pp>> pq2;
    pq2.push({0,num});
    while(pq2.size()){
        auto f= pq2.top();
        int now= f.second;
        int value= f.first;
       // cout<<now<<" "<<value<<"\n";
        pq2.pop();
        for(auto next: v[now]){
         //   cout<<next.first<<" "<<next.second<<"\n";
         //cout<<disto[next.first]<<" "<<disto[now]<<" "<<next.second<<"\n";
            if(disto[next.first]>disto[now]+next.second){
                disto[next.first] = disto[now]+next.second;
             //   cout<<disto[next.first]<<"\n";
                pq2.push({disto[next.first],next.first});
            }
        }
    }
    ret= disto[a]+disto[b];
    return;
}

void go(int num){
    dist[num]=0;
    priority_queue<pp,vector<pp>,greater<pp>> pq;
    pq.push({0,num});
    
    while(pq.size()){
        auto f= pq.top();
        int now= f.second;
        int value= f.first;
        pq.pop();
        for(auto next: v[now]){
            if(dist[next.first]>dist[now]+next.second){
                dist[next.first] = dist[now]+next.second;
                pq.push({dist[next.first],next.first});
            }
        }
    }

    if(dist[a]!=INF||dist[b]!=INF)
    ret= min(disto[num]+dist[a]+dist[b],ret);
    return;
}

int solution(int nn, int ss, int aa, int bb, vector<vector<int>> fares) {
    n=nn; a=aa; b=bb; s= ss;
    
    for(int i=0; i<fares.size(); i++){
        int t1=fares[i][0];
        int t2=fares[i][1];
        int t3=fares[i][2];
        v[t1].push_back({t2,t3});
        v[t2].push_back({t1,t3});
    }
    fill(disto,disto+201,INF);
    base_go(s);
    for(int i=1; i<=n; i++){
        if(i==s) continue;
        fill(dist,dist+201,INF);
        go(i);
    }
    cout<<ret;          
    int answer = ret;
    return answer;
}
