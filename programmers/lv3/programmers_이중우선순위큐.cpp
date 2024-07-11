#include <string>
#include <vector>
#include<bits/stdc++.h>

using namespace std;

priority_queue<int> pq;
priority_queue<int,vector<int>, greater<int>> pq2;
vector<int>v;
map<int,int> mp;
int cnt;


vector<int> solution(vector<string> operations) {
    for(int i=0;i<operations.size(); i++){
        string s= operations[i];
        if(s[0]=='D'&&cnt>0){
            if(s[2]=='-'){
              pq2.pop(); 
                cnt--;
            }
            else{
              pq.pop();
                cnt--;
            }
            if(cnt==0){
                while(!pq.empty()){
                    pq.pop();
                }
                while(!pq2.empty()){
                    pq2.pop();
                }
                cnt=0;
            }
        }
        else if(s[0]=='I'){
            int temp=0;
            if(s[2]=='-'){
               for(int i=3; i<s.size(); i++){
                  temp= (s[i]-'0')+temp*10;
              } 
                temp= -1*temp;
            }
            else{
              for(int i=2; i<s.size(); i++){
                  temp= (s[i]-'0')+temp*10;
              } 
            } 
            cout<<temp<<" ";
            pq.push(temp);
            pq2.push(temp);
            cnt++;
        }
    }
    while(pq.size()){
     v.push_back(pq.top());
      mp[pq.top()] ++;
        pq.pop();
    }
     while(pq2.size()){
     v.push_back(pq2.top());
      mp[pq2.top()] ++;
        pq2.pop();
    }
    sort(v.begin(),v.end());
    int maxx=-987654321;
    int minn=987654321;
    for(int i=0; i<v.size(); i++){
        if(mp[v[i]]>1){
            if(v[i]>maxx) maxx=v[i];
            if(v[i]<minn) minn=v[i];
        }
    }
    
    vector<int> answer;
    if(maxx==-987654321) maxx=0;
    if(minn==987654321) minn=0;
    answer.push_back(maxx);
    answer.push_back(minn);
    return answer;
}
