#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int dp[1001]; // n의 최대값이 1000이므로 dp 배열 크기를 1001로 설정
    dp[1] = 1;    // 2×1 크기의 직사각형을 채우는 방법은 1가지
    dp[2] = 2;    // 2×2 크기의 직사각형을 채우는 방법은 2가지
    
    // 동적 프로그래밍으로 점화식을 이용해 dp 채우기
    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % 10007;  // 10007로 나눈 나머지를 계산
    }
    
    // n 크기의 직사각형을 채우는 방법의 수 출력
    cout << dp[n] << endl;
    
    return 0;
}

