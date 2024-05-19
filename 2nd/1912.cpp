#include<bits/stdc++.h>
using namespace std;
int sum;
int n;
int ret;
int big=-1001;

int main(){
	cin>>n;
	bool flag= false;
	for(int i=0; i<n; i++){
		int temp;
		cin>>temp;
		big=max(temp,big);
		if(temp+sum<0) {
			sum=0;
		}
		else{
			sum+=temp;
			ret=max(ret,sum);
			flag= true;
		}
	}
	if(!flag)
		cout<<big;
	else
	cout<<ret;
	return 0;
}
