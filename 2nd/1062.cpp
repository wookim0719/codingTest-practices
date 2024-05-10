#include<bits/stdc++.h>
using namespace std;
int n, k,ret;
int a[51];
int nk[7]= {0,2,8,13,19};
vector<int> v;
int tete;
string s;
int nu=0;

void go(){
	 v.clear();
	for(int i=0;i<n; i++){
		for(int j=0; j<26; j++){
			if(j!=0&&j!=2&&j!=8&&j!=13&&j!=19){
				if(a[i]&(1<<j)) {
					auto it = find(v.begin(),v.end(),j);
					if(it== v.end()) v.push_back(j);
			}
		}
	}
}
	//temp에서  k-5개를 고른다.
	 for(int i=0; i<(1<<(v.size())); i++){
	 	int op=0;
	 	//cout<<tete<<"\n";
	 	int cnt=0;
	 	for(int j=0; j<(v.size()); j++){
	 		if(i&(1<<j)){
	 		//	cout<<v[j];
	 		if(v[j]!=0&&v[j]!=2&&v[j]!=8&&v[j]!=13&&v[j]!=19){
	 			cnt++;
	 			op |= (1<<v[j]);
	 		}
			 }
		 }
		 //만약에 a,t,n중에 중간에 같은 값이 있는 경우 수가 잘못세어짐. 
		 if(cnt<=k-5){
		 	//cout<<true<<" "<<cnt<<"\n";
		 	for(int l=0; l<5; l++){
		 		op |= (1<<nk[l]);
			 }
			 nu=0;
		 	for(int g=0; g<n; g++){
		 		if((op&a[g])==a[g]) {
		 			nu++;
				 }
			 }
		 }
		 ret = max(nu, ret);
	 }
	return;
}



int main(){
	cin>>n>>k;
	if(k<5) {
		cout<<0;
		return 0;
	}

	for(int i=0; i<n;i++){
		cin>>s;
		for(char str: s){
			a[i] |= (1<< (str - 'a'));	
		}
	}
	
	go();
	
	cout<<ret;
	return 0;
}
