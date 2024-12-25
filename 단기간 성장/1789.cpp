#include<bits/stdc++.h>
using namespace std;

int main(){
long long S;
    cin >> S; // 합 S 입력받기

    long long N = 0; // 자연수 개수 N 초기화
    long long sum = 0; // 현재 합

    // 1부터 시작해서 합이 S를 초과하지 않을 때까지 더하기
    for (long long i = 1; ; i++) {
        sum += i; // 현재 숫자 i를 더하기
        if (sum > S) { // S를 초과하면 break
            break;
        }
        N = i; // i는 현재 가능한 N의 최댓값
    }
	cout<<N;
	return 0;
}
