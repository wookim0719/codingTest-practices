#include <string>
#include <vector>
#include<bits/stdc++.h>

using namespace std;
int visited[10001];
vector<vector<string>> v;
vector<string> ret;

void go(string now, int cnt, vector<string> temp){
     temp.push_back(now);
    for(int i=0; i<v.size(); i++){
        if(v[i][0]==now&& !visited[i]){
            visited[i]=1;
            go(v[i][1], cnt+1,temp);
            visited[i]=0;
        }
    }
    if(cnt==v.size()){
        if(ret.size()){
            for(int i=0; i<ret.size(); i++){
                if(ret[i]>temp[i]){
                    ret= temp;
                    return;
                }
                else if(ret[i]<temp[i]){
                        return;
                }
            }
        }
        ret= temp;
    }
    return;
}

vector<string> solution(vector<vector<string>> tickets) {
    v=tickets;
    for(int i=0; i<tickets.size(); i++){
        if(tickets[i][0]== "ICN"){
             visited[i]=1;
            vector<string> tt;
            tt.push_back("ICN");
            go(tickets[i][1],1,tt);
            visited[i]=0;
        }
    }
    
    vector<string> answer =ret;
    return answer;
}
