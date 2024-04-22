#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k;

void update(vector<ll> &v, int x, ll value){
    int i = x; 
    while(i < v.size()){
        v[i] += value; 
        i += (i & -i);  
    } 
    return;
}

ll sum(vector<ll> &v, int x){
	ll sum=0;
	int i= x;
	while(i>0){
		sum +=v[i];
		i -= (i&-i);
	}
	return sum;
}

int main(){
	cin>>n>>m>>k;
	vector<ll> a(n+1);
	vector<ll> b(n+1);
	for(int i=1; i<=n; i++){
		cin>>b[i];
		update(a, i,b[i]);
	}
	for(int i=0; i<(m+k); i++){
		ll c,d,f;
		cin>>c>>d>>f;
		if(c==1){
			ll dif = f - b[d];
			b[d] = f;
			update(a,d,dif);	
		}
		else{
			ll k = sum(a,f)-sum(a,d-1);
			cout<< k<<"\n";
		}
	}
	
	
	return 0;
}
