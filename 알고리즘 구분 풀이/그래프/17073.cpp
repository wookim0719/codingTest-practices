#include<bits/stdc++.h>
using namespace std;
int n;
double start;
vector<int> v[500001];
vector<int> tree[500001];
int water[500001];
int visited[500001];
double ret;

void make_tree(int node){
//	cout<<node<<"\n";
	for(int i : v[node]){
		if(!visited[i]){
			visited[i]=1;
			tree[node].push_back(i);
			make_tree(i);
		}
	}
	return;
}

void go(int now, bool isWater){
//	cout<<now<<" "<<"\n";
	if(tree[now].size()>water[now]){
		for(int i=0; i<tree[now].size(); i++)
		go(tree[now][i],false);
	}
	else{
		for(int i=0; i<tree[now].size();i++){
		if(water[now]){
			water[tree[now][i]]+= water[now]/tree[now].size();
			water[now] = water[now]%tree[now].size();
			go(tree[now][i],true);
		}
	}	
	}
	if(isWater){
		water[now]++;
	}
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>start;
	for(int i=0; i<n-1; i++){
		int t1,t2;
		cin>>t1>>t2;
		v[t1].push_back(t2);
		v[t2].push_back(t1);
	}
	visited[1]=1;
	make_tree(1);
	//water[1] = start;

	//	go(1,false);

	double sum=0;
	int cnt= 0;
	for(int i=1; i<=n; i++){
		if(tree[i].size()==0)  cnt++;
	}
	//cout<<start<<" "<<cnt<<"\n";
	cout.precision(10);
	cout<<start/cnt;
	return 0;
}
