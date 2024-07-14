#include <string>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
vector<int> e[20001];
int dist[20001];
priority_queue<int, vector<int>, greater<int>> pq;

int solution(int n, vector<vector<int>> edge) {
    fill(dist,dist+20001,987654321);
    for(int i=0; i<edge.size(); i++){
        for(int j=0; j<edge[i].size(); j++){
            e[edge[i][0]].push_back(edge[i][1]);
            e[edge[i][1]].push_back(edge[i][0]);
        }
    }
    pq.push(1);
    dist[1]=0;
    while(pq.size()){
        int now= pq.top();
        pq.pop();
        for(int next : e[now]){
            if(dist[next]> dist[now]+1){
                dist[next] = dist[now]+1;
                pq.push(next);
            }
        }
    }
    int value= 0;
    int answer = 0;
    for(int i=1; i<=n; i++){
        if(dist[i]>value) {
            value= dist[i];
            answer=1;
        }
        else if(dist[i]==value){
            answer++;
        }
    }
    
    return answer;
}
