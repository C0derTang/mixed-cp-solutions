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
	int k; cin >> k;
	if ((k+1)/2 > 18){
		cout << "-1";
		return;
	}

	if (k%2) cout << '4';
	for(int i=0; i<k/2; ++i) cout << '8';
}

signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	int t = 1;
	while(t--){
		solve();
	}
}
