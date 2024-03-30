#include <bits/stdc++.h>
using namespace std;
int n,k;
int ret;


struct  medal{
	int g,s,b;
	bool operator < (const medal & a) const{
	if(g ==a.g){
		if(s== a.s) return b > a.b;
		return s>a.s;
	}
	return g> a.g;
	}
};
vector<medal> v;
medal c;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin.tie(NULL);
	
	cin>>n>>k;
	for(int i=0; i<n; i++){
		int temp;
		medal h;
		cin>>temp>>h.g>>h.s>>h.b;
		if(temp ==k ) {
			c= h; 
		};
		v.push_back(h);
	}
	for(int i=0; i<n; i++){
		if(v[i].g>c.g) ret++;
		if(v[i].g==c.g&& v[i].s>c.s)ret++;
		if(v[i].g==c.g&& v[i].s==c.s&&v[i].b>c.b)ret++;}
		
	cout<<ret+1;
	
	return 0;
}
