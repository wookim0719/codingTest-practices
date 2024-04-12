#include <bits/stdc++.h>
using namespace std;
int n,m,t;
int tree[200004];
map<int,int> mp;
int temp;

void update(int idx, int value){
	while(idx<=200004){
		tree[idx] += value;
		idx += idx&-idx;
	}
}

int sum(int idx){
	int ret = 0;
	while(idx>0){
		ret += tree[idx];
		idx -= (idx&-idx);
	}
	return ret;
}

int main(){
	cin>>t;

	while(t--){
		memset(tree,0,sizeof(tree));
		mp.clear();
		cin>>n>>m;
		int update_idx=100001;
		for(int i=1; i<=n; i++){
			update(i+update_idx, 1);
			mp[i] = i+ update_idx;
		}
		for(int i=0; i<m; i++){
			cin>>temp;
			int idx = mp[temp];
			cout<<sum(idx)-1<<" ";
			update(idx,-1);
			update(--update_idx, 1);
			mp[temp] = update_idx;
			}
			cout<<"\n";
	}

	return 0;
}
