#include<bits/stdc++.h>
using namespace std;
int n;
int m;
struct room{
	int s=0;
	int num=0;
	bool possible=true;
	vector<pair<string,int>> player;
};
vector<room> v;

int main(){
	cin>>n>>m;
	for(int i=0; i<n; i++){
		int l;
		string name;
		cin>>l>>name;
		bool flag= false;
		for(room& r: v){
			if(r.possible&&l<=(r.s+10)&&l>=(r.s-10)){
				r.num++;
				if(r.num==m) r.possible=false;
				r.player.push_back({name,l});
				sort(r.player.begin(),r.player.end());
				flag= true;
				break;
			}
		}
		if(!flag){
				room temp;
				temp.s=l;
				temp.player.push_back({name,l});
				temp.num++;
				if(temp.num==m) temp.possible=false;
				v.push_back(temp);
			}
	}
	
	for(room& r: v){
		if(r.possible){
			cout<<"Waiting!"<<"\n";
		}
		else cout<<"Started!"<<"\n";
		for(auto s: r.player){
			cout<< s.second<< " "<<s.first<<"\n";
		}
	}
	
	return 0;
}
