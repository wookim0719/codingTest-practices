#include<bits/stdc++.h>
using namespace std;
int n,m,t,tc,s,g,h;
const int INF= 987654322;
int a[2001][2001];
int dist[2001];
int flag =0;
			int temp1,temp2,temp3;


void disikjra(){
	fill(dist,dist+2001,INF);
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	dist[s] =0;
	pq.push({0,s});
	while(pq.size()){
		int here = pq.top().second;
		int here_dist= pq.top().first;
		pq.pop();
		if(dist[here] != here_dist) continue;
		for(int i=1; i<=n; i++){
			if(a[here][i]==-1) continue;
			if(dist[i]> dist[here]+a[here][i]){
				dist[i] = dist[here]+a[here][i];
				pq.push({dist[i],i});
			}		
		}
	}
}

bool check(int node){
	flag=0;
	int start =99999;
	while(start != s){
	//	cout<<start<<"\n";
	for(int i=1;i<=n; i++){
		if(dist[node] ==dist[i]+a[i][node]){
			if(((node ==h)&&(i ==g))||((node ==g)&&(i ==h))){
				//cout<<"추적";
				flag =1;
				return true;
			}
			//			cout<<node<<" "<<i<<"\n";
			start = i;
			node = i;
			break;
		}
	}
}
	return  false;
}

int main(){
		ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
	cin>>tc;
	while(tc--){
		//도로 값들 무한대로 초기화시키기 
		vector<int> v;
		v.clear();  
		memset(a,-1,sizeof(a));
		cin>>n>>m>>t;
		cin>>s>>g>>h;	
		for(int i=0;i<m;i++){
			cin>>temp1>>temp2>>temp3;
			temp3= temp3*2;
			if(temp1 == h && temp2 == g) temp3= temp3-1;
			else if(temp1 == g && temp2 == h) temp3= temp3-1;
 			a[temp1][temp2] =temp3;
			a[temp2][temp1] = temp3;
		}
	//	cout<<a[g][h]<<" "<<a[h][g]<<"\n"; 
		int candi[t + 1];
        for(int i = 0; i < t; i++){
        cin >> candi[i];
        }
        sort(candi, candi + t);

		//다익스트라를 실행하여 시작점에서 부터의 최단 거리를 모든 노드에 업데이트함  
		disikjra();
		//후보 노드에 대하여 최단거리에 g,h를 포함하는 지 확인해야함. 
		for(int i=0; i<t; i++){
			if(dist[candi[i]]%2)
			cout << candi[i]<<" ";  
		}
	cout<<"\n";
	}
	return 0;
}
