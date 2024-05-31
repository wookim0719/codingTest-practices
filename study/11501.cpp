#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n;
ll res;
vector<int> a;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--){
		a.clear();
		cin>>n;
		int max_value=0;
		int index=0;
		int last=0;
		res=0;
		for(int i=0; i<n; i++){
			int temp;
			cin>>temp;
			a.push_back(temp);
			if(temp>=max_value) {
			max_value=temp;
				index=i;	
			}	
		}
		while(true){
			max_value=0;
			for(int i= last; i<index; i++){
				res+=a[index]-a[i];
			}
			last = index+1;
			if(last==n-1||index==n-1) break;
			for(int i=index+1; i<n; i++){
				if(a[i]>=max_value) {
				max_value=a[i];
				index=i;	
			}	
			}
		}
	
		cout<<res<<"\n";
	}
	return 0;
}
