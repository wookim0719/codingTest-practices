#include <string>
#include <vector>
#include<bits/stdc++.h>

using namespace std;
const int INF =987654321;
pair<int,int> dp[100001];
vector<int> v;

vector<int> solution(int target) {
    for(int i=0; i<100001; i++){
        dp[i].first=INF;
        dp[i].second=0;
    }
    
    dp[50]={1,1};
    for(int i=1; i<=20; i++){
        dp[i]={1,1};
        dp[i*2]={1,0};
        dp[i*3]={1,0};
        v.push_back(i);
        v.push_back(i*2);
        v.push_back(i*3);
    }
    v.push_back(50);

    
    for(int i=0; i<v.size(); i++){
        for(int j=1; j<=100000; j++){
            if(j< v[i]) continue;
            else if(dp[j].first>dp[j-v[i]].first+dp[v[i]].first){
                dp[j].first= dp[j-v[i]].first+dp[v[i]].first;
                dp[j].second= dp[j-v[i]].second+dp[v[i]].second;
            }
            else if(dp[j].first==dp[j-v[i]].first+dp[v[i]].first){
                if(dp[j].second<dp[j-v[i]].second+dp[v[i]].second){
                    dp[j].second=dp[j-v[i]].second+dp[v[i]].second;
                }
            }
        }
    }
    vector<int> answer;
    answer.push_back(dp[target].first);
    answer.push_back(dp[target].second);
    return answer;
}
