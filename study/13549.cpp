#include<bits/stdc++.h>
using namespace std;
int n,k;
int visited[100001];
int ret=987654321;

int main(){
	cin>>n>>k;
	if(n==k){
		cout<<0;
		return 0;
	}

	queue<pair<int,int>> q;
	q.push({n,0});
	memset(visited,-1,sizeof(visited));
	visited[n]=1;
	while(!q.empty()){
		int num= q.front().first;
		int time=q.front().second;
		if(num==k) {
			ret=min(time,ret);
			break;
		}
		q.pop();
		bool flag= false;
		if(num==k) return visited[num];
		for(int next: {num*2,num-1,num+1}){
			if(0<=next && next<=100000){
				if(visited[next]==-1){
					if((next==num*2))
					q.push({next,time});
					else 
					q.push({next,time+1});
					visited[next]=1;
				}
			}
	}
}
	cout<<ret;
	return 0;
}
