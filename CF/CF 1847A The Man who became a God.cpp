#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long


void solve(){
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i=0; i<n; ++i) cin >> a[i];

	vector<int> dif(n-1);
	for(int i=0; i<n-1; ++i)dif[i] = abs(a[i+1]-a[i]);

	sort(dif.begin(), dif.end());
	int ans = 0;
	for(int i=0; i<n-k; ++i) ans += dif[i];
	cout << ans << '\n';

}

signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	int t; cin >> t; // = 1;
	while(t--){
		solve();
	}
}
