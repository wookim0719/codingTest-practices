#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,m;
vector<ll> v;
ll ret= 0;

ll cal(ll num){
    ll sum=0;
    int idx=1e8;
    int ss=0;
    int ee=v.size()-1;
    while(ss<=ee){
        int mid= (ss+ee)/2;
        if(v[mid]>=num){
            idx= min(idx,mid);
            ee=mid-1;
        }
        else{
            ss=mid+1;
        } 
    }
    if(idx==1e8) idx=v.size();
    for(int i=0; i<idx; i++){
        sum+= (num-v[i])*(num-v[i]);
        if(sum>m) break;
    }
    return sum;
}


int main(int argc, char** argv)
{
    cin>>n>>m;
    for(int i=0; i<n; i++){
        ll tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    ll s= 0;
    ll e= 1e10;

    while(s<=e){
    ll mid= (s+e)/2;
    ll r= cal(mid);
   // cout<<r<<" "<<mid<<"\n";
    if(r<=m){
     //   cout<<mid<<"\n";
        ret= max(ret,mid);
        s= mid+1;
    }
    else{
        e=mid-1;
    }  
    }

    cout<<ret;
    
   return 0;
}
