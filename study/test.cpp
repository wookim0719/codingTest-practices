#include <bits/stdc++.h>
using namespace std;
int n,k;
int ret;


struct  medal{
	int g,s,b;
	bool operator < (const medal & a) const{
	if(g ==a.g){
		if(s== a.s) return b < a.b;
		return s<a.s;
	}
	return g< a.g;
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
		if(c<v[i]){
		//	cout<<v[i].g<<v[i].s<<v[i].b<<"\n";
			ret++;
		}
        }
		
	cout<<ret+1;
	
	return 0;
}
