#include <bits/stdc++.h>
using namespace std;

int n;
//���� ���� ���� ���ؼ� ���������� �켱���� ť�� �����.  
priority_queue<int, vector<int>, greater<int>> pq;
int ret;
int a,b;
vector<pair<int, int>> v; 


int main(){
	cin>> n;
	
	for(int i=0;i <n; i++){
        cin >> a >> b; v.push_back({b, a});
	}
	
	sort(v.begin(), v.end());

 for(int i = 0; i < n; i++){ 
        pq.push(v[i].second);
        if(pq.size() > v[i].first){ 
            pq.pop();
        } 
    }	
	while(pq.size()){
    	ret += pq.top(); pq.pop();
	}
	cout<<ret; 
	return 0;
}
