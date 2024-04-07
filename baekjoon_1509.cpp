#include<bits/stdc++.h>
using namespace std;
string s;
int n;
int a[2501][2501];
const int INF = 987654321;
int dp[2501];
int go(int here){
	if(here == n ) return 0;
	if(dp[here] != INF) return dp[here];
	int &ret = dp[here];
	// 길이가 1인 것부터 찾기 시작해서 존재하면 go에 들어간다.
	// 그리고 +1을 지속적으로 해준다. 처음에는 덩어리 이므로 1개를 추가. 
	for(int i=1; here+i<=n; i++){
		if(a[here][i]) ret= min(ret,go(here+i)+1);
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin >>s;
	n= s.size();
	for(int i=0; i<n; i++){
		a[i][1]=1;
	}
	
	for(int i=0; i<n-1; i++){
		if(s[i] == s[i+1]) a[i][2]=1;
	}
	
	for(int _size=3; _size<=s.size(); _size++){
		for(int j=0; j+_size<= n; j++){
			if(s[j] == s[j+_size-1]&& a[j+1][_size-2])
				a[j][_size] =1;
		}
	}
	
	fill(dp,dp+2501, INF);
	cout<<go(0);
	
	return 0;
}
