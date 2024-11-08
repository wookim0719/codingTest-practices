#include <string>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v;
int ret=1;

int solution(vector<vector<int>> routes) {
    for(int i=0; i<routes.size(); i++){
        v.push_back({routes[i][0],routes[i][1]});
    }
    sort(v.begin(),v.end());
    int answer = 0;
    int f=v[0].first; int e = v[0].second;
    
    for(int i=1; i<v.size(); i++){
          if(v[i].first<=e){
              e = min(v[i].second,e);
          }
          else{
              ret++;
              f=v[i].first;
              e= v[i].second;
          }
    }
    
    return ret;
}
