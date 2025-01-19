#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int ret=9876432;
int main(){
	
	for(int i=0; i<7; i++){
		int temp;
		cin>>temp;
		if(temp%2){
			sum+=temp;
			ret = min(ret,temp);
		}
	}
	cout<<sum<<"\n"<<ret;
	return 0;
}
