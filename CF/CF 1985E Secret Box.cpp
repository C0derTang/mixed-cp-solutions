#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void solve(){
	// for 1 dimension, its just x-k+1
	// for 2 dimensions, is it just (x-a+1)(y-b+1) where a and b are factors of k, which we can brute force
	// for 3 dimensions just same thing

	int x, y, z, k;
	cin >> x >> y >> z >> k;

	int ans = 0;
	for(int a=1; a <=x; ++a){
		for(int b=1; b<=y; ++b){
			int c=k/a/b;
			if (k % (a*b) || c > z) continue;
			ans = max(ans, (x-a+1) * (y-b+1) * (z-c+1));
		}
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
