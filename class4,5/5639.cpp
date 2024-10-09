#include<bits/stdc++.h>
using namespace std;
pair<int,int> a[1000001]; 
int parent[1000001];
vector<int> v;
int cnt=0;
void go(int now){
//	cout<<v[now]<<" "<<"진입"<<"\n";
//	cout<<now<<" "<<cnt-1<<"\n";
	if(now==cnt-1) {
	//	cout<<"반환";
		return; 
	}
	if(v[now+1]<v[now]){
		a[v[now]].first = v[now+1];
		parent[v[now+1]]= v[now];
		go(now+1);
	}
	else{
	//	cout<<v[now]<<" "<<v[now+1]<<"\n";
		int nn= v[now];
		while(true){
		//	cout<<nn<<"\n";
		//	cout<<nn<<"\n";
			if(parent[nn]>v[now+1]){
			//	cout<<nn<<" "<<v[now+1]<<"\n";
				int mm= nn;
				while(true){
			//		cout<<mm<<" "<<a[mm].second<<"\n";
					if(a[mm].second==0){
						a[mm].second = v[now+1];
						parent[v[now+1]] = mm;
						go(now+1);
						break;
					}
					else{
						mm= a[mm].second;
					}
				}
				break;
			}
			else{
			if(parent[nn]==0){
				int tt= nn;
				while(true){
					if(a[tt].second==0){
						a[tt].second = v[now+1];
						parent[v[now+1]] = tt;
						go(now+1);
						break;
					}
					else{
						tt= a[tt].second;
					}
				}
				break;
			}
			else
				nn= parent[nn];
			}
		}
	}
	return;
}

void gogo(int now){
//	cout<<now<<"\n";
	if(a[now].first){
//		cout<<"왼쪽"<<"\n";
	//	cout<<a[v[now]].first<<"\n";
		gogo(a[now].first);
	}
	if(a[now].second){
//				cout<<"오른쪽 "<<"\n";
	//	cout<<a[v[now]].second<<"\n";
		gogo(a[now].second);
	}
	cout<<now<<"\n";
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	while(cin >> n){
		v.push_back(n);
		cnt++;
	}	
	go(0);
	gogo(v[0]);	
//	for(int i=0; i<v.size(); i++){
//		cout<<parent[v[i]]<<"\n";
//	}
//	for(int i=0; i<v.size(); i++){
//		cout<<v[i]<<" ";
//		cout<<a[v[i]].first<<" "<<a[v[i]].second<<"\n";
//	}
	return 0;
}
