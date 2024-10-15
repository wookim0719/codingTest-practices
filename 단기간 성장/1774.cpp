#include<bits/stdc++.h>
using namespace std;
typedef pair<double,int> tt;
const double INF =1e12;
int n,m;
int v[1001][1001];
pair<int,int> a[1001];
double ret = INF;
int visited[1001];


double gocal(int num1, int num2){
	double diff = pow(a[num1].first-a[num2].first,2);
	double diff2= pow(a[num1].second-a[num2].second,2);
	double total  = sqrt(diff+diff2);
	return total;
}

void go(int num){
	memset(visited,0,sizeof(visited));
	priority_queue<tt,vector<tt>,greater<tt>> pq;
	pq.push({0,num});
	double res=0;
	while(pq.size()){
		auto f= pq.top();
		pq.pop();
		if(visited[f.second]) continue;
		else{
		visited[f.second]=1;
		res+= f.first;
		bool flag= true;
		for(int i=1; i<=n; i++){
			if(!visited[i]){
				flag= false;
				break;
			}
		}
		if(flag) break;	
	for(int i=1; i<=n; i++){
		if(visited[i]) continue;
		else{
			if(v[f.second][i]){
				pq.push({0,i});
			}
			double gap = gocal(f.second,i);
			pq.push({gap,i});
		}
	}
	}
	}
//	cout<<res<<"\n";
	ret= min(res,ret);
	return;
}

int main(){
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		int t1,t2;
		cin>>t1>>t2;
		a[i]={t1,t2};
	}
	for(int i=0; i<m; i++){
		int t1,t2;
		cin>>t1>>t2;
		v[t1][t2]=1;
		v[t2][t1]=1;
	}
		
	go(1);
	
	ret= round(ret*100.0)/100.0;
	cout <<fixed <<setprecision(2);

	cout<<ret;
	
	return 0;
}
