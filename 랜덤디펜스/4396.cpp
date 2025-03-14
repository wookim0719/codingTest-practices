#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[11][11];
char ret[11][11];
int dy[8]={0,0,1,1,1,-1,-1,-1};
int dx[8]={-1,1,0,1,-1,0,1,-1};
int main() {
    cin>>n;
    for(int i=0; i<n; i++){
        string temp;
        cin>>temp;
        for(int j=0; j<n; j++){
            if(temp[j]=='*')
            a[i][j]= 1;
            else a[i][j] = 0;
        }
    }
    bool flag = false;
    for(int i=0; i<n; i++){
        string temp;
        cin>>temp;
        for(int j=0; j<n; j++){
            int cnt=0;
            if(temp[j] == 'x'){
                for(int k=0; k<8; k++){
                    int ny= i+dy[k];
                    int nx= j+dx[k];
                    if(ny<0||nx<0||ny>=n||nx>=n||!a[ny][nx]) continue;
                    cnt++;
                }
                if(a[i][j]==1) flag=true;
                ret[i][j] = cnt+'0';
              //  cout<<ret[i][j];
            }
            else{
               ret[i][j]='.';
            }
           // if(j==n-1) cout<<"\n";
        }
    }
    if(flag){
       for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(a[i][j]==1){
                ret[i][j]='*';
            }
        }
    }  
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<ret[i][j];
        }
        cout<<"\n";
    }  
    return 0;
}