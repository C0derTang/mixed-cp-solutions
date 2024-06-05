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
	
	for(int i=n-1; i>0; i-=2){
		if (a[i-1] > a[i]) swap(a[i-1], a[i]);
	}
	bool val = true;
	for(int i=0; i<n-1; ++i){
		if (a[i] > a[i+1]){
			val = false;
			break;
		}
	}

	cout << (val ? "YES\n" : "NO\n");
}

signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	int t; cin >> t; // = 1;
	while(t--){
		solve();
	}
}
