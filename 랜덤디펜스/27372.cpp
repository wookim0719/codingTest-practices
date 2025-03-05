#include <bits/stdc++.h>
using namespace std;
int t;
string s;
char a[3][3];
int visited[3][3];
int dy[6] = {-1,0,1,0,1,-1};
int dx[6] = {0,1,0,-1,1,1};
int flag[8];

bool checkPoint(int y, int x, int d, int num){
    if(visited[y][x]==0) return false;
    for(int i=0; i<2; i++){
        y += dy[d];
        x += dx[d];
        if(visited[y][x]==0) return false;
    }
    flag[num]=1;
    return true;
}

int check(){
    int temp = 0;
    if(!flag[0]){
        if(checkPoint(0,0,1,0)){
            temp++;
        }       
    }
    if(!flag[1]){
        if(checkPoint(1,0,1,1)){
            temp++;
        }       
    }
    if(!flag[2]){
        if(checkPoint(2,0,1,2)){
            temp++;
        }       
    }
    if(!flag[3]){
        if(checkPoint(0,0,2,3)){
            temp++;
        }       
    }
    if(!flag[4]){
        if(checkPoint(0,1,2,4)){
            temp++;
        }       
    }
    if(!flag[5]){
        if(checkPoint(0,2,2,5)){
            temp++;
        }       
    }
     if(!flag[6]){
        if(checkPoint(0,0,4,6)){
            temp++;
        }       
    }
    if(!flag[7]){
        if(checkPoint(2,0,5,7)){
            temp++;
        }       
    }
     return temp;   
}
string getValue(){
    string tt;
     for(int i=0; i<s.size(); i++){
            for(int j=0; j<3; j++){
                for(int h=0; h<3; h++){
                    if(a[j][h]==s[i]){
                        visited[j][h]=1;
                        break;
                    }
                }
            }
             tt+=(check()+'0');   
        }   
    return tt;
}

int main() {
    cin>>t;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(t--){
        string tt;
        memset(visited,0,sizeof(visited));
        memset(flag,0,sizeof(flag));
        cin>>s;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                cin>>a[i][j];
            }
        }
      string ans = getValue(); 
      sort(s.begin(),s.end());
        cout<<ans<<" ";
      do {
        memset(visited,0,sizeof(visited));
        memset(flag,0,sizeof(flag));
        if(ans == getValue()){
            cout<<s<<"\n";
            break;
        }
    } while (next_permutation(s.begin(), s.end())); // 다음 순열 생성
        
    }
    
    return 0;
}