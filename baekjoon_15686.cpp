#import <bits/stdc++.h>
using namespace std;
int n,m;
int arr[51][51];
vector<pair<int,int>> chicken;
vector<pair<int,int>> house;
vector<vector<int>>chickenList;
int result = 987654321;


void combi(int start, vector<int> v){
    if(v.size() == m){
        chickenList.push_back(v);
        return;
    }
    for(int i = start + 1; i < chicken.size(); i++){
        v.push_back(i);
        combi(i, v);
        v.pop_back();
    }
    return;
}

int main(){
 cin>>n>>m;
 
 for(int i=0; i<n; i++){
 	for(int j=0; j<n; j++){
 		cin>> arr[i][j];
 		if(arr[i][j]==2)
 		chicken.push_back({i,j});
 		if(arr[i][j]==1) 
 		house.push_back({i,j});
	 }
 }
    vector<int> v;
	combi(-1,v);
	
	for(vector<int> clist: chickenList){
		int ret=0;
		for(pair<int,int> home: house){
			int _min = 987654321;
			for(int ch: clist){
				int dist = abs(home.first - chicken[ch].first) + abs(home.second - chicken[ch].second);
				_min = min(_min, dist);
			}
			ret += _min;
		}
		result = min(result,ret);
	}
 
 cout<< result<<"\n";
 return 0;
 	
}
