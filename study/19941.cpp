#include<bits/stdc++.h>
using namespace std;
char arr[20001]={};
bool flag= false;
string s;
int main(){
	int n,k,ans=0;
	cin>>n>>k;
	cin>>s;
	for(int i=0;i<=n;i++){
		if(s[i] == 'P'){
			for(int g=k;g>=1;g--){
				if(i+1>=g&&s[i-g] == 'H'){
					s[i-g] = 'N';
					ans ++;
					s[i]= 'S';
					flag =true;
					break;
				}
			}
			if(!flag)
			for(int g=1; g<=k; g++){
				if(s[i+g] == 'H'){
					s[i+g] = 'N';
					ans ++;
					break;
					s[i]= 'S';
				}
			}
			flag =false;
		}
	}

	printf("%d",ans);
}
