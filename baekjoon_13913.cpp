#include <bits/stdc++.h>
using namespace std;
int n,m;
int max_n = 100004;
int visited[100004];
int prev_value[100004];
vector<int> v;


int main(){
	cin>> n>> m;
	
	queue<int> q;
	q.push(n);
	while(q.size() !=0){
		int now = q.front();
		q.pop();
		if(now == m) break;
		for(auto it : {now+1, now-1, now*2}){
			if(it>= max_n|| it<0) continue;
			if(visited[it] ==0){
				visited[it] =visited[now]+1;
				prev_value[it] = now;
				q.push(it);
			}
		}
	}
	
	for(int i = m; i!= n; i = prev_value[i]){
		v.push_back(i);
	}
	v.push_back(n);
	reverse(v.begin(),v.end());
	
	cout<< visited[m]<<"\n";

	for(auto it: v) cout<<it<<" ";
	
	return 0;	
}
