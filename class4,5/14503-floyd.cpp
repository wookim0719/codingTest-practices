#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1001;  // 최대 노드 수
const int INF = 1e9;     // 무한대 값

int dist[MAX_N][MAX_N];  // 거리 배열
int n, m;                // 노드 수, 쿼리 수

int main() {
    cin >> n>>m;
    
    // 거리 배열 초기화
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }
    
    // 간선 입력
    for (int i = 0; i < n - 1; i++) {
        int u, v,k;
        cin >> u >> v>>k;
        dist[u][v] = dist[v][u] = k;  // 트리에서 모든 간선의 가중치는 1
    }
    
    // 플로이드-워셜 알고리즘
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        cout << dist[u][v] << "\n";
    }
    
    return 0;
}
