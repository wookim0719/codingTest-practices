#include<bits/stdc++.h>
using namespace std;
int n;
char a[101][101];
int ret;
int res;

void check_row(int num){
	int tmp=0;
	for(int i=0; i<n; i++){
		if(a[num][i]=='.') {
			tmp++;
			if(tmp==2) {
				ret++;
		}
	}
		else{
			tmp=0;
		}
}
	return;
}

void check_col(int num){
	int tmp=0;
	for(int i=0; i<n; i++){
		if(a[i][num]=='.') {
			tmp++;
			if(tmp==2) {
				res++;
		}
	}
		else{
			tmp=0;
		}
	}
	return;
}

int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>a[i][j];
		}
	}
	for(int i=0; i<n; i++){
	check_row(i);
	check_col(i);	
	}
	cout<<ret<<" "<<res;
	return 0;
}
