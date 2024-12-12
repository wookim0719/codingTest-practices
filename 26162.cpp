#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
int isPrime[400];

void make_num(){
	isPrime[1]=1;
	isPrime[2]=0;
	
	for(int i=2; i*i<=200; i++){
		if(!isPrime[i]){
		for(int j=i*i; j<=200; j+=i){
			isPrime[j] = 1;
		}
		}
	}
	return;
}

int main(){
	cin>>n;
	
	for(int i=0; i<n; i++){
		int temp;
		cin>>temp;
		v.push_back(temp);
	}
	
	make_num();
	
	for(int i=0; i<v.size(); i++){
		int num = v[i];
		bool flag= false;
		for(int i=1; i<num; i++){
			if(!isPrime[i]){
				if(!isPrime[num-i]){
					flag =  true;
					break;
				}
			}
		}
		if(flag) cout<<"Yes"<<"\n";
		else cout<<"No"<<"\n";
	}
	
	return 0;
}
