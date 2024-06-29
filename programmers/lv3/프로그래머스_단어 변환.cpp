
#include <string>
#include <vector>
#include<bits/stdc++.h>

using namespace std;
string c;
string t;
vector<string> words;
int ret=987654321;

void dfs(string temp, int cnt){
    cout<<temp<<"\n";
    if(temp==t) {ret= min(ret,cnt);
         return ;       
    }
      for(int i=0; i<words.size(); i++){
        int n=0;
        for(int j=0; j<temp.size();j++){
                if(temp[j]!=words[i][j]) n++;
            }
        if(n==1) {
        string temp2=words[i];
        words.erase(words.begin()+i);
        dfs(temp2,cnt+1);
        words.push_back(temp2);
        }
        }
    return;
}

int solution(string begin, string target, vector<string> w) {
    c= begin;
    t= target;
    words= w;
    dfs(begin,0);
    int answer = ret;
    if(answer==987654321) answer=0;
    return answer;
}

