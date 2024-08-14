#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
vector<int> a;
map<int,int> mp;
int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n;
	
	for(int i=0 ;i<n; i++){
		int temp;
		cin>>temp;
		v.push_back(temp);
		if(!mp[temp]){
			a.push_back(temp);
			mp[temp]=1;
		}
	}
	sort(a.begin(),a.end());
	for(int i=0 ;i<n; i++){
		int t=v[i];
		int s=0;
		int e=a.size()-1;
		while(s<=e){
			int m= (s+e)/2;
			//cout<<m;
			if(a[m]<t){
				s=m+1;
			}
			else if(a[m]==t){
				cout<<m<<" ";
				break;
			}
			else{
				e=m-1;	
			}
		}
	}	
	return 0;
}
