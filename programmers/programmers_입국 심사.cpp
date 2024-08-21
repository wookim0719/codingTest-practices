#include<bits/stdc++.h>

typedef long long ll;
using namespace std;
vector<int> j;
ll ntime;
ll ret=1e15;
long long caculate(ll value){
    ll vvv=0;
    for(int i=0; i<j.size(); i++){
        vvv+= value/j[i];
    }
    return vvv;
}

long long solution(int n, vector<int> times) {
    j=times;
    ntime=1e16;
    ll end= ntime;
    ll start=0;
    while(start<=end){
        ll mid= (end+start)/2;
        ll p= caculate(mid);
        if(p<n){
            start= mid+1;
        }
        else{
            if(p>=n){
                ret= min(ret,mid);
            }
            end= mid-1;
        }
    }
    
    long long answer = ret;
    return answer;
}
