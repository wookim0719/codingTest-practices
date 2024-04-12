#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m,k;
ll a[1000001];
int temp1,temp2,temp3;

ll sum(int idx, vector<ll> &tree){
	ll res= 0;
	while(idx>0){
		res+= tree[idx];
		idx -= (idx & -idx);
	}
	return res;
}

void update(int idx, ll value, vector<ll> &tree){
	while(idx < tree.size()){
		tree[idx] +=value;
		idx= idx + (idx& -idx);
	}
}



int main(){
	cin>>n>>m>>k;
	vector<ll> fenwick_tree(n+1);
	
	for(int i=1; i<=n; i++){
		cin>>a[i];
		update(i,a[i],fenwick_tree);
	}
	
	for(int i=0; i<m+k; i++){
		cin>>temp1>>temp2>>temp3;
		if(temp1==1){
			long long diff= temp3 - a[temp2];
			a[temp2] = temp3;
			update(temp2,diff,fenwick_tree);
		}
		else
			cout<<sum(temp3,fenwick_tree)-sum(temp2-1,fenwick_tree)<<"\n";
		
	}
	
	return 0;
}
