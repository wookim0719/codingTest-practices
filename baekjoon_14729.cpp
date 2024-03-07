#include <bits/stdc++.h>
using namespace std;

int n;
vector<double> a;
double temp;

int main(){
	cin>>n;	
	priority_queue<double> pq;
	
	for(int i=0; i<n; i++){
		cin>>temp;
		if(pq.size() == 7){
			pq.push(temp);
			pq.pop();
		}
		else pq.push(temp);
	}
	
	while(pq.size()){
		a.push_back(pq.top());
		pq.pop();
	}
	
	reverse(a.begin(), a.end());
	
	for(double i: a)
printf("%.3lf\n", i); 	
	return 0;
	
}
