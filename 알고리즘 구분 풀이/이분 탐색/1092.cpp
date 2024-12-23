#include<bits/stdc++.h>
using namespace std;
int n;
int m;
vector<int> v;
vector<int> a;
int ret;

bool go(int num){
	int s=0;
	int e= v.size()-1;
	int temp = -1;
	while(s<=e){
		int mid = (s+e)/2;
		if(num>=v[mid]){
			temp = mid;
			s= mid+1;
		}
		else{
			e= mid-1;
		}
	}
//	cout<<num<<" "<<temp<<"\n";
	if(temp!=-1) {
		v.erase(v.begin()+temp);
		return true;
	}
	else return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=0; i<n; i++){
		int temp;
		cin>>temp;
		a.push_back(temp);
	}
	
	cin>>m;
	for(int i=0; i<m; i++){
		int temp;
		cin>>temp;
		v.push_back(temp);
	}
	
	sort(a.begin(),a.end());
	sort(v.begin(),v.end());
	
	while(true){
		int cnt=0;
		if(v.size()==0) break;
		for(int i=0; i<n; i++){
			if(go(a[i])){
				cnt++;
			}
		}
		if(cnt==0) {
			ret = -1;
			break;
		}
		ret++;
	}	
	cout<<ret;
	
	return 0;
}
