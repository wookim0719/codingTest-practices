#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> L(N + 1, 0);
    vector<int> U(N + 1, 0);

    // 입력을 받아서 L과 U 배열을 채웁니다.
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (x > 0) {
            U[x]++;
        } else {
            L[-x]++;
        }
    }

    vector<int> LS(N + 1, 0);
    vector<int> US(N + 1, 0);

    // LS 배열을 채웁니다.
    for (int i = 1; i <= N; i++) {
        LS[i] = LS[i - 1] + L[i - 1];
    }

    // US 배열을 채웁니다.
    for (int i = N - 1; i >= 0; i--) {
        US[i] = US[i + 1] + U[i + 1];
    }

    vector<int> ans;

    // 정답을 찾습니다.
    for (int i = 0; i <= N; i++) {
        if (US[i] + LS[i] == i) {
            ans.push_back(i);
        }
    }

    // 결과 출력
    cout << ans.size() << endl;
    for (int i : ans) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

