#include <bits/stdc++.h>
using namespace std;
int n;
struct stage{
	int s,i,p;
};

vector<stage> a;
bool visited[1001];
int dp[1001][1001];

int rpg(int STR, int INT){
	int &ret = dp[STR][INT];
	if(ret != -1) return ret;
	
	ret = 0;
	int pnt = 0;
	vector<int> v;
	for(int i=0; i<n; i++){
		 if(a[i].s <= STR || a[i].i <= INT){
            ret++;
            if(!visited[i]){
                visited[i] = true;
                pnt += a[i].p;
                v.push_back(i);
            }
        }
	}
	
	for(int p=0; p<=pnt; p++){
		int nextSTR = min(1000, STR+p);
		int nextINT = min(1000, INT+pnt-p);
		ret = max(ret,rpg(nextSTR,nextINT));
	}
	for(int here: v)
		visited[here] = false;
	
	return ret;
	
}


int main(){
	cin>>n;	
	for(int i=0; i<n; i++){
		stage stage1;
		cin>>stage1.s>>stage1.i>>stage1.p;
		a.push_back(stage1);
	}
	memset(dp,-1, sizeof(dp));
	cout<<rpg(1,1);
	
	return 0;
}
