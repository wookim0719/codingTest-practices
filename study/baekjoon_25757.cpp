#include<bits/stdc++.h>
using namespace std;
 int n;
 char c;
 string s;
 map<string,int> a;
 int ret;
 
 int main(){
 	
 	cin>>n>>c;
 	
 	for(int i=0; i<n; i++){
 		cin>>s;
 		if(a[s]) continue;
 		else{
 		ret++;
		a[s]++;	
		
	}
	 }

 	
 	if(c == 'Y') cout<<ret;
 	else if(c== 'F')cout<<ret/2;
 	else cout<<ret/3;
 	
 	return 0;
 }
