#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
vector<int> v[3];
int ret1,ret2,ret3;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int a[5]= {1,2,3,4,5};
    int b[8]= {2,1,2,3,2,4,2,5};
    int c[10]= {3,3,1,1,2,2,4,4,5,5};
    for(int i=0; i<10000; i++){
        v[0].push_back(a[i%5]);
    }
    for(int i=0; i<10000; i++){
        v[1].push_back(b[i%8]);
    }
    for(int i=0; i<10000; i++){
        v[2].push_back(c[i%10]);
    }
    for(int i=0; i<answers.size(); i++){
       for(int j=0; j<3; j++){
           if(answers[i]==v[j][i]){
               if(j==0)ret1++;
               else if(j==1)ret2++;
               else if(j==2) ret3++;
           }
       }
    }
    vector<pair<int,int>>vv;
    cout<<ret1<<ret2<<ret3;
    vv.push_back({ret1,1});
    vv.push_back({ret2,2});
    vv.push_back({ret3,3});
    sort(vv.begin(),vv.end());
    int maxx=vv[2].first;
    for(int i=2; i>=0; i--){
        if(maxx<=vv[i].first) answer.push_back(vv[i].second);
    }
    sort(answer.begin(),answer.end());
    return answer;
}
