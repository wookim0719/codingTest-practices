#include<bits/stdc++.h>
using namespace std;
int t;
vector<pair<int,int>> v;
bool flag=false;
int n;
int stay,stax;
int desy,desx;
int visited[101];

bool pos(int y,int x,int ny,int nx){
	int amounty= abs(ny-y);
	int amountx= abs(nx-x);
	if((amounty+amountx)<=1000){	
		return true;
	}
	else return false;
}


void go(int y,int x){
//	cout<<y<<" "<<x<<"\n";
	if(pos(y,x,desy,desx)) {
		flag= true;
		return;
	}
	else{
	  for(int i=0; i<v.size(); i++){
	  	if(pos(y,x,v[i].first,v[i].second)&&!visited[i]){
	  		visited[i]=1;
	  		go(v[i].first,v[i].second);
		  }
	  }	
	}
	return; 
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>t;
	while(t--){
		memset(visited,0,sizeof(visited));
		v.clear();
		flag= false;
		cin>>n;
		cin>>stay>>stax;
		for(int i=0; i<n; i++){
			int t1,t2;
			cin>>t1>>t2;
			v.push_back({t1,t2});
		}
		cin>>desy>>desx;
		sort(v.begin(),v.end());
		go(stay,stax);
		if(flag) cout<<"happy"<<"\n";
		else cout<<"sad"<<"\n";
	}
	return 0;
}
