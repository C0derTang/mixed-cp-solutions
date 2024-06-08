#include <algorithm>
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

	// if edge case not included shitty pointer memory access #notscuffedtrust
	if(n == 1){
		cout << "0\n";
		return;
	}

	
	int ans = a[n-1] - a[0];
	ans = max(ans, *max_element(a.begin()+1, a.end()) - a[0]);
	ans = max(ans, a[n-1] - *min_element(a.begin(), a.begin()+n-1));

	for(int i=0; i<n; ++i){
		rotate(a.begin(), a.begin()+1, a.end());
		ans = max(ans, a[n-1] - a[0]);
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
