#include <string>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

int stringToTime(string time){
    int value=0;
    value +=((time[0]-'0')*10+time[1]-'0')*60;
    value +=((time[3]-'0')*10+time[4]-'0');
    return value;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    map<string, vector<string>> mp;
    set<string> st;
    vector<int> answer;
    for (int i = 0; i < records.size(); i++) {
        string car_number = records[i].substr(6, 4);
        st.insert(car_number);
        mp[car_number].push_back(records[i].substr(0, 5));
    }
    
    for(string s: st){
        stack<string> stk;
        int total=0;
        int ttt=0;
        for(int t=0; t<mp[s].size(); t++){
            if(stk.empty()){
               if(t==mp[s].size()-1){
                   ttt+=stringToTime("23:59")- stringToTime(mp[s][t]);
                  if(ttt>0){
                      if(ttt-fees[0]>0){
                          total+= ((ttt-fees[0])/fees[2])*fees[3];
                          if((ttt-fees[0])%fees[2]) total+=fees[3];
                      }
                        total+=fees[1];
                  } 
               } 
            else stk.push(mp[s][t]);
            }
            else{
                if(t==mp[s].size()-1){
                    string before= stk.top();
                    stk.pop();
                  ttt+= stringToTime(mp[s][t])-stringToTime(before);
                  if(ttt>0){
                      if(ttt-fees[0]>0){
                          total+= ((ttt-fees[0])/fees[2])*fees[3];
                          if((ttt-fees[0])%fees[2]) total+=fees[3];
                      }
                        total+=fees[1];
                  } 
                }
                else{
                    string before= stk.top();
                    stk.pop();
                    ttt+= stringToTime(mp[s][t])-stringToTime(before);
                }
            }
        }
        answer.push_back(total);
        cout<<"\n";
    }

    return answer;
}
