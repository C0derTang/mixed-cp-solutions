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
	string a, b;
	cin >> a >> b;
	cout << b[0];
	for(int i=1; i<3; ++i) cout << a[i];
	cout << ' ';
	cout << a[0];
	for(int i=1; i<3; ++i) cout << b[i];
	cout << '\n';
}

signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	int t; cin >> t;
	while(t--){
		solve();
	}
}
