#include <bits/stdc++.h>
using namespace std;
string p,a;
int ret;
vector<int> v;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>p>>a;
    for(int i=0; i<p.size(); i++){
        int temp = (a[i]-'A'+1)-(p[i]-'A'+1);
        if(temp>26) temp -=26;
        if(temp<=0) temp+=26;
     v.push_back(temp);
    }

    for(int i=1; i<=v.size(); i++){
        bool flag = true;
        if(v.size()%i==0){
            for(int j=0; j<v.size(); j++){
                if(v[j%i] != v[j]){
                    flag= false;
                    break;
                }
            }
            if(flag) {
                ret= i;
                break;
            }
        }
    }
    for(int i=0; i<ret; i++){
        cout<<char(v[i]+'A'-1);
    }
    return 0;
}