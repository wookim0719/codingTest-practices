#include <bits/stdc++.h>
using namespace std;
int n, m;
int dp[5000001];
vector<bool> isPrime(5000001, true);

void sieve(int limit) {
    isPrime[0] = isPrime[1] = false; 
    for (int i = 2; i * i <= limit; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= limit; j += i) {
                isPrime[j] = false; 
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;

    sieve(n); 

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + (isPrime[i] ? 1 : 0); 
    }

    while (m--) {
        int a, b;
        cin >> a >> b;
        cout << dp[b] - dp[a-1] << "\n";
    }

    return 0;
}

