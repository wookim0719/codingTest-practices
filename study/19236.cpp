#include<bits/stdc++.h>
using namespace std;
int dy[8]={-1,-1,0,1,1,1,0,-1};
int dx[8]={0,-1,-1,-1,0,1,1,1};
int dir; 
int y,x;
int ret;
map<int, pair<int,int>> loc;
struct fish{
	int num;
	int d;
};
fish nofish;
int v[4][4]; 
fish a[4][4];

void show_fish(){
//	for(int i=0; i<4; i++){
//		for(int j=0; j<4; j++){
//			cout<<v[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
		for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			cout<<a[i][j].num<<" ";
		}
		cout<<"\n";
	}
	return ;
}

void gofish(){
	for(int i=1; i<=16; i++){
	//	cout<<i<<" "<<loc[i].first<<"\n";
		if(loc[i].first!=-1){
			int yy= loc[i].first;
			int xx= loc[i].second;
			fish temp = a[yy][xx];
			int d= temp.d;
			int od=d;
			int ny,nx;
			int tn=0;
			while(true){
				if(tn==8) break;
				ny= yy+dy[d];
				nx= xx+dx[d];
				if(ny<0||nx<0||ny>=4||nx>=4||(ny==y&&nx==x)){
					d= (d+1)%8;
					tn++;	
				}	
				else break;
			} 
			if(tn!=8){
			//�̵��� ���⿡ ����Ⱑ �����ϴ� �� Ȯ���Ѵ�. 
			if(a[ny][nx].d!=-1){
			fish temp2 = a[ny][nx];
			loc[temp2.num]={yy,xx};
			a[yy][xx]=temp2;	
			}
			else{
				a[yy][xx]=nofish;
			}
			// ��ġ �� ���� ����ü���� �ٲ��ֱ� 
			temp.d=d;
			//map�� �� ������Ʈ �����ֱ�  
			loc[i]={ny,nx};
			// ���� �̵������ֱ�
			 a[ny][nx]=temp;
			}
		//cout<<y<<" "<<x<<"\n";
	//	show_fish(); 
	//	cout<<"\n";
		}
	} 
	return;
}

void backfish(){
		for(int i=16; i>=1; i--){
		if(loc[i].first!=-1){
			int yy= loc[i].first;
			int xx= loc[i].second;
			fish temp = a[yy][xx];
			int d= temp.d;
			int tn=0;
			int od=d;
			int ny,nx;
			while(true){
				if(tn==8) break;
				ny= yy-dy[d];
				nx= xx-dx[d];
				if(ny<0||nx<0||ny>=4||nx>=4||(ny==y&&nx==x)){
					d= (d-1);
					if(d<0) d+=8;
					tn++;	
				}	
				else break;
			}
			if(tn!=8){
			if(a[ny][nx].d!=-1){
			fish temp2 = a[ny][nx];
			loc[temp2.num]={yy,xx};
			a[yy][xx]=temp2;	
			}
			else{
				a[ny][nx]=nofish;
			}
			// ��ġ �� ���� ����ü���� �ٲ��ֱ� 
			temp.d=d;
			//map�� �� ������Ʈ �����ֱ�  
			loc[i]={ny,nx};
			// ���� �̵������ֱ�
			 a[ny][nx]=temp;
			}
		}
	} 
	return;
}



void go(int sum){
  //  cout<<y<<" "<<x<<"\n";
 //   cout<<"����"<<dir<<"\n"; 
  //  cout<<"�հ�"<<sum<<"\n";
    ret= max(ret,sum);
 //   show_fish();
 //   cout<<"\n";
    //����� �̵�
  //  cout<<"�����̵�"<<"\n";
    gofish(); 
  //  show_fish();
 //   cout<<"\n";
    //�̵� ������ ��ġ�� ���ؼ� �̵��� ��Ų��. �׸��� go�� ȣ���Ѵ�. 
    int cnt=0;
    for(int i=1; i<=3; i++){
        int ny= y+dy[dir]*i;
        int nx= x+dx[dir]*i;
        if(ny<0||nx<0||ny>=4||nx>=4||a[ny][nx].num==-1)continue;
        else{
            cnt++;
            int od= dir;
            int ox= x;
            int oy= y;
            fish killed= a[ny][nx];
            loc[killed.num]={-1,-1};
            dir = killed.d;
            a[ny][nx]=nofish;
            y= ny; x=nx;
            go(sum+killed.num);
            y= oy; x=ox;
            a[ny][nx]=killed;
            dir = od;
            loc[killed.num]={ny,nx};
        }
    }
   //if(cnt==0) return; 
    //��Ʈ��ŷ (����� ����ġ�̵�)  
    backfish(); 
  // // cout<<"\n";
    return;
}



int main(){
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			int t1,t2;
			cin>>t1>>t2;
			t2--;
			fish temp;
			temp.num=t1;
			temp.d=t2;
			a[i][j]=temp;
			loc[t1]= {i,j};
		}
	}
	int ss= a[0][0].num;
	nofish.d=-1; nofish.num=-1;
	//ù ��° ĭ�� ����� �Ա� , ���� ����
	dir= a[0][0].d; 
	loc[a[0][0].num]={-1,-1}; 
	a[0][0]=nofish;
	// map���� ���� ����⿡ ���Ͽ� ��ġ�� -1,-1�� �������ش�. 	
	
//	gofish();
//	for(int i=0; i<4; i++){
//		for(int j=0; j<4; j++){
//			cout<<a[i][j].num<<" ";
//		}
//		cout<<"\n";
//	}
//	ret=a[0][0].num;
//	go(a[0][0].num);

//	backfish();
//	for(int i=0; i<4; i++){
//		for(int j=0; j<4; j++){
//			cout<<a[i][j].num<<" ";
//		}
//		cout<<"\n";
//	}
	go(ss);
	cout<<ret;	
	return 0;
}
