#include<bits/stdc++.h>
using namespace std;
int n;
int num;
vector<pair<int,int>> v;

int main(){
	cin>>n;
	while(n--){
		cin>>num;
		vector<int> a;
		int value =0;
		//�Ź� ���ο� ����� ���� �� �տ� �� ���� �ڽź��� ū �� ���� �����ָ� ��
		//�׸��� Ű ������ ������ ���ش�. 
		for(int i=0; i<20; i++){
			int b;
			cin>> b;
			for(int t: a){
				if(t>b) value++;
			}
			a.push_back(b);	
		}		
		sort(a.begin(), a.end());
		v.push_back({num, value});
	} 	
	
	for(auto i: v){
		cout<<i.first<<" "<<i.second<<"\n";
	}
	return 0;
}
