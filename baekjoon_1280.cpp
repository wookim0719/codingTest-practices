#include <bits/stdc++.h>
using namespace std; 
#define max_n 200004
#define ll long long
const ll mod = 1e9 + 7; 
int n, value;  
ll ret = 1, _prev; 
vector<ll> tree_cnt(max_n, 0), tree_sum(max_n, 0); 
ll _sum(vector<ll> &tree, int value){ 
    ll _ret = 0; 
    int i = value; 
    while(i){
        _ret += tree[i];
        i -= (i & -i); 
    }
    return _ret;  
}
ll sum(vector<ll> &tree, int s, int e){
    if(s > e) return 0; 
    return (_sum(tree, e) - _sum(tree, s - 1)); 
}

void update(vector<ll> &tree, int x, ll value){
    int i = x; 
    while(i <= max_n){
        tree[i] += value; 
        i += (i & -i);  
    } 
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);  
    cin >> n;  
    for(int i = 1; i <= n; i++){
    	// value를 1 증가 시키는 이유는 펜윅트리에서 사용하기 위해서이다. 
        cin >> value; value++;   
        if(i != 1){
        	// value에서 갯수를 곱한 값에서 값의 합들을 빼서 작은 값들에 대한 값을 구한다.  value-1을 하는 이유는 value보다 작은 값까지의 범위를 구해야한다.
            ll left = value * sum(tree_cnt, 1, value - 1) - sum(tree_sum, 1, value - 1);
            // value+1을 하는 이유는 value보다 큰 값들 중에서의 갯수와 합을 구해야 하기 때문이다. 
            ll right = sum(tree_sum, value + 1, max_n) - value * sum(tree_cnt, value + 1, max_n);
            ret *= (left + right) % mod; 
            ret %= mod; 
        }
        update(tree_cnt, value, 1);
        update(tree_sum, value, value);
    } 
    cout << ret << "\n";
}
