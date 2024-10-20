#include<bits/stdc++.h>
using namespace std;
int r,c;
char a[21][21];
vector<string> v;

void go_left(int n1,int n2){
	string s="";
	if(n2==0){
		while(true){
			if(a[n1][n2]=='#'||n2>=c) break;
			s+=a[n1][n2];
			n2++;
		}
	}
	else{
		if(a[n1][n2-1]=='#'){
			while(true){
				if(a[n1][n2]=='#'||n2>=c) break;
				s+=a[n1][n2];
				n2++;
			}
		}
	}
	if(s.size()>1){
	//	cout<<s;
		v.push_back(s);
	}
	return;
}
void go_down(int n1,int n2){
	string s="";
	//cout<<n1<<" "<<n2<<"\n";
	if(n1==0){
		while(true){
			if(a[n1][n2]=='#'||n1>=r) break;
			s+=a[n1][n2];
			n1++;
		}
	}
	else{
		if(a[n1-1][n2]=='#'){
			while(true){
				if(a[n1][n2]=='#'||n1>=r) break;
				s+=a[n1][n2];
				n1++;
			}
		}
	}
	if(s.size()>1){
	//	cout<<s;
		v.push_back(s);
	}
	return;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>r>>c;
	for(int i=0; i<r; i++){
		string t1;
		cin>>t1;
		for(int j=0; j<c; j++){
			a[i][j]=t1[j];
		}
	}
	
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
		//	cout<<a[i][j]<<"\n";
			if(a[i][j]!='#'){
				go_left(i,j);
				go_down(i,j);
			}
		}
	}
	sort(v.begin(),v.end());
	cout<<v[0];

	return 0;
}
