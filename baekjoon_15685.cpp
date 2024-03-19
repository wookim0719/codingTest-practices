#include <bits/stdc++.h>
using namespace std;
int k;
int a[101][101];
int dy[4] = {0,-1,0,1};
int dx[4] = {1,0,-1,0};
int cnt;

struct dragon{
	int x,y,d,g;
};
dragon dra[21];

int main(){
	cin>>k;
	
	for(int i=0; i<k; i++){
		cin>>dra[i].x>>dra[i].y>>dra[i].d>>dra[i].g;
	}
	
	for(int i=0; i<k; i++){
		dragon temp = dra[i];
		stack<int> stk;
		stk.push(temp.d);
		int kkk = temp.d;
		vector<int> j;
		j.push_back(temp.d);
		a[temp.y][temp.x]=1;
		int xx = temp.x;
		int yy = temp.y;
		a[yy+dy[kkk]][xx+dx[kkk]]=1;
		for(int q=0; q<temp.g; q++){
			while(stk.size()){
				int val = stk.top(); 
				stk.pop();	
				if(val==3) j.push_back(0);
				else if(val==1) j.push_back(2);
				else if(val==2) j.push_back(3);
				else j.push_back(1);
			}
			for(int p: j){
				stk.push(p);
			}
			if(q==temp.g-1){
				for(auto c : j){
					xx = xx+dx[c];
					yy = yy+dy[c];
					a[yy][xx]=1;
				}	
			}
		}	
		
	}
	
for(int i = 0; i <= 100; i++){
        for(int j = 0; j <= 100; j++){
            if(a[i][j] && a[i + 1][j] && a[i + 1][j + 1] && a[i][j + 1])cnt++;
        }
    }
	
	cout<<cnt;	
	return 0;
}
