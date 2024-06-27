#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long

// largest weight, smallest interval?
// has to be greedy right
//might as well
// creating the smallest interval possible:
// i hate overflow


void solve(){
	int n; cin >> n;
	vector<int> l(n), c(n);
	for(int i=0; i<n; ++i) cin >> l[i];
	set<int> r;
	for(int i=0; i<n; ++i){
		int x; cin >> x;
		r.insert(x);
	}
	for(int i=0; i<n; ++i) cin >> c[i];

	sort(l.begin(), l.end(), greater<int>());
	sort(c.begin(), c.end(), greater<int>());

	vector<int> diffs(n);
	for(int i=0; i<n; ++i){
		auto it = r.upper_bound(l[i]);
		if (it == r.end()) --it;
		diffs[i] = abs(*it - l[i]);
		r.erase(it);
	}

	sort(diffs.begin(), diffs.end());
	int ans = 0;
	for(int i=0; i<n; ++i){
		ans += diffs[i]*c[i];
	}
	cout << ans << '\n';
}

signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	int t; cin >> t; // = 1;
	while(t--){
		solve();
	}
}
