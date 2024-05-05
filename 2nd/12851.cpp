#include<bits/stdc++.h>
using namespace std;
int n,k;
int ret;
queue<int> q;
int visited[100001];
int cnt[100001];

int main(){
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	cin>>n>>k;
	
	if(n==k){
	cout<<"0"<<"\n"<<"1";
	return 0;
}	
	visited[n] =1;
	cnt[n] =1;
	q.push(n);
	while(!q.empty()){
	int num =q.front();
	q.pop();
	for(int next: {num-1,num+1,num*2}){
		if(0<=next && next<=100000){
			if(!visited[next]){
				q.push(next);
				visited[next] = visited[num]+1;
				cnt[next] = cnt[num];
			}
			else if(visited[num]+1 == visited[next]){
				cnt[next] += cnt[num];
			}
		}
	}
		
	}
	
	cout<<visited[k]-1<<"\n";
	cout<<cnt[k]<<"\n";

	return 0;
}
