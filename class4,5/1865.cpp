#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;

bool bellman_ford(int n, int m, int w, vector<tuple<int, int, int>>& edges) {
    vector<int> dist(n + 1, INF);

    for (int i = 1; i <= n; ++i) {
        for (const auto& edge : edges) {
            int u, v, cost;
            tie(u, v, cost) = edge;

            if (dist[u] + cost < dist[v]) {
                dist[v] = dist[u] + cost;

                if (i == n) {
                    return true;  // n-th iteration���� ������ �߻��ϸ� ���� ����Ŭ ����
                }
            }
        }
    }

    return false;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, w;
        cin >> n >> m >> w;

        vector<tuple<int, int, int>> edges;

        for (int i = 0; i < m; ++i) {
            int u, v, cost;
            cin >> u >> v >> cost;
            edges.emplace_back(u, v, cost);
            edges.emplace_back(v, u, cost);  // ����� ����
        }

        for (int i = 0; i < w; ++i) {
            int u, v, cost;
            cin >> u >> v >> cost;
            edges.emplace_back(u, v, -cost);  // ��Ȧ
        }

        if (bellman_ford(n, m, w, edges)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}

