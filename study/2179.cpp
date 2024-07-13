#include <bits/stdc++.h>
using namespace std;

vector<string> v;
int n;
map<string, int> mp;
int ret;
string a, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        v.push_back(temp);
        mp[temp] = i;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int cnt = 0;
            for (int k = 0; k < min(v[i].size(), v[j].size()); k++) {
                if (v[i][k] == v[j][k]) {
                    cnt++;
                } else {
                    break;
                }
            }

            if (cnt > ret) {
                ret = cnt;
                a = v[i];
                b = v[j];
            } else if (cnt == ret) {
                if ((mp[a] == mp[v[i]] && mp[b] > mp[v[j]])) {
                    a = v[i];
                    b = v[j];
                }
            }
        }
    }

    cout << a << "\n" << b << "\n";
    for(int i=0; i<n; i++){
    	cout<<v[i]<<" ";
	}
    
    return 0;
}

