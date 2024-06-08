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
	int n; cin >> n;

	vector<int> a(n);
	for(int i=0; i<n; ++i) cin >> a[i];
	
	int pref = 0;
	for(int i=0; i<n; ++i){
		if (a[i] == a[0]) ++pref;
		else break;
	}

	int suff = 0;
	for(int i=n-1; i>-1; --i){
		if (a[i] == a[n-1]) ++suff;
		else break;
	}

	if (a[0] == a[n-1]) cout << max(0, n-pref-suff);
	else cout << n - max(pref, suff);
	cout << '\n';
}

signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	int t; cin >> t; // = 1;
	while(t--){
		solve();
	}
}
