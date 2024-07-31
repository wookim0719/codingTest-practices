#include<bits/stdc++.h>
using namespace std;

int x1,x2,x3;
int y1,y2,y3;

int main(){
	cin>>x1>>y1;
	cin>>x2>>y2;
	cin>>x3>>y3;
	
	int ret= x1*y2+x2*y3+x3*y1-(x2*y1+x3*y2+x1*y3);
	
	if(ret<0) cout<<-1;
	else if(ret==0) cout<<0;
	else cout<<1;
	
	return 0;
}
