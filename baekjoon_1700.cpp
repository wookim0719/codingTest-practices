#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[101];
int visited[101];
int cnt;
vector<int> v;
const int INF = 987654321;

int main(){
	cin>>n>>k;
	
	for(int i=0; i<k; i++){
		cin>>a[i];
	}
	for(int i=0; i<k; i++){
		if(!visited[a[i]]){
			if(v.size() == n){
				int last_idx= 0, pos;
				for(int _a :v){
					int here_pick = INF;
					for(int j= i+1; j<k; j++){
						if(_a == a[j]){
							here_pick = j;
							break;
						}
					}
					if(last_idx<here_pick){
						last_idx = here_pick;
						pos=_a;
					}
				}
					visited[pos] = 0;
					cnt++;
					v.erase(find(v.begin(), v.end(),pos));
				}
			
			v.push_back(a[i]);
			visited[a[i]]=1;
		}
		}
	
	
	cout<<cnt;
	
	
	return 0;
}
