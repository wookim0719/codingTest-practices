#include<iostream>
#include<bits/stdc++.h>

using namespace std;
vector<int> v[4];
int a[4][100001];
int dp[4][100001];
int n;
int main(int argc, char** argv)
{
    cin>>n;
    for(int i=0; i<3; i++){
       for(int j=0; j<n; j++){
           int temp;
           cin>>a[i][j];
           v[i].push_back(a[i][j]);
       } 
    }
    
    for(int i=0; i<n; i++){
        int temp=0;
        for(int j=0; j<3; j++){
            temp=temp+v[j][i];
        }
        v[3].push_back(temp);
        a[3][i]=temp;
    }

       
    for(int i=0; i<4; i++){
        sort(v[i].begin(),v[i].end());
    }
   // for(int i=0; i<=3; i++){
   //      for(int j: v[i]){
   //          cout<<j<<" ";
   //      }
   //      cout<<"\n";
   //  }
    for(int j=0; j<4; j++){
    for(int i=0;i<n; i++){
        int temp = a[j][i];
        if(dp[j][temp]){
            cout<<dp[j][temp];
            if(i!=n-1) cout<<" ";
            continue;
        }
        int s=0;
        int e=n-1;
        int idx=n-1;
        while(s<=e){
            int mid=(s+e)/2;
            if(temp<v[j][mid]){
                e=mid-1;
            }
            else{
                s=mid+1;
                 if(temp==v[j][mid]){
                  //  cout<<temp<<" "<<idx<<"\n";
                   idx= mid;
                }
            }
        }
        dp[j][temp]=n-idx;
      cout<<n-idx;
            if(i!=n-1) cout<<" ";

    }
                cout<<"\n";
        }
    
   return 0;
}
