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
	int n, m;
	cin >> n >> m;
	vector<string> grid(n);
	for(int i=0; i<n; ++i) cin >> grid[i];
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			if (grid[i][j] == '#'){
				int ni = i;
				while(ni+1 < n && grid[ni][j] == '#') ++ni;
				cout << i + (ni-i)/2 + 1 << ' ' << j+1 << '\n';
				return;
			}
		}
	}
}

signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	int t; cin >> t;
	while(t--){
		solve();
	}
}
