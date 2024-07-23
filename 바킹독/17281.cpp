#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v[51];
int ret = 0;
int base[4];

int simulate(vector<int> order) {
    int score = 0;
    int idx = 0; // 현재 타순에서의 타자 인덱스
    for (int inning = 0; inning < n; ++inning) {
        int out = 0;
        fill(base,base+4,0);
        while (out < 3) {
            int batter = order[idx];
            int result = v[inning][batter];
            idx = (idx + 1) % 9;
            if (result == 0) {
                out++;
            } else {
                if (result == 4) {
                    score++;
                    for(int i=1; i<=3;i++){
                    	if(base[i]==1){
                    		base[i]=0;
                    		score++;
						}
					}
                } else {
                   for(int i=3; i>=1; i--){
                   		if(base[i]){
                   			if(i+result>=4){
                   				base[i]=0;
                   				score++;
							   }
							else{
								base[i]=0;
								base[i+result]++;
							}
					 }
				   }
				   base[result]++;
                }
            }
        }
    }
    return score;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 9; ++j) {
            int temp;
            cin >> temp;
            v[i].push_back(temp);
        }
    }

    vector<int> order = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    do {
        if (order[3] != 0) continue; // 1번 선수를 4번 타자로 고정

        vector<int> batting_order(9);
        for (int i = 0, j = 0; i < 9; ++i) {
            if (i == 3) {
                batting_order[i] = 0;
            } else {
                batting_order[i] = order[j++];
                if (j == 3) j++; // 1번 선수는 이미 4번 타자로 고정했으므로 건너뜀
            }
        }

        ret = max(ret, simulate(batting_order));
    } while (next_permutation(order.begin(), order.end()));

    cout << ret;
    return 0;
}

