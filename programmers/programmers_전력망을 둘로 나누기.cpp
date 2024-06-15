#include <string>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

pair<int,int> a[101];
vector<int> v[101];
int ret= 987654321;
int t[101];
int t2[101];


int solution(int n, vector<vector<int>> wires) {
    for(int i=0; i<n-1; i++){
        int temp1= wires[i][0];
        int temp2= wires[i][1];
        a[i]={temp1,temp2};
        v[temp1].push_back(temp2);
        v[temp2].push_back(temp1);
    }
    for(int i=0; i<n-1; i++){
        queue<int> q;
        queue<int> q2;
        q.push(a[i].first);
        q2.push(a[i].second);
        memset(t,0,sizeof(t));
        memset(t2,0,sizeof(t2));
        int cnt1=1;int cnt2=1;
        while(q.size()){
            int b= q.front();
            t[b]=1;
            q.pop();
            for(int j: v[b]){
                if(j!=a[i].second&&!t[j]){
                  q.push(j);
                    cnt1++;
                }
            }
        }
         while(q2.size()){
            int b2= q2.front();
            t2[b2]=1;
            q2.pop();
            for(int x: v[b2]){
                if(x!=a[i].first&&!t2[x]){
                     q2.push(x);
                    cnt2++;
                }
            }
        }
     
       // cout<<cnt1<<" "<<cnt2<<"\n";
        ret= min(ret,abs(cnt1-cnt2));
    }
    int answer= ret;

    return answer;
}
