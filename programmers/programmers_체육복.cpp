#include <string>
#include <vector>
#include<bits/stdc++.h>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    sort(lost.begin(),lost.end());
    queue<int> q1;
    map<int,int> mp;
    n= n-lost.size();
    
    for(int i=0; i<lost.size(); i++)
    q1.push(lost[i]);
    for(int j=0;j<reserve.size();j++)
    mp[reserve[j]]=1;
    
   while(q1.size()){
       int f= q1.front();
        q1.pop();
       if(mp[f]==1){
           mp[f]=0;
           n++;
       }
    else if(mp[f-1]==1){mp[f-1]=0;
       n++;}
       else if(mp[f+1]==1){
           if(q1.front()!=f+1){
           mp[f+1]=0;
           n++;}
       }
       cout<<f<<n<<"\n";
   }
    int answer = n;
    return answer;
}
