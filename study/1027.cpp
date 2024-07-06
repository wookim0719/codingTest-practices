#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<ll> v;
vector<int> a;

int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		ll temp;
		cin>>temp;
		v.push_back(temp);
	}
	
	for(int i=0; i<v.size();i++){
		int sum=0;
		double mx=-1e9;
		double mx2=-1e9;
		for(int j=i-1; j>=0; j--){
            double lean = static_cast<double>(v[i] - v[j]) / (i - j); // 소수점까지 계산 및 저장
		if(j==i-1) {
			mx=lean;
			sum++;
		}
		else if(lean<mx){
				 mx=lean;
				 sum++;
		}
	}
		for(int k=i+1; k<n; k++){
            double lean2 = static_cast<double>(v[k] - v[i]) / (k - i); // 소수점까지 계산 및 저장
		if(k==i+1){
			mx2=lean2;
			sum++;
		}
	//	if(i==4) cout<< k<<" "<<lean2<<"\n";
		if(lean2>mx2){
			mx2=lean2;
			sum++;
		}	
		}
		a.push_back(sum);
	}
	
	sort(a.begin(),a.end());	
	cout<<a[n-1];
	return 0;
}
