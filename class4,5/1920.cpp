#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
unordered_map<int,int> mp;
int main(){
	ios::sync_with_stdio(false); // C++ ǥ�� ����°� C ǥ�� ������� ����ȭ ��Ȱ��ȭ
    cin.tie(nullptr);  
    cout.tie(nullptr);
	cin>>n;
	
	for(int i=0; i<n; i++){
		int temp;
		cin>>temp;
		mp[temp]=1;
	}
	
	int m;
	cin>>m;
	
	for(int i=0; i<m; i++){
		int temp2;
		cin>>temp2;
		if(mp[temp2]) cout<<1<<"\n";
		else cout<<0<<"\n";
	}
	
	
	return 0;
}
