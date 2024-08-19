#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int INF=987654321;
int n, m;
int a[51][51];
int dist[51][51];
vector<pii> virus;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int res=INF;

void bfs(vector<int>& active) {
    queue<pii> q;
    vector<vector<int>> visited(n, vector<int>(n, 0));
    
    for(int i : active) {
        q.push(virus[i]);
        visited[virus[i].first][virus[i].second] = 1;
    }
    
    int time = 0;
    while(!q.empty()) {
        int size = q.size();
        for(int i=0; i<size; i++) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            
            for(int j=0; j<4; j++) {
                int ny = y + dy[j];
                int nx = x + dx[j];
                if(ny<0 || nx<0 || ny>=n || nx>=n || a[ny][nx] == 1 || visited[ny][nx]) continue;
                visited[ny][nx] = 1;
                q.push({ny, nx});
                if(a[ny][nx] == 0) dist[ny][nx] = time + 1;
            }
        }
        time++;
    }
}

void dfs(int idx, int cnt, vector<int>& active) {
    if(cnt == m) {
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                dist[i][j] = (a[i][j] == 0 ? INF : 0);
        
        bfs(active);
        
        int max_time = 0;
        bool possible = true;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(a[i][j] == 0) {
                    if(dist[i][j] == INF) {
                        possible = false;
                        break;
                    }
                    max_time = max(max_time, dist[i][j]);
                }
            }
            if(!possible) break;
        }
        
        if(possible) res = min(res, max_time);
        return;
    }
    
    for(int i=idx+1; i<virus.size(); i++) {
        active.push_back(i);
        dfs(i, cnt+1, active);
        active.pop_back();
    }
}

int main() {
    cin >> n >> m;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> a[i][j];
            if(a[i][j] == 2) virus.push_back({i, j});
        }
    }
    
    vector<int> active;
    dfs(-1, 0, active);
    
    cout << (res == INF ? -1 : res) << endl;
    
    return 0;
}
