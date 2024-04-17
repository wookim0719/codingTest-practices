#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[100001];
int ret;

int main(){
	cin>>n>>m;
	
	for(int i=0; i<m; i++)
	cin>>a[i];
	
	ret = a[0]-0;
	
	for(int i=0;i<m-1; i++){
		int temp =(a[i+1] - a[i])/2;
		if((a[i+1]-a[i])%2) temp++;
		ret = max(ret,temp);
	}
	
	ret= max(ret,(n-a[m-1]));
	
	cout<<ret;
	
	return 0;
}
