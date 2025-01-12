#include <iostream>
#include <string>
#include <istream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a, b;
    cin >> a >> b;


    ll limit = sqrt(b) + 1;
    vector<bool> is_prime(limit + 1, true);
    vector<ll> primes;

    // �����佺�׳׽��� ü�� sqrt(b)������ �Ҽ��� ����
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i <= limit; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (ll j = i * i; j <= limit; j += i) {
                is_prime[j] = false;
            }
        }
    }

    int count = 0;
    for (ll i : primes) {
        ll temp = i*i;

        while (temp <= b) {
            if (temp >= a) {
                count++;
            }
            if (temp > b /i) break; // �����÷ο� ����
            temp *= i;
        }

    }

    cout << count << '\n';

    return 0;
}
