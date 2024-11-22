#include <bits/stdc++.h>
using namespace std;

string s;
string a[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
int cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;

    for (int i = 0; i < 8; i++) {
        size_t pos = 0;
        while (true) {
            pos = s.find(a[i], pos); // 패턴 검색
            if (pos == string::npos) break; // 더 이상 패턴이 없으면 종료
            cnt++; // 크로아티아 알파벳 개수 증가
            s.replace(pos, a[i].size(), "*"); // 패턴을 처리하고 대체
        }
    }

    // 남아 있는 단일 문자 개수 계산
    int value = s.size() - count(s.begin(), s.end(), '*');
    cout << cnt + value << endl; // 크로아티아 알파벳 + 나머지 단일 문자 개수 출력

    return 0;
}

