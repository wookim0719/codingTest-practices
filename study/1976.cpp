#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[201][201];
vector<int> v;
bool visited[201];

bool bfs(int start, int end) {
    fill(visited, visited + n, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        
        if (curr == end) {
            return true;
        }
        
        for (int i = 0; i < n; i++) {
            if (a[curr][i] && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    
    for (int i = 0; i < m; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp - 1);
    }
    
    bool ret = true;
    for (int i = 0; i < m - 1; i++) {
        if (!bfs(v[i], v[i + 1])) {
            ret = false;
            break;
        }
    }
    
    cout << (ret ? "YES" : "NO") << '\n';
    return 0;
}

