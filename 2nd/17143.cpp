#include<bits/stdc++.h>
using namespace std;
int r,c,m,ret;
int a[200][200];
vector<int> v;
int big=0;
struct sk{
	int r2,c2,s,d,z;
};
vector<sk> sharks;

void kill(){
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			v.clear();
			big=0;
			if(a[i][j]>1){
				for(int s=0;s<sharks.size(); s++){
					if(sharks[s].r2==i&&sharks[s].c2==j){
						v.push_back(s);
						big=max(big,sharks[s].z);
					}
				}
			for(int k=0; k<v.size(); k++){
    			if(sharks[v[k]].z != big) {
        			sharks.erase(sharks.begin()+v[k]);
        	// 이건 지우게 된다면 v에 들어간 상어의 순서에서 1을 빼서 동기화해준다.  
        			 for(int l=k+1; l<v.size(); l++) {
            		if(v[l] > v[k]) v[l]--;
        }
    		}
		}
				a[i][j]=1;
			}
		}
	}
	return;
}


int main(){
	cin>>r>>c>>m;
	for(int i=0;i<m; i++){
		sk temp;
		cin>>temp.r2>>temp.c2>>temp.s>>temp.d>>temp.z;
		temp.r2--;
		temp.c2--;
		temp.d--;
		a[temp.r2][temp.c2]++;
		sharks.push_back(temp);
	}
	
	for(int i=0; i<c; i++){
		bool flag=false;
		for(int j=0; j<r; j++){
			//상어를 죽이고 무게를 추가해준다. 
			if(a[j][i]){
				a[j][i]=0;
				for(int s=0; s<sharks.size();s++){
					if((sharks[s].r2==j)&&(sharks[s].c2==i)){
						ret+= sharks[s].z;
						sharks.erase(sharks.begin()+s);	
					}
				}
				break;	
			}
		}
	
	//상어 이동시켜주기  
		for(int s=0; s<sharks.size(); s++){
			int dir= sharks[s].d;
			int iloc= sharks[s].r2;
			int jloc= sharks[s].c2;
			int speed= sharks[s].s;
			a[iloc][jloc]--;
			if(dir==0){
				int inii= iloc;
				iloc= iloc-speed;
				if(iloc<0) {
					int z= speed-inii;
					int tem1= z/(r-1);
					int tem2= z%(r-1);
					if(tem1%2){
						 iloc= (r-1)-tem2;
						 sharks[s].d=0;
					}
					else {
					iloc=tem2;
					sharks[s].d=1;
					}
				}
				sharks[s].r2=iloc;
				a[iloc][jloc]++;
			}
			if(dir==1){
				int inii=iloc;
				iloc= iloc+speed;
				if(iloc>r-1) {
					int z= speed-(r-1)+inii;
					int tem1= z/(r-1);
					int tem2= z%(r-1);
					if(tem1%2){
						 iloc= tem2;
						 sharks[s].d=1;
					}
					else {
					iloc=(r-1)-tem2;
					sharks[s].d=0;
					}
				}
				sharks[s].r2=iloc;
				a[iloc][jloc]++;
			}
			if(dir==2){
				int inij=jloc;
				jloc= jloc+speed;
				if(jloc>c-1) {
					int z= speed-(c-1)+inij;
					int tem1= z/(c-1);
					int tem2= z%(c-1);
					if(tem1%2){
						 jloc= tem2;
						 sharks[s].d=2;
					}
					else {
					jloc=(c-1)-tem2;
					sharks[s].d=3;
					}
				}
				sharks[s].c2=jloc;
				a[iloc][jloc]++;
			}
				if(dir==3){
				int inij= jloc;
				jloc= jloc-speed;
				if(jloc<0) {
					int z= speed-inij;
					int tem1= z/(c-1);
					int tem2= z%(c-1);
					if(tem1%2){
						 jloc= (c-1)-tem2;
						 sharks[s].d=3;
					}
					else {
					jloc=tem2;
					sharks[s].d=2;
					}
				}
				sharks[s].c2=jloc;
				a[iloc][jloc]++;
			}
		}
		kill();
	}
	cout<<ret;
	return 0;
}
