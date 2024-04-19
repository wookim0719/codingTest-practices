#include <bits/stdc++.h>
using namespace std; 
const int INF = 987654321; 
int n, a[104], b[104], dp[104][10][10][10][2];
int _mod(int x){
    return (x < 0) ? x + 10 : x % 10; 
}
int f(int pos, int x, int y, int z, int flag){
    if(pos == n) return 0; 
    int &ret = dp[pos][x][y][z][flag]; 
    if(ret != -1) return ret; 
    // 돌렸을 때 비밀번호와 특정 위치가 같은 경우엔 pos에 1을 더해서 다음을 재귀하도록 한다. 시계, 반시계 정해주기 
    if(_mod(x + a[pos]) == _mod(b[pos])) return ret = min(f(pos + 1, y, z, 0, 0), f(pos + 1, y, z, 0, 1)); 
    ret = INF; 
    int _flag = flag ? 1 : -1; 
    for(int i = 1; i <= 3; i++){
        ret = min(ret, 1 + f(pos, _mod(x + i * _flag), y, z, flag));
        ret = min(ret, 1 + f(pos, _mod(x + i * _flag), _mod(y + i * _flag), z, flag));
        ret = min(ret, 1 + f(pos, _mod(x + i * _flag), _mod(y + i * _flag), _mod(z + i * _flag), flag)); 
    }
    return ret; 
}
int main(){
    memset(dp, -1, sizeof(dp)); 
    scanf("%d", &n);
    for (int i = 0; i < n; i++)scanf("%1d", &a[i]);
    for (int i = 0; i < n; i++)scanf("%1d", &b[i]);
    printf("%d\n", min(f(0, 0, 0, 0, 0), f(0, 0, 0, 0, 1))); 
}

