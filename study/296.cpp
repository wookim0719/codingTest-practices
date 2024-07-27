#include<bits/stdc++.h>
using namespace std;
int n;
int a[3];
int dp[2][3];
int dp2[2][3];
int ret = 0;
int ret2 = INT_MAX;

int main() {
    cin >> n;

    for (int j = 0; j < 3; j++) {
        cin >> a[j];
        dp[0][j] = a[j];
        dp2[0][j] = a[j];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a[j];
        }

        dp[1][0] = a[0] + max(dp[0][0], dp[0][1]);
        dp[1][1] = a[1] + max({dp[0][0], dp[0][1], dp[0][2]});
        dp[1][2] = a[2] + max(dp[0][1], dp[0][2]);

        dp2[1][0] = a[0] + min(dp2[0][0], dp2[0][1]);
        dp2[1][1] = a[1] + min({dp2[0][0], dp2[0][1], dp2[0][2]});
        dp2[1][2] = a[2] + min(dp2[0][1], dp2[0][2]);

        for (int j = 0; j < 3; j++) {
            dp[0][j] = dp[1][j];
            dp2[0][j] = dp2[1][j];
        }
    }

    for (int i = 0; i < 3; i++) {
        ret = max(ret, dp[0][i]);
        ret2 = min(ret2, dp2[0][i]);
    }

    cout << ret << " " << ret2;
    return 0;
}

