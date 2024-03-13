#include <bits/stdc++.h>
using namespace std;

int n;
const int INF = 987654321;
int a[21][21];
int visited[21];
int k=10;
int ret = INF;
vector<int> start;
vector<int> link;

int go(vector<int>& v1, vector<int>& v2){
	pair<int,int> ret2;
	for(int i=0; i<k; i++){
		for(int j=0; j<k; j++){
			if(i==j)continue;
			ret2.first += a[v1[i]][v1[j]];
			ret2.second += a[v2[i]][v2[j]];
		}
	}
	return abs(ret2.first - ret2.second);
}

void comb(int s, vector<int> b){
	if(b.size()== k){
		vector<int> start;
		vector<int> link;
		for(int i=0; i<n; i++){
			if(visited[i])start.push_back(i);
			else link.push_back(i);
		}
		ret = min(ret, go(start,link));
		return;
	}
	for(int i= s+1; i<n; i++){
		visited[i] = 1;
		b.push_back(i);
		comb(i,b);
		visited[i]=0;
		b.pop_back();
	}
	return;
}

int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>a[i][j];
		}
	}
	k=n/2;
	vector<int> v; 
	comb(-1,v);
	cout<<ret;
	return 0;
}
