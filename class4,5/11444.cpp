#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
unordered_map<long long, long long> memo;
long long n;

long long fibo(long long n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    if (memo.count(n)) return memo[n];

    long long k = (n % 2 == 0) ? n / 2 : (n + 1) / 2;

    if (n % 2 == 0) { // n is even
        memo[n] = (fibo(k) * ((2 * fibo(k - 1)) % MOD + fibo(k)) % MOD) % MOD;
    } else { // n is odd
        memo[n] = (fibo(k) * fibo(k) % MOD + fibo(k - 1) * fibo(k - 1) % MOD) % MOD;
    }

    return memo[n];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    cout << fibo(n) % MOD;
    return 0;
}

