#include <bits/stdc++.h>
using namespace std;
const int MAX = 100000;;
long long cnt[MAX+4];
int visited[MAX+4];
int n,m;

int main(){
	cin>>n>>m;
	if(n==m){
	cout<<"0"<<"\n"<<"1";
	return 0;
}	
	visited[n] =1;
	cnt[n] =1;
	
	queue<int> q;
	q.push(n);
	
	while(!q.empty()){
		int now = q.front();
		q.pop();
		for (int next: {now-1,now+1,now*2}){
			if(0<= next && next<= MAX){
				if(!visited[next]){
					q.push(next);
					visited[next] = visited[now] + 1;
					cnt[next] += cnt[now];
				}
				else if(visited[next] == visited[now] + 1){
					cnt[next] += cnt[now];
				}
			}
		}
	}
	cout << visited[m] - 1 << '\n';
    cout << cnt[m] << '\n';
    return 0;
}
