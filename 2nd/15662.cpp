#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int> a[1001];
vector<pair<int,int>> v;
int ret;
string s[1001];

int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>s[i];
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<8; j++){
			a[i].push_back(s[i][j]-'0');
		}
	}
		
	cin>>k;
	
	while(true){
		v.clear();
		int temp1,temp2;
		cin>>temp1>>temp2;
		temp1--; 
		int temp3=temp2;
	for(int i=temp1; i>0; i--){
		if(a[i][6]!=a[i-1][2]){
			if(temp3==-1){
			v.push_back({i-1,1});
			temp3=1;
			}
			else{
			v.push_back({i-1,-1});
			temp3=-1;
			}
		}
		else {
			break;
		}
	}
	int temp4=temp2;
	for(int i=temp1; i<n-1; i++){
		if(a[i][2]!=a[i+1][6]){
			if(temp4==-1){
			v.push_back({i+1,1});
			temp4=1;
			}
			else{
			v.push_back({i+1,-1});
			temp4=-1;
			}
		}
		else break;
	}
	for(int i=0; i<v.size(); i++){
		int index= v[i].first;
		if(v[i].second==1)
		rotate(a[index].rbegin(),a[index].rbegin()+1, a[index].rend());
		else
		rotate(a[index].begin(),a[index].begin()+1, a[index].end());
	}
	if(temp2==-1)
	rotate(a[temp1].begin(),a[temp1].begin()+1, a[temp1].end());
	else	
	rotate(a[temp1].rbegin(),a[temp1].rbegin()+1, a[temp1].rend());
		k--;
		if(k==0) break;
	}
	
	for(int i=0; i<n; i++){
		if(a[i][0]==1) ret++;
	}
	
	cout<<ret;
	
	return 0;
}
