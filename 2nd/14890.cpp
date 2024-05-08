#include<bits/stdc++.h>
using namespace std;
int n,l;
int ret=0;
int a[102][102];
vector<int> v1[102];
vector<int> v2[102];

void check(vector<int> temp[102]){
	for(int i=0; i<n; i++){
		int cnt=1;
		int j;
		for(j=0; j<n-1; j++){
			if(temp[i][j]==temp[i][j+1]) cnt++;
			else if(temp[i][j]+1==temp[i][j+1]&& cnt>=l) cnt=1;
			else if(temp[i][j]-1==temp[i][j+1]&& cnt>=0) cnt= -l+1;
			else break;
		}
		if(j==n-1 && cnt>=0) ret++;
	}
	return;
}


int main(){
	cin>>n>>l;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>a[i][j];
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			v1[i].push_back(a[i][j]);
		}
	}
	
	for(int j=0; j<n; j++){
		for(int i=0; i<n; i++){
			v2[j].push_back(a[i][j]);
		}
	}
	check(v1);
	check(v2);
	
	cout<<ret;
	
	return 0;
}
