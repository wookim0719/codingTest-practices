#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
int ret;
int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		int temp;
		cin>>temp;
		v.push_back(temp);
	}	
	sort(v.begin(),v.end());
	
	for(int i=0; i<n; i++){
		int s= 0;
		int e= n-1;
		if(i==s) s++;
		if(i==e) e--;
		while(s<e){
		if(v[e]+v[s]==v[i]) {
			ret++;
		//	cout<<v[i];
			break;
		}
		else if(v[e]+v[s]>v[i]){
			e=e-1;
			if(i==e) e--;

		}
		else if(v[e]+v[s]<v[i]){
			s=s+1;
			if(i==s) s++;
		}	
		}
	}
	cout<<ret;
	
	return 0;
}
