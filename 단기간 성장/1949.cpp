#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
vector<int> e[10001];
int dp[10001][2];
int visited[10001];

int go(int node, int flag){	
	int &ret= dp[node][flag];
	if(ret!=-1) return ret;
	if(flag) ret= v[node];
	else ret=0;
	for(int i=0 ;i<e[node].size(); i++){
		int next= e[node][i];
		if(!visited[next]){
			visited[next]=1;
			if(flag){
			ret = ret+go(next,0);
			}
			else{
			int ret2 = ret+go(next,1);
			int ret3= ret+go(next,0);
			ret= max(ret2,ret3);
			}
			visited[next]=0;
		}
	}
	return ret;
}

int main(){
    memset(dp, -1, sizeof(dp)); // dp 배열을 -1로 초기화	
	cin>>n;
	for(int i=0; i<n; i++){
		int temp;
		cin>>temp;
		v.push_back(temp);	
	}
	
	for(int i=0; i<n-1; i++){
		int t1,t2;
		cin>>t1>>t2;
		t1--; t2--;
		e[t1].push_back(t2);
		e[t2].push_back(t1);
	}
	visited[0]=1;
	int res1= go(0,1);
	int res2= go(0,0);
	int res= max(res1,res2);
	cout<<res;
	return 0;
}
