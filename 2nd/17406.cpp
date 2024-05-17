#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[101][101];
vector<int> vv;
struct b{
	int q,w,e;
};
vector<b> f;
int r[8];
int ret =987654321;

int push_top(int temp, int jj, int ii, int jjj){
	temp=a[ii][jj];
	for(int i=jj; i<jjj-1; i++){
			int temp2= a[ii][i+1];
			a[ii][i+1] = temp;
			temp= temp2; 
		}
	return temp; 
}
int push_right(int temp, int iii, int ii, int jjj){
	temp= a[ii][jjj];
	for(int i=ii; i<iii-1; i++){
		int temp2 = a[i+1][jjj];
		a[i+1][jjj] =temp;
		temp = temp2;
	}
	return temp;
}

int push_left(int temp, int iii, int ii, int jj){
	temp = a[iii][jj];
	for(int i=iii; i>ii+1; i--){
		int temp2 = a[i-1][jj];
		a[i-1][jj] =temp;
		temp = temp2;
	}
	return temp;
}

int push_bottom(int temp, int jj, int iii, int jjj){
	temp = a[iii][jjj];
		for(int i=jjj; i>jj+1; i--){	
			int temp2= a[iii][i-1];
			a[iii][i-1] = temp;
			temp= temp2; 
		}
	return temp; 
}


void roro(b temp){
	// fir, sec은 돌릴 배열의 중간점의 행과 열 인덱스  
	int fir= temp.q;
	int sec= temp.w;
	int t= temp.e;
		int ii= fir-t; 
		int jj= sec-t;
		int iii= fir+t;
		int jjj= sec+t;
	while(true){
		int tempp=a[ii][jj];
		if(ii==fir) break;
	vv.clear();
	vv.push_back(a[iii-1][jjj]);
	vv.push_back(a[iii][jj+1]);
	vv.push_back(a[ii+1][jj]);
	vv.push_back(a[ii][jjj-1]);
	tempp =push_top(tempp, jj ,ii,jjj);
	tempp=push_right(tempp,iii,ii,jjj);
	tempp=push_bottom(tempp,jj,iii,jjj);
	tempp=push_left(tempp,iii,ii,jj);
	a[ii][jj] = vv[2];
	a[ii][jjj]= vv[3];
	a[iii][jjj]= vv[0];
	a[iii][jj] = vv[1]; 
		ii++;
		jj++;
		iii--;
		jjj--;
	}
	return;
}


void go(int num){
	if(num==k) {
		for(int i=0; i<n; i++){
			int sum=0;
			for(int j=0; j<m; j++){
				sum+=a[i][j];
			}
			ret = min(ret,sum);
		}
		return;
	}
	int c[101][101];
	memcpy(c,a,sizeof(c));
	for(int i=0; i<f.size(); i++){
		if(r[i]==1)continue;
		r[i]=1;
		roro(f[i]);
		go(num+1);
		r[i]=0;
		memcpy(a,c,sizeof(a));
	}
	return;
}

int main(){
	cin>>n>>m>>k;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>a[i][j];
		}
	}
	for(int i=0; i<k; i++){
		int t1,t2,t3;
		cin>>t1>>t2>>t3;
		b temp;
		temp.q=--t1;
		temp.w=--t2;
		temp.e=t3;
		f.push_back(temp);	
	}
	go(0);
	
	cout<<ret;
	return 0;
}
