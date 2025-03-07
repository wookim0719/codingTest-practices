#include<bits/stdc++.h>
using namespace std;
int n,m;
int visited[10000000];
int main(){
	
	cin>>n>>m;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for(int i=0; i<m; i++){
		queue<int> q;
		int ret=0;
		int temp;
		bool flag= true;
		cin>>temp;
		q.push(temp);
		while(q.size()){
			int f= q.front();
			//cout<<f<<"\n";
			q.pop();
			if(f==0) break;
			if(visited[f]) {
				ret = f;
				q.push(f/2);
				flag= false;
			}
			else{
				q.push(f/2);
			}
		}
		if(flag){
			visited[temp]=1;
			cout<<0<<"\n";
		} 
		else{
			cout<<ret<<"\n";
		}
	}
	
	
	return 0;
}
