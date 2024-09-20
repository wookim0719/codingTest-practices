#include<bits/stdc++.h>
using namespace std;
const int INF=987654321;
int n;
int a[21][21];
int v[21][21];
vector<int> vv;
int ret =INF;
	
bool pos(int y, int x, int d1, int d2){
	bool flag=true;
	if(y+d1+d2>=n) flag= false;
	if(x-d1<0) flag=false;
	if(x+d2>=n)flag= false;	
	return flag;
}

void line5(int y,int x,int d1,int d2){
	while(true){
	if(v[y][x]) break;
	if(y<n)
	v[y][x]=5;
	if(d1>0)
	for(int i=0; i<=d1; i++){
		v[y+i][x-i]=5;
	}
	if(d2>0)
	for(int i=0; i<=d2; i++){
		v[y+i][x+i]=5;
	}
	if(d2>0&&d1>0)
	for(int i=0; i<=d2; i++){
		v[y+d1+i][x-d1+i]=5;
	}
	if(d1>0&&d2>0)
	for(int i=0; i<=d1; i++){
		v[y+d2+i][x+d2-i]=5;
	}
	if(d1>0)
	d1--;
	if(d2>0)
	d2--;
	y++;
	}
	return;
}

void lineo(int y,int x,int d1,int d2){
	for(int i=0; i<y+d1;i++){
		for(int j=0; j<=x; j++){
			if(!v[i][j]){
				v[i][j]=1;
			}
		}
	}
	for(int i=0; i<=y+d2; i++){
		for(int j=x+1; j<n; j++){
			if(!v[i][j]){
				v[i][j]=2;
			}
		}
	}
	for(int i=y+d1; i<n; i++){
		for(int j=0; j<x-d1+d2; j++){
			if(!v[i][j]){
				v[i][j]=3;
			}
		}
	}
	for(int i=y+d2; i<n; i++){
		for(int j=x-d1+d2; j<n; j++){
			if(!v[i][j]){
				v[i][j]=4;
			}
		}
	}
	return;
}

int cal(int y,int x, int d1, int d2){
	int res=0;
	memset(v,0,sizeof(v));
	vv.clear();
	line5(y,x,d1,d2);
	lineo(y,x,d1,d2);
//	cout<<y<<" "<<x<<" "<<d1<<" "<<d2<<"\n";
//		for(int i=0; i<n; i++){
//		for(int j=0; j<n; j++){
//			cout<<v[i][j];
//		}
//		cout<<"\n";
//	}
	for(int i=0; i<5; i++){
		vv.push_back(0);
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			vv[v[i][j]-1]+=a[i][j];
		}
	}
	sort(vv.begin(),vv.end());
	res= vv[4]-vv[0];
	return res;
}

void go(int n1,int n2){
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(pos(n1,n2,i,j)){
		//	cout<<cal(n1,n2,i,j)<<"\n";
			ret=min(ret,cal(n1,n2,i,j));
			}
		}
	}
	return;
}	
	
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>a[i][j];
		}
	}	
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			go(i,j);
		}
	}
//	line5(2,2,1,1);
//	lineo(2,2,1,1);
//	
//	for(int i=0; i<n; i++){
//		for(int j=0; j<n; j++){
//			cout<<v[i][j];
//		}
//		cout<<"\n";
//	}
	
	cout<<ret;
	return 0;
}
