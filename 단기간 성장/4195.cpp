#include<bits/stdc++.h>
using namespace std;
int t;
unordered_map<string,string> parent;
unordered_map<string,int> mp;

string findp(string a){
 	if(parent[a]==a) return a;
 	string b= parent[a];
// 	cout<<a<<"\n";
 	return parent[a] = findp(b);
 }
 
int gatherp(string a, string b){
	string pa= findp(a);
	string pb= findp(b);
//	cout<<pa<<" "<<pb<<"\n";
	mp[pb] += mp[pa];
	parent[pa]= pb;
 	return mp[pb];
 }

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>t;
	while(t--){
		mp.clear();
		parent.clear();
		int n;
		cin>>n;
		for(int i=0; i<n; i++){
			string t1,t2;
			cin>>t1>>t2;
			if(parent[t1]=="")parent[t1]=t1;
			if(parent[t2]=="")parent[t2]=t2;
			if(mp[t1]==0) mp[t1]=1;
			if(mp[t2]==0) mp[t2]=1;
			string p1= findp(t1);
		//	cout<<parent[t2];
			string p2= findp(t2);
			if(p1==p2){
				cout<<mp[p1]<<"\n";	
			}
			else{
				cout<<gatherp(t1,t2)<<"\n";
			}
		}
	}	
	
	return 0;
}
