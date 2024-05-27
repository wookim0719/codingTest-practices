#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<pair<int, int>> a;
int dp[100001];

int go(int weight, vector<int>& v) {
    int& ret = dp[weight];
    if (ret) return ret;

    for (int i = 0; i < a.size(); i++) {
        if (weight + a[i].first <= k) {
            auto it = find(v.begin(), v.end(), i);
            if (it == v.end()) {
            v.push_back(i);
            ret = max(ret, a[i].second + go(weight + a[i].first, v));
            v.pop_back();
        }
        }
    }

    return ret;
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        a.push_back({temp1, temp2});
    }

    vector<int> v; // √ ±‚ ∫Û ∫§≈Õ
    int res = go(0, v);
    cout << res;

    return 0;
}
