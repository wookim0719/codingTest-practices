
#include<bits/stdc++.h>
using namespace std;
int n;
vector<pair<int,int>> a;
stack<pair<int,int>> s;
stack<pair<int,int>> s2;
int ret;
int cnt[100001];
int num[100001];

int main(){
	fill(num,num+100001,987654321);
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin>>n;
	for(int i=0; i<n; i++){
		int temp;
		cin>>temp;
		a.push_back({temp,i});
	}
	int index=0;
	
	while(true){
	int value= a[index].first;
	int value2= a[n-1-index].first;
	if(index==n) break;
	if(!s.empty()){
		while(s.size()){
			if(s.top().first<=value){
				s.pop();
			}
			else {
			if(abs(num[index]-index)>=abs(s.top().second-index))
				num[index]=s.top().second;
				break;
		}
	}
}
	if(!s2.empty()){
		while(s2.size()){
			if(s2.top().first<=value2){
				s2.pop();
			}
			else{
		if(abs(num[n-index-1]-n+index+1)>abs(s2.top().second-n+index+1))
			num[n-index-1]=s2.top().second;
			break;	
			} 
		}
	}
	
	cnt[index]+=s.size();	
	cnt[n-index-1]+=s2.size();
	s.push(a[index]);
	s2.push(a[n-index-1]);	
	index++;
	}
	for(int i=0; i<n; i++){
	if(num[i]!=987654321)
	cout<<cnt[i]<<" "<<num[i]+1<<"\n";
	else cout<<cnt[i]<<"\n";
	}
	return 0;
}
