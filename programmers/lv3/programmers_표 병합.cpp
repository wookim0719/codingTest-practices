#include <bits/stdc++.h>
using namespace std;
vector<string> v;
string a[51][51];
pair<int,int> p[51][51];

void merge(int r,int c,int r2,int c2){
    if(a[r][c]!=""){
        p[r2][c2]= {r,c};
        a[r2][c2]="";
    for(int i=1; i<=50; i++){
        for(int j=1; j<=50; j++){
            auto temp = p[i][j];
            if(temp.first==r2&&temp.second==c2){
                a[i][j]="";
                p[i][j]={r,c};
            }
        }
    }
    }
    else if(a[r2][c2]!=""){
        p[r][c]= {r2,c2};
        a[r][c]="";
        for(int i=1; i<=50; i++){
         for(int j=1; j<=50; j++){
            auto temp = p[i][j];
            if(temp.first==r&&temp.second==c){
                a[i][j]="";
                p[i][j]={r2,c2};
            }
        }
    }
    }
    else{
        p[r2][c2]={r,c};
    for(int i=1; i<=50; i++){
        for(int j=1; j<=50; j++){
            auto temp = p[i][j];
            if(temp.first==r2&&temp.second==c2){
                a[i][j]="";
                p[i][j]={r,c};
            }
        }
    }
    }
}

void unmerge(int r, int c){
    a[r][c]="";
    for(int i=1; i<=50; i++){
        for(int j=1; j<=50; j++){
            auto temp = p[i][j];
            if(temp.first==r&&temp.second==c){
                a[i][j]="";
                p[i][j]={-1,-1};
            }
        }
    }
}

vector<string> solution(vector<string> commands) {
    vector<string> answer;
    for(int i=1; i<=50; i++){
        for(int j=1; j<=50; j++){
            p[i][j]={-1,-1};
        }
    }
   
    for (const string& cmd : commands) {
        istringstream iss(cmd);
        v.clear();
        string s;
        while(iss>>s){
            v.push_back(s);
        }
        string fstr = v[0];
        if(fstr == "PRINT"){
            int r= stoi(v[1]);
            int c= stoi(v[2]);
            if(p[r][c].first!=-1){
               int rr= p[r][c].first;
               int cc= p[r][c].second;
                r= rr; c=cc;
            }
            if(a[r][c]!="")
            answer.push_back(a[r][c]);
            else answer.push_back("EMPTY");
        }
        else if(fstr == "MERGE"){
            int r1= stoi(v[1]);
            int c1= stoi(v[2]);
            int r2= stoi(v[3]);
            int c2= stoi(v[4]);
             if(p[r1][c1].first!=-1){
                int tr1= p[r1][c1].first;
                int tc1= p[r1][c1].second;
                 r1=tr1; c1=tc1;
            }
             if(p[r2][c2].first!=-1){
                int tr2= p[r2][c2].first;
                int tc2= p[r2][c2].second;
                 r2=tr2; c2=tc2;
            }
            if(r1==r2&&c1==c2) continue;
            else
            merge(r1,c1,r2,c2);
        }
        else if(fstr == "UNMERGE"){
            int r= stoi(v[1]);
            int c= stoi(v[2]);
            int rr=r;
            int cc=c;
            string vv= a[r][c];
            if(p[r][c].first!=-1){
                int rrr= p[r][c].first;
                int ccc= p[r][c].second;
                r=rrr; c=ccc;
                vv= a[r][c];
            }
             unmerge(r,c); 
             a[rr][cc]= vv;
        }
        else{
            if(v.size()==3){
                string v1= v[1];
                string v2= v[2];
                for(int i=1; i<=50;i++){
                    for(int j=1; j<=50; j++){
                        if(a[i][j]==v1){
                            a[i][j]=v2;
                        }
                    }
                }
            }
            else{
                int r= stoi(v[1]);
                int c= stoi(v[2]);
                string vv= v[3];
            if(p[r][c].first!=-1){
                int rr= p[r][c].first;
                int cc= p[r][c].second;
                r=rr; c=cc;
            }
               a[r][c] = vv; 
            }
        }
          for(int i=1; i<5; i++){
              for(int j=1; j<5; j++){
                  cout<<a[i][j]<<" ";
              }
              cout<<"\n";
          }  
        cout<<"\n";
            for(int i=1; i<5; i++){
              for(int j=1; j<5; j++){
                  cout<<p[i][j].first<<" "<<p[i][j].second;
              }
              cout<<"\n";
          } 
    }

    return answer;
}

