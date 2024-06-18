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

	int mine = 1, maxe = n;
	int l=0, r=n-1;
	while (l<r){
		bool change = false;
		if (a[l] == mine){
			++l; change = true;
			++mine;
		}
		if (a[l] == maxe){
			++l; change = true;
			--maxe;
		}
		if (a[r] == mine){
			--r; change = true;
			++mine;
		}
		if (a[r] == maxe){
			--r; change = true;
			--maxe;
		}
		if (!change){
			cout << l+1 << ' ' << r+1 << '\n';
			return;
		}
	}
	cout << "-1\n";
}

signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	int t; cin >> t; // = 1;
	while(t--){
		solve();
	}
}
