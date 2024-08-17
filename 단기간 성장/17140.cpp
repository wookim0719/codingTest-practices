#include<bits/stdc++.h>
using namespace std;
int r,c,t;
int a[101][101];
int b[101][101];
int r_len;
int c_len;
int ret;

void cal_r(){
	int mx=0;
	memset(b,0,sizeof(b));
	for(int i=0; i<r_len; i++){
		map<int,int> mp;
		set<int> numbers;
		vector<pair<int,int>> v;
		for(int j=0; j<c_len; j++){
			int temp= a[i][j];
			if(temp==0) continue;
			numbers.insert(temp);
			mp[temp]++;		
		}
		for(int h: numbers){
			v.push_back({mp[h],h});
		}
		int leng= v.size()*2;
		mx= max(mx,leng);
		sort(v.begin(), v.end());
		for(int l=0; l<v.size(); l++){
		//	if(2*l>=100) break;
			b[i][2*l]= v[l].second;
		//	if(2*l+1>=100) break;
			b[i][2*l+1]=v[l].first;
		}
	}
	memcpy(a,b,sizeof(a)); 
//		if(mx>=100) mx=100;
	c_len = mx;
	return;
}

void cal_c(){
	memset(b,0,sizeof(b));
	int mx=0;
	for(int i=0; i<c_len; i++){
		map<int,int> mp;
		set<int> numbers;
		vector<pair<int,int>> v;
		for(int j=0; j<r_len; j++){
			int temp= a[j][i];
			if(temp==0) continue;
			numbers.insert(temp);
			mp[temp]++;		
		}
		for(int h: numbers){
			v.push_back({mp[h],h});
		}
		int leng= v.size()*2;
		mx= max(mx,leng);
		sort(v.begin(), v.end());
		for(int l=0; l<v.size(); l++){
	//		if(2*l>=100) break;
			b[2*l][i]= v[l].second;
	//		if(2*l+1>=100) break;
			b[2*l+1][i]=v[l].first;
		}
	}
	memcpy(a,b,sizeof(a)); 
//	if(mx>=100) mx=100;
	r_len = mx;
	return;
}

int main(){
	cin>>r>>c>>t;
	r--; c--;
	for(int i=0; i<3; i++){
		for(int j=0 ;j<3; j++){
			cin>>a[i][j];
		}
	}	
	r_len= 3;
	c_len= 3;
	
	while(true){
	//	cout<<r_len<<" "<<c_len<<"\n";
		if(a[r][c]==t||ret>100){
			break;
		}
		else{
			if(r_len>=c_len){
				cal_r();
			}
			else{
				cal_c();
			}	
		}
		ret++;
//			for(int i=0; i<r_len; i++){
//		for(int j=0; j<c_len; j++){
//			cout<<a[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
//	cout<<"\n";
	}
	if(ret>100) cout<<-1;
	else
	cout<<ret;
	
	return 0;
}
