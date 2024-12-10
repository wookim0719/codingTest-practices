#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e12;
int n;
vector<int> v;
ll ret= INF;
int a1,a2,a3;
vector<int> res;

void go(int f,int s){
	ll value = v[f]+v[s];
	int start = f+1;
	int end= s-1; 
	//		if(f==1&& s==3) cout<<1<<"\n";
	//ll sum = INF;
	while(start<=end){
		int mid = (start+end)/2;
	//	if(f==1&& s==3) cout<<mid<<"\n";
		ll sum = v[mid]+value;
		if(sum>0){
			if(abs(sum)<abs(ret)){
				a1= v[f];
				a2= v[s];
				a3= v[mid];
				ret= abs(sum);
			}
			end = mid-1;
		}
		else{
			if(abs(sum)<abs(ret)){
				a1= v[f];
				a2= v[s];
				a3= v[mid];
				ret= abs(sum);
			}
			start = mid+1;
		}
	}
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=0; i<n; i++){
		int temp;
		cin>>temp;
		v.push_back(temp);
	}
	
	sort(v.begin(),v.end());
	
	for(int i=0; i<n ;i++){
		for(int j=n-1; j>i+1; j--){
		//	cout<<i<<" "<<j<<"\n";
			go(i,j);
		}
	}
	res.push_back(a1);
	res.push_back(a2);
	res.push_back(a3);
	sort(res.begin(),res.end());
	for(int i: res){
		cout<<i<<" ";
	}
	
	return 0;
}
