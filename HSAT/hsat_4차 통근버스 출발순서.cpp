#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int n;
vector<int> v;
ll a[5001][5001];
ll ret;
int main(int argc, char** argv)
{
    cin>>n;
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    for(int i=0; i<n; i++){
        int value=0;
        for(int j=n-1; j>=i+1; j--){
            if(v[i]>v[j]){
                value++;
            }
         a[v[i]][j]=value;
        }
    }
    // for(int i=1; i<=n; i++){
    //     for(int j=0; j<n; j++){
    //         cout<<a[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(v[i]<v[j]){
                ret+=a[v[i]][j];
            }
        }
    }
    cout<<ret;
   return 0;
}
