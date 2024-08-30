#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int visited[100001];
int visited2[100001];
int visited3[100001];
int visited4[100001];

vector<int> v[100001];
vector<int> rv[100001];
int n,m;
int s,e;
int ret;
bool flag1=false;
bool flag2=false;

int main(int argc, char** argv)
{
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int t1,t2;
        cin>>t1>>t2;
        v[t1].push_back(t2);
        rv[t2].push_back(t1);
    }
    cin>>s>>e;
    visited[s]=1;
    visited2[e]=1;
    visited3[e]=1;
    visited4[s]=1;
    queue<int> q;
    q.push(e);
    while(q.size()){
        int f= q.front();
        q.pop();
        for(int i:rv[f]){
            if(!visited3[i]) {
                visited3[i]=1;
                q.push(i);}
        }
    }
    q.push(s);
    while(q.size()){
        int f= q.front();
        q.pop();
        for(int i:v[f]){
            if(i==e)flag2=true;
            if(!visited[i]&&i!=e) {
                visited[i]=1;
                q.push(i);}
        }
    }

    queue<int> q2;
    q2.push(e);
    while(q2.size()){
        int f= q2.front();
        q2.pop();
        for(int i:v[f]){
            if(i==s)flag1=true;
            if(!visited2[i]&&i!=s) {
                visited2[i]=1;
                q2.push(i);}
        }
    }
    q2.push(s);
    while(q2.size()){
        int f= q2.front();
        q2.pop();
        for(int i:rv[f]){
            if(!visited4[i]) {
                visited4[i]=1;
                q2.push(i);}
        }
    }
    if(flag1&&flag2)
    for(int i=1; i<=n; i++){
        if(visited[i]&&visited2[i]&&visited3[i]&&visited4[i]) {
           // cout<<i<<" ";           
            ret++;}
    }
    else ret=0;
    cout<<ret;
   return 0;
}
