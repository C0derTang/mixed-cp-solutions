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

	/*
	if s is the sum of coins
	then ki*ci > s
	so ci > s/ki
	s > (s/ki) for every k
	so 1 > (1/ki) for every k;
	*/

	void solve(){
		int n; cin >> n;
		vector<int> k(n);
		for(int i=0; i<n; ++i) cin >> k[i];
		
		int lcm = 1;
		for (auto x: k){
			lcm = lcm*x / __gcd(lcm, x);
		}

		vector<int> ans(n);

		int lmao = lcm;
		for(int i=0; i<n; ++i){
			ans[i] = lcm/k[i];
			lmao -= ans[i];
		}

		if (lmao <= 0){
			cout << "-1\n";
			return;
		}

		for (auto x: ans) cout << x << ' ';
		cout << '\n';
	}

	signed main() {
		cin.tie(NULL) -> sync_with_stdio(false);
		int t; cin >> t; // = 1;
		while(t--){
			solve();
		}
	}
