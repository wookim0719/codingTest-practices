#include<bits/stdc++.h>
using namespace std;

int main(){
long long S;
    cin >> S; // �� S �Է¹ޱ�

    long long N = 0; // �ڿ��� ���� N �ʱ�ȭ
    long long sum = 0; // ���� ��

    // 1���� �����ؼ� ���� S�� �ʰ����� ���� ������ ���ϱ�
    for (long long i = 1; ; i++) {
        sum += i; // ���� ���� i�� ���ϱ�
        if (sum > S) { // S�� �ʰ��ϸ� break
            break;
        }
        N = i; // i�� ���� ������ N�� �ִ�
    }
	cout<<N;
	return 0;
}
