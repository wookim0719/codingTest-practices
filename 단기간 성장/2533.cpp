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
            dp[start][0] += dp[child][1];  // ��Ʈ�� �� ����Ͱ� �ƴ� ��
            dp[start][1] += min(dp[child][0], dp[child][1]);  // ��Ʈ�� �� ������� ��
        }
    }
    dp[start][1]++;  // �ڽ��� �� ����ͷ� ����
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
    make_tree(1);  // ��Ʈ ������ Ʈ�� ���� �� DP ���
    
    cout << min(dp[1][0], dp[1][1]) << "\n";  // ��Ʈ�� �� ������� ���� �ƴ� ����� �ּҰ� ���
    return 0;
}

