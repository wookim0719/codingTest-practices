#include <bits/stdc++.h>
using namespace std; 
#define MAX_N 16
const int INF = 987654321;
// 1<<MAX_N�� ������ ������ 16������ �迭�� �ʿ������� ��Ʈ����ŷ���� 
// ǥ���Ͽ� �湮�ߴ����� ��Ÿ���� �� 
int n, dp[MAX_N][1<<MAX_N], dist[MAX_N][MAX_N];

int tsp(int here, int visited){
	// visited�� 1�� 15���� ��쿡 ��� �湮�Ѱ��̹Ƿ� Ż���Ѵ�.  
	if(visited == (1<<n)-1){
	// �ٽ� ó������ ���� ����� 0�� ��쿡�� INF�ƴϸ� �� ���� ��ȯ���ش�. 
		return dist[here][0] ? dist[here][0] : INF;
	}
	int &ret = dp[here][visited];
	//���� �����ϸ� ���� ��ȯ�Ѵ�. 
	if(ret != -1)return ret;
	ret = INF;
	for(int i=0; i<n; i++){
		//�湮�� ���̸� continue�� �Ѿ��. 
		if(visited & (1<<i))continue;
		// ���� ����� 0�̸� continue�� �Ѿ��. 
		if(dist[here][i]==0) continue;
		// tsp���� 2��° ���ڿ��� visited�� �湮�� ���� or�� �ؼ�
		//�湮�� ���� ǥ���Ѵ�. 
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
