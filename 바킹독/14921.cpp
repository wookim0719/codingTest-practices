#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
int ret=987654321;
int main(){
	cin>>n;
	
	for(int i=0; i<n; i++){
		int temp;
		cin>>temp;
		v.push_back(temp);
	}
	sort(v.begin(),v.end());
	int s=0;
	int e=v.size()-1;
	while(s<e){
		int temp= v[s]+v[e];
		//cout<<temp<<"\n";
		if(temp>=0){
			if(abs(ret)>abs(temp)){
				ret=temp;
			}
			e--;	
		}
		else{
			if(abs(ret)>abs(temp)){
				ret=temp;
			}
			s++;	
		}
	}
	
	cout<<ret;
	return 0;
}
