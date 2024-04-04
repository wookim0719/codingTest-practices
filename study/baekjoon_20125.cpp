#include <bits/stdc++.h>
using namespace std;
int n;
int a[1001][1001];
vector<pair<int,int>> v;
pair<int,int> heart;
int la,ra,h,ll,rl;


int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			char temp;
				cin>>temp;
				if(temp == '_') a[i][j]=0;
				else{
					a[i][j]=1;
					v.push_back({i,j});
				} 
		}
	}
	sort(v.begin(),v.end());
	heart.first = v[0].first+1;
	heart.second = v[0].second;
	

	for(auto i : v){
		if(heart.first==i.first&&i.second<heart.second)
			la++;
		else if(heart.first == i.first&& i.second>heart.second)
			ra++;
		else if(heart.first<i.first&& heart.second==i.second)
			h++;
		else if(heart.first<i.first&& heart.second>i.second)
			ll++;
		else if(heart.first<i.first&& heart.second<i.second)
		rl++;
	}
	cout<<heart.first+1<<" "<<heart.second+1<<"\n";
	cout<<la<<" "<<ra<<" "<<h<<" "<<ll<<" "<<rl;	
	
	return 0;
}
