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
            pos = s.find(a[i], pos); // ���� �˻�
            if (pos == string::npos) break; // �� �̻� ������ ������ ����
            cnt++; // ũ�ξ�Ƽ�� ���ĺ� ���� ����
            s.replace(pos, a[i].size(), "*"); // ������ ó���ϰ� ��ü
        }
    }

    // ���� �ִ� ���� ���� ���� ���
    int value = s.size() - count(s.begin(), s.end(), '*');
    cout << cnt + value << endl; // ũ�ξ�Ƽ�� ���ĺ� + ������ ���� ���� ���� ���

    return 0;
}

