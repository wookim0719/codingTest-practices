#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v[1000001];
int dp[1000001][2];
bool visited[1000001];

void make_tree(int start) {
    visited[start] = true;
    for (int child : v[start]) {
        if (!visited[child]) {
            make_tree(child);
            dp[start][0] += dp[child][1];  // 루트가 얼리 어답터가 아닐 때
            dp[start][1] += min(dp[child][0], dp[child][1]);  // 루트가 얼리 어답터일 때
        }
    }
    dp[start][1]++;  // 자신을 얼리 어답터로 선택
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        v[t1].push_back(t2);
        v[t2].push_back(t1);
    }
    
    memset(dp, 0, sizeof(dp));
    make_tree(1);  // 루트 노드부터 트리 구성 및 DP 계산
    
    cout << min(dp[1][0], dp[1][1]) << "\n";  // 루트가 얼리 어답터인 경우와 아닌 경우의 최소값 출력
    return 0;
}

