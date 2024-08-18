#include <string>
#include <vector>
#include<bits/stdc++.h>

using namespace std;
int visited[501];

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int cnt=0;
    int cur=0;
    int ret=0;
    while(true){
        if(cnt==jobs.size()) break;
        int ii=0;
        int vv=987654321;
       for(int i=0; i<jobs.size(); i++){
           if(jobs[i][0]<=cur&& visited[i]==0){
               if(jobs[i][1]<vv) {
                   ii=i;
                   vv=jobs[i][1];
               }
           }
       }    
        if(vv!=987654321){
              visited[ii]=1;
            cur += jobs[ii][1];
            cnt++;
        ret+= cur-jobs[ii][0];
        cout<<ret<<"\n";
        }
          else{
              cur++;
          }
    } 
    
    answer= ret/jobs.size();
    return answer;
}
