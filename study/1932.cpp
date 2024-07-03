#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> v[501];
int dp[501][501];


int go(int num, int pos) {
    if (num == n) {
        return 0;
    }
    int &res = dp[num][pos];
    if (res) return res;
    for(int i=0; i<v[num].size(); i++){
    }
    res = go(num + 1, pos) + v[num][pos];   
    res = max(res, go(num + 1, pos + 1) + v[num][pos]);
    return res;
}

int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		for(int j=0; j<=i; j++){
			int temp;
			cin>>temp;
			v[i].push_back(temp);
		}
	}
	
	int ret= go(0,0);
	cout<<ret;	
	return 0;
}
