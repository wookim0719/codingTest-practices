#include <bits/stdc++.h>
using namespace std;
int a[101][101];
int n,m;
int ret;

int main(){
 	cin>>n>>m;
	 
	 for(int i=0;i<n;i++){
	 	int x1,y1,x2,y2;
	 	cin>>x1>>y1>>x2>>y2;
	 	for(int k=0; k<100; k++){
	 		for(int j=0; j<100; j++){
				if(k>=(y1-1)&&j>=(x1-1)&&k<=(y2-1)&&j<=(x2-1))
					a[k][j]++;	 			
			 }
		 }
	 }	
	 
	 for(int i=0; i<100; i++){
	 	for(int j=0; j<100; j++){
	 		if(a[i][j]>m) ret++;
		 }
	 }
	 
	 cout<<ret;
	return 0;
}
