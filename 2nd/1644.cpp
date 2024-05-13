#include<bits/stdc++.h>
using namespace std;
int n;
bool che[4000001];
vector<int> a;
int res;

void era(int mx_n){
for(int i = 2; i <= mx_n; i++){
if(che[i]) continue;
for(int j = 2*i; j <= mx_n; j += i){
che[j] = 1;
}}
for(int i = 2; i <= mx_n; i++) if(che[i] == 0)a.push_back(i);
return ;
}

void check(){
	for(int i=0; i<a.size(); i++){
		int sum=0;
		//cout<<a[i];
		for(int j=i; j<a.size(); j++){
		//	cout<<sum<<" ";
			sum+=a[j];
			if(sum==n){
				sum=0;
				res++; break;
		}
			else if(sum>n){
				sum=0;
				break;
			}
	}
}
return;
}


int main(){
	cin>>n;
	era(n);
	check();
	cout<<res;
	
	return 0;
}
