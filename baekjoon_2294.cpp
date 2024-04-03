#include <bits/stdc++.h>
using namespace std;
int n,k;
const int INF = 987654321;
int a[10001];
int v[101];


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
	cin>>n>>k;
	fill(a,a+10001,INF);
	
	for(int i=0; i<n; i++){

		cin>>v[i];
	}
	
	a[0]=0;
	
	for(int i=0; i<n;i++){
		for(int j=v[i]; j<=k; j++){
			a[j] = min(a[j-v[i]]+1,a[j]);
		}
	}
	
	if(a[k]==INF) cout<<-1;
	else
	cout<<a[k];
	return 0;
}
