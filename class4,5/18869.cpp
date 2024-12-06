#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> v[101];
vector<string> res;
int ret;

void go(int num){
	string sum;
	vector<int> temp = v[num];
	sort(temp.begin(),temp.end());
	for(int i=0; i<m; i++){
		int now = v[num][i];
		int s=0;
		int e=m-1;
		while(s<=e){
			int mid = (s+e)/2;
			if(temp[mid]==now){
				sum+=mid+'0';
				break;
			}
			else if(temp[mid]<now){
				s=mid+1;
			}
			else{
				e= mid-1;
			}
		}
	}
	res.push_back(sum);
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			int temp;
			cin>>temp;
			v[i].push_back(temp);
		}
	}
	
	for(int i=0; i<n; i++){
		go(i);
	}
	
	sort(res.begin(),res.end());
	int temp=0;
	for(int i=1; i<n; i++){
		if(res[i]==res[i-1]){
			temp++;
		}
		else{
			ret+= (temp+1)*(temp)/2;
			temp=0;
		}
	}
	if(temp){
		ret+=(temp+1)*temp/2;
	}
	cout<<ret;
	return 0;
}
