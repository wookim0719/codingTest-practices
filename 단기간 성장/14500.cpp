#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[501][501];
int ret;

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if((i + 3) < n) {
                ret = max(ret, a[i][j] + a[i+1][j] + a[i+2][j] + a[i+3][j]);
            }
            if((j + 3) < m) {
                ret = max(ret, a[i][j] + a[i][j+1] + a[i][j+2] + a[i][j+3]);
            }
            if(((i + 1) < n) && ((j + 1) < m)) {
                ret = max(ret, a[i][j] + a[i][j+1] + a[i+1][j] + a[i+1][j+1]);
            }
            if(((i + 2) < n) && ((j + 1) < m)) {
                ret = max(ret, a[i][j] + a[i][j+1] + a[i+1][j] + a[i+2][j]);
                ret = max(ret, a[i][j] + a[i+1][j] + a[i+2][j] + a[i+2][j+1]);
            }
            if(((i + 2) < n) && ((j - 1) >= 0)) {
                ret = max(ret, a[i][j] + a[i][j-1] + a[i+1][j] + a[i+2][j]);
                ret = max(ret, a[i][j] + a[i+1][j] + a[i+2][j] + a[i+2][j-1]);
            }
            if(((i + 2) < n) && ((j + 1) < m)) {
                ret = max(ret, a[i][j] + a[i+1][j] + a[i+1][j+1] + a[i+2][j+1]);
            }
            if(((i + 2) < n) && ((j - 1) >= 0)) {
                ret = max(ret, a[i][j] + a[i+1][j] + a[i+1][j-1] + a[i+2][j-1]);
            }
            if(((i + 1) < n) && ((j - 1) >= 0) && ((j + 1) < m)) {
                ret = max(ret, a[i][j] + a[i][j+1] + a[i+1][j] + a[i+1][j-1]);
            }
            if(((i + 1) < n) && ((j + 2) < m)) {
                ret = max(ret, a[i][j] + a[i][j+1] + a[i+1][j+1] + a[i+1][j+2]);
                ret = max(ret,a[i][j]+a[i+1][j]+a[i+1][j+1]+a[i+1][j+2]);
            }
            if(((i + 1) < n) && ((j - 2) >= 0)) {
                ret = max(ret, a[i][j] + a[i][j-1] + a[i+1][j-1] + a[i+1][j-2]);
                ret = max(ret,a[i][j]+a[i+1][j]+a[i+1][j-1]+a[i+1][j-2]);
            }
            if(((j - 1) >= 0) && ((j + 1) < m) && ((i + 1) < n)) {
                ret = max(ret, a[i][j] + a[i][j+1] + a[i][j-1] + a[i+1][j]);
            }
            if(((j + 1) < m) && ((i + 1) < n) && ((i - 1) >= 0)) {
                ret = max(ret, a[i][j] + a[i][j+1] + a[i+1][j] + a[i-1][j]);
            }
            if(((j - 1) >= 0) && ((j + 1) < m) && ((i - 1) >= 0)) {
                ret = max(ret, a[i][j] + a[i-1][j] + a[i][j+1] + a[i][j-1]);
            }
            if(((j - 1) >= 0) && ((i - 1) >= 0) && ((i + 1) < n)) {
                ret = max(ret, a[i][j] + a[i][j-1] + a[i+1][j] + a[i-1][j]);
            }
            if((i+1)<n&&(j+2)<m){
            	ret= max(ret,a[i][j]+ a[i+1][j] + a[i+1][j+1]+ a[i+1][j+2]);
			}
			if((i+1)<n&&(j+2)<m){
            	ret= max(ret,a[i][j]+ a[i+1][j] + a[i][j+1]+ a[i][j+2]);
            	ret= max(ret,a[i][j]+a[i][j+1]+a[i][j+2]+a[i+1][j+2]);
			}
        }
        
    }	

    cout << ret;
    return 0;
}

