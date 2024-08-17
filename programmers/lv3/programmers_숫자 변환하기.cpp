#include <string>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
int visited[1000001];
int ret=987654321;

int solution(int x, int y, int n) {
    queue<pair<int,int>> q;
    q.push({x,0});
    while(q.size()){
        auto f= q.front();
        q.pop();
        if(f.first==y){
            ret= min(ret,f.second);
            break;
        }
        if(f.first<y){
            if((f.first*2)<=y&&!visited[(f.first*2)]){
                q.push({f.first*2,f.second+1});
                visited[(f.first*2)]=1;
            }
            if((f.first*3)<=y&&!visited[(f.first*3)]) {
              q.push({f.first*3,f.second+1});
            visited[(f.first*3)]=1;
            }    
            if((f.first+n)<=y&&!visited[f.first+n]){
                 q.push({f.first+n,f.second+1});
                visited[f.first+n]=1;
            }
        }
    }
    
    int answer = ret;
    if(answer==987654321) answer=-1;
    return answer;
}
