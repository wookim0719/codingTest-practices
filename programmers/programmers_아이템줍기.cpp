#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int a[101][101];
int impo[101][101];
int dy[4] = {0,1, 0, -1};
int dx[4] = {1, 0, -1, 0};
int gx, gy;
int ret = 987654321;
int visited[101][101];

void impossible(vector<int> arr) {
    for (int i = arr[1]*2 + 1; i < arr[3]*2; i++) {
        for (int j = arr[0]*2 + 1; j < arr[2]*2; j++) {
            impo[i][j] = 1;
        }
    }
    return;
}

void possible(vector<int> arr) {
    for (int i = arr[0]*2; i <= arr[2]*2; i++) {
        a[arr[1]*2][i] = 1;
        a[arr[3]*2][i] = 1;
    }
    for (int i = arr[1]*2; i <= arr[3]*2; i++) {
        a[i][arr[0]*2] = 1;
        a[i][arr[2]*2] = 1;
    }
}

void go(int y, int x, int cnt) {
    if (y == gy && x == gx) {
        ret = min(ret, cnt);
        return;
    }
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= 101 || nx >= 101 || !a[ny][nx] || impo[ny][nx] || visited[ny][nx]) continue;
        visited[ny][nx] = 1;
       // cout<<ny<<" "<<nx<<" "<<cnt+1<<" "<<y<<" "<<x<<" "<<i<<"\n";
        go(ny, nx, cnt + 1);
        visited[ny][nx] = 0;
    }
    return;
}

int solution(vector<vector<int>> rectangle, int x, int y, int ggx, int ggy) {
    memset(a, 0, sizeof(a));
    memset(impo, 0, sizeof(impo));
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < rectangle.size(); i++) {
        possible(rectangle[i]);
        impossible(rectangle[i]);
    }
    y*=2;
    x*=2;
    gy = ggy*2;
    gx = ggx*2;
    visited[y][x] = 1;
    go(y, x, 0);
 
    // 한 칸일 경우 선분위에 있지 않아도 가능한 점에 있으면 불가능한 이동도 가능해진다.
    int answer = ret/2;
    return answer;
}

