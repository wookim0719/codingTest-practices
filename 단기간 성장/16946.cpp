#include<bits/stdc++.h>
using namespace std;
int n,m;
int dy[4]={-1,0,1,0};
int dx[4]={0,-1,0,1};
int a[1001][1001];
set<pair<int,int>> st;
int visited[1001][1001];
int dp[1001][1001];
int cnt;
int snum=1;

void bfs(int startY, int startX) {
    queue<pair<int, int>> q;
    q.push({startY, startX});
    visited[startY][startX] =snum;
    cnt = 1;

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx] || a[ny][nx]) continue;
            visited[ny][nx] = snum;
            q.push({ny, nx});
            st.insert({ny, nx});
            cnt++;
        }
    }
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < m; j++) {
            a[i][j] = row[j] - '0';
        }
    }
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(a[i][j]==0&&dp[i][j]==0){
			visited[i][j]=snum;
				cnt=1;
				bfs(i,j);
			dp[i][j]=cnt;
			for(auto g: st){
				dp[g.first][g.second]=cnt;
			}
			st.clear();	
			snum++;
			}	
		}
	}
	for(int i=0; i<n;i++){
		for(int j=0; j<m; j++){
			if(a[i][j]){
				map<int,int> mp;
				for(int t=0; t<4; t++){
					int ny=i+dy[t];
					int nx=j+dx[t];
					if(ny>=0&&nx>=0&&ny<n&&nx<m&&a[ny][nx]==0&&!mp[visited[ny][nx]]){
						mp[visited[ny][nx]]=1;
						dp[i][j]+=dp[ny][nx];
					}
				}
				dp[i][j]=(dp[i][j]+1);
			}
		}
		}
	
	
	for(int i=0; i<n;i++){
		for(int j=0; j<m; j++){
		if(a[i][j]==0) cout<<0;
		else	
			cout<<dp[i][j]%10;
		}
		cout<<"\n";
			}	
	
	return 0;
}
