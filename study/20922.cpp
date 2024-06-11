#include <bits/stdc++.h>
using namespace std;

int n, k;
deque<int> dq;
int a[100001];
int ret;

int main() {
    cin >> n >> k;
    int len = 0;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if (a[temp] < k) {
            dq.push_front(temp);
            a[temp]++;
            len++;
        } else if (a[temp] == k) {
            ret = max(ret, len);
            while (!dq.empty()) { // Ensure dq is not empty
                int last = dq.back();
                dq.pop_back();
                len--;
                a[last]--;
                if (last == temp) {
                    break;    
                }
            }
            dq.push_front(temp);
            len++;
            a[temp]++;
        }
    }
    
    ret = max(len, ret);
    cout << ret;
    return 0;
}

