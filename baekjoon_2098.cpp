#include <bits/stdc++.h>
using namespace std; 
#define MAX_N 16
const int INF = 987654321;
// 1<<MAX_N인 이유는 원래는 16차원의 배열이 필요하지만 비트마스킹으로 
// 표시하여 방문했는지를 나타나게 함 
int n, dp[MAX_N][1<<MAX_N], dist[MAX_N][MAX_N];

int tsp(int here, int visited){
	// visited가 1이 15개인 경우에 모두 방문한것이므로 탈출한다.  
	if(visited == (1<<n)-1){
	// 다시 처음으로 가는 비용이 0인 경우에는 INF아니면 그 값을 반환해준다. 
		return dist[here][0] ? dist[here][0] : INF;
	}
	int &ret = dp[here][visited];
	//값이 존재하면 값을 반환한다. 
	if(ret != -1)return ret;
	ret = INF;
	for(int i=0; i<n; i++){
		//방문한 곳이면 continue로 넘어간다. 
		if(visited & (1<<i))continue;
		// 가는 비용이 0이면 continue로 넘어간다. 
		if(dist[here][i]==0) continue;
		// tsp안의 2번째 인자에는 visited와 방문한 값과 or을 해서
		//방문한 것을 표현한다. 
		ret = min(ret, tsp(i,visited | (1<<i)) + dist[here][i]);
	} 
	return ret;
	
}

int main(){
	ios_base::sync_with_stdio(fasle);
	cin.tie(NULL);
	cin.tile(NULL);
	
	cin>>n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++)
			cin>>dist[i][j];
	}
	memset(dp,-1, sizeof(dp));
	
	cout<<tsp(0,1);
	return 0;
}
