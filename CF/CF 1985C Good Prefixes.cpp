#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void solve(){
	int n;
	cin >> n;
	ll cursum = 0;
	ll curmax = 0;
	int ans = 0;
	for(int i=0; i<n; ++i){
		ll x; cin >> x;
		cursum += x;
		curmax = max(x, curmax);
		ans += cursum-curmax==curmax;
	}
	cout << ans << '\n';
}

signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	int t; cin >> t;
	while(t--){
		solve();
	}
}
