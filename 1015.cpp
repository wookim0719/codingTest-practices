#include<bits/stdc++.h>
using namespace std;
int n;
vector<pair<int,int>> v;
map<int,int> mp;

int main(){
    cin>>n;
    for(int i=0;i<n; i++){
        int temp;
        cin>>temp;
        v.push_back({temp,i});
    }
    sort(v.begin(),v.end());
    for(int i=0; i<n; i++){
        mp[v[i].second] = i;
    }
    
    for(int i=0; i<n; i++){
        cout<<mp[i]<<" ";
    }
   
    return 0;
}