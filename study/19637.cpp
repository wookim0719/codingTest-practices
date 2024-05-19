#include<bits/stdc++.h>
using namespace std;
int n,m;
string s[100001];
int r[100001];
map<int,int> mp;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	
	for(int i=0; i<n; i++){
		cin>>s[i]>>r[i];
	}

	
	for(int i=0; i<m; i++){
		int temp;
		cin>>temp;
		int start= 0;
		int end=n;
		int point=0;
		if(temp<=r[0])cout<<s[0]<<"\n";
		else if(temp>r[n-1]) cout<<s[n-1]<<"\n";
		else{
		while(true){
			 point = (start+end)/2;
			if(temp<=r[point]&&temp>r[point-1])
			break;
			if(temp<r[point]){
				end=point;
			}
			else{
				start =point;
			}
		}
		cout<<s[point]<<"\n";
		}
	}

	
	return 0;
}
