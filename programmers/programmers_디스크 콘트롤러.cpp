#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
int ret;
queue<pair<int,int>> q;
vector<int> v;

int solution(vector<vector<int>> jobs) {
    for(int i=0; i<jobs.size(); i++){
        v.push_back(jobs[i][0]);
        pq.push({jobs[i][1],jobs[i][0]});
    }
    sort(v.begin(),v.end());
    int c=v[0];
    while(pq.size()){
        int cnt=0;
       while(pq.size()){
        pair<int,int> f= pq.top();
        pq.pop();
        if(f.second<=c){
            c+=f.first;
            ret+=(c-f.second);
            cnt++;
            break;
        }  
          else q.push(f);
       }
        if(cnt==0) c++;
        while(q.size()){
            pair<int,int> t= q.front();
            pq.push(t);
            q.pop();
        }
    }

    int answer = ret/jobs.size();
    return answer;
}
