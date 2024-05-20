 #include<bits/stdc++.h> 
 using namespace std;
 typedef long long ll;
 ll n,c;
 ll a[300001];
 ll hi;
 ll ret=1e18;
 
 bool check(ll mid){
 	ll num=0;
 	for(int i=0; i<c; i++){
 		num+= a[i]/mid;
 		if(a[i]%mid)num++;
	 }
	 return n>=num;
 }
 
 int main(){
 	cin>>n>>c;
 		 ll lo=1, hi=0, mid;

 	for(int i=0;i<c; i++){
 	 	cin>>a[i];
		hi=max(hi,a[i]);	
	 }
	 
	 while(lo<=hi){
	 	mid= (lo+hi)/2;
	 	if(check(mid)){
	 		ret= min(ret,mid);
	 		hi = mid-1;
		 }
		 else
		 	lo=mid+1;
	 }
	 
 		cout<<ret;
 	
 	return 0;
 }
