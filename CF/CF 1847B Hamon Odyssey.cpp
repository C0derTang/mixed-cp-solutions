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

	vector<int> a(n+1);
	for(int i=0; i<n; ++i) cin >> a[i];
	
	int cur = a[0], ans = 1;
	for(int i=0; i<n; ++i){
		cur &= a[i];
		if (cur==0){
			if (i==n-1) break;
			++ans;
			cur = a[i+1];
		}
	}
	if (cur) --ans;
	cout << max(1, ans) << '\n';
	

}

signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	int t; cin >> t; // = 1;
	while(t--){
		solve();
	}
}
