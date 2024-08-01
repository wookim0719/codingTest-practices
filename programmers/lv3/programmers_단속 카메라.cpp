#include <string>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
int cnt;

int solution(vector<vector<int>> routes) {
    for(int i=0; i<routes.size(); i++){
        pair<int,int> temp;
        temp= {routes[i][1],routes[i][0]};
        pq.push(temp);
    }
    int i_spot=-30001;
    while(pq.size()){
        auto t= pq.top();
        pq.pop();
        if(i_spot<t.second){
            i_spot=t.first;
            cout<<i_spot<<" ";
            cnt++;
        }
    }
    
    int answer = cnt;
    return answer;
}
