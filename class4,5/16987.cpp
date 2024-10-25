#include<bits/stdc++.h>
using namespace std;
int n;
struct egg{
	int w, d;
};
vector<egg> v;
int ret;

void go(int idx, int total){
	//cout<<idx<<" "<<total<<"\n";
	if(idx==n){
	//	cout<<total<<"\n";
		ret= max(total,ret);
//		cout<<ret<<"\n";
		return;
	}
	for(int i=0; i<n; i++){
		if(i==idx) continue;
		else{
			if(v[idx].d>0){
			if(v[i].d>0){
				int tt=	v[i].d;
				int ttt= v[idx].d;
				int cnt=0;
				v[i].d-=v[idx].w;
				v[idx].d-= v[i].w;	
				if(v[idx].d<=0) cnt++;
				if(v[i].d<=0)cnt++;
				go(idx+1,total+cnt);
				v[i].d=tt;
				v[idx].d=ttt;
			}
			else{
				go(idx+1,total);
			}
		}
		else{
			go(idx+1,total);
		}
		}
	}
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=0; i<n; i++){
		int t1,t2;
		cin>>t1>>t2;
		egg temp;
		temp.d=t1;
		temp.w=t2;
		v.push_back(temp);
	}
	
	go(0,0);
	
	cout<<ret;
	return 0;
}
