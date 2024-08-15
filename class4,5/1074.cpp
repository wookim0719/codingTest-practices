#include<bits/stdc++.h>
using namespace std;
int n,r,c;
int ret;
int main(){
	cin>>n>>r>>c;
	int total=1;
	
	for(int i=0 ;i<n; i++){
		total = total*2;
	}	
	int temp= total;
	while(true){
		total/=2;
	//	cout<<total<<"\n";
		if(total==0) break;
		int r2= r/total;
		int c2= c/total;
		if(r2==0&& c2==1){
			ret+=total*total*1;
		}
		else if(r2==1&&c2==0){
			ret+=total*total*2;
		}
		else if(r2==1&&c2==1){
			ret+=total*total*3;
		}
		r= r%total;
		c= c%total;
	}
	
	cout<<ret;
	return 0;
}
