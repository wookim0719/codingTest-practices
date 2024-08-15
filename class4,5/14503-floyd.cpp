#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1001;  // �ִ� ��� ��
const int INF = 1e9;     // ���Ѵ� ��

int dist[MAX_N][MAX_N];  // �Ÿ� �迭
int n, m;                // ��� ��, ���� ��

int main() {
    cin >> n>>m;
    
    // �Ÿ� �迭 �ʱ�ȭ
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }
    
    // ���� �Է�
    for (int i = 0; i < n - 1; i++) {
        int u, v,k;
        cin >> u >> v>>k;
        dist[u][v] = dist[v][u] = k;  // Ʈ������ ��� ������ ����ġ�� 1
    }
    
    // �÷��̵�-���� �˰���
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
