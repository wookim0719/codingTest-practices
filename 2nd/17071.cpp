#include <bits/stdc++.h>
using namespace std;

int n,m;
const int max_n = 500000;
int visited[2][max_n+4];
int  ok, turn=1;

int main(){
	cin>> n>> m;
	queue<int> q;
	visited[0][n] = 1;
	q.push(n);
	    if(n == m){cout << 0 << "\n"; return 0;}
	while(q.size() !=0){
		m+=  turn;
		if(m> max_n) break;
		if(visited[turn%2][m]){
			ok = true;
			break;
		}
		int qSize = q.size();
		for(int i=0; i<qSize; i++){
			int x = q.front(); q.pop();
			for(int nx : { x+1, x-1, x*2}){
				if(nx < 0 || nx> max_n|| visited[turn%2][nx]) continue;
				visited[turn%2][nx] = visited[(turn +1) % 2][x]+1;
				
				if(nx == m){
					ok =1; break;
				}
				q.push(nx);
			}
			if(ok) break;
		}
		if(ok) break;
		turn++;
	}
	if(ok) cout<< turn << "\n";
	else cout<< -1;
	
	return 0;
}
