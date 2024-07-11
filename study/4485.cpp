#include<bits/stdc++.h>
using namespace std;
int n;
int a[126][126];
int dp[126][126];
int dx[4]={1,0,0,-1};
int dy[4]={0,1,-1,0};
const int INF=987654321;
struct g{
	int v;int y;int x;
	bool operator>(const g& other) const {
        return v > other.v; // 예: v 값을 기준으로 비교
    }
};
priority_queue<g,vector<g>,greater<g>> pq;

int main(){
	int cnt=1;
	while(true){
		cin>>n;
		 for (int i = 0; i < 126; ++i) {
        fill(dp[i], dp[i] + 126, INF);
    }
		if(n==0)break;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cin>>a[i][j];
			}
		}
			dp[0][0]=a[0][0];
			g tmp;
			tmp.v=a[0][0]; tmp.y=0; tmp.x=0;
			pq.push(tmp);
			while(pq.size()){
				g temp = pq.top();
				pq.pop();
				for(int i=0; i<4; i++){
					int ny= temp.y+dy[i];
					int nx= temp.x+dx[i];
					if(ny>=n||nx>=n||ny<0||nx<0) continue;
					if(dp[ny][nx]> dp[temp.y][temp.x]+a[ny][nx]){
						dp[ny][nx] = dp[temp.y][temp.x]+a[ny][nx];
						g tmp2;
						tmp2.y=ny; tmp2.x=nx; tmp2.v=dp[ny][nx];
						pq.push(tmp2);
					}
				}
			}
		cout<<"Problem "<<cnt<<": "<<dp[n-1][n-1]<<"\n";
		cnt++;
	}
	
	return 0;
}
