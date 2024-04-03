
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
	
	a[0]=1;
	for(int i=0; i<n; i++){
		cin>>v[i];
		if(v[i]>10001) continue;
		for(int j=v[i]; j<=k; j++){
			a[j] += a[j-v[i]];
		}
	}
	
	cout<<a[k];
	return 0;
}
