#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<string, int>> v;
string nums[11] = { "zero" ,"one" ,"two" ,"three" ,"four" ,"five" ,"six" ,"seven" ,"eight" ,"nine" };

int main() {
	cin >> n >> m;

	for (int i = n; i <= m; i++) {
		if(i>=10)
		v.push_back({nums[i/10]+nums[i%10],i});
		else
		v.push_back({nums[i],i});
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		cout << v[i].second<<" ";
		if ((i+1) % 10 == 0) cout << "\n";
	}

	return 0;
}
