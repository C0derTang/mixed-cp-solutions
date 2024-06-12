#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <queue>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void solve(){
	int h, n; cin >> h >> n;
	vector<int> a(n), c(n);
	for(int i=0; i<n; ++i) cin >> a[i];
	for(int i=0; i<n; ++i) cin >> c[i];

	
	priority_queue<pair<int, int>> lmao;
	for(int i=0; i<n; ++i){
		lmao.push({-1, i});
	}

	int turns = 0;
	while (h >0){
		pair<int, int> attack = lmao.top();
		lmao.pop();
		turns = -attack.first;
		h -= a[attack.second];
		lmao.push({attack.first - c[attack.second], attack.second});
	}
	cout << turns << '\n';
}

signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	int t; cin >> t;
	while(t--){
		solve();
	}
}
