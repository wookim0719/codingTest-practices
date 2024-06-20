#include <string>
#include <vector>
#include<bits/stdc++.h>

using namespace std;
set<string> typ;
map<string,int> mp;
int res =1;

int solution(vector<vector<string>> clothes) {
    for(int i=0; i<clothes.size(); i++){
        typ.insert(clothes[i][1]);
        mp[clothes[i][1]]++;
    }
    for(auto it: typ){
      res = res * (mp[it]+1);
    }
    
    return res-1;
}
