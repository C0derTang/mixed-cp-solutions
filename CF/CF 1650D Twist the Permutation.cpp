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
	for(int i=0; i<n; ++i) {
		cin >> a[i];
		--a[i];
	}

	vector<int> ans(n);
	for(int i=n-1; i>-1; --i){
		int cur = 0;
		for(int j=0; j<i+1; ++j){
			if (a[j] == i){
				cur = j; break;
			}
		}
		int shift = 0;
		if (i<cur) shift = cur-i;
		else if(i==cur) shift = 0;
		else shift = (i+1)-(i-cur);
		ans[i] = shift;
		rotate(a.begin(), a.begin()+shift, a.begin()+(i+1));
	}

	for(auto x: ans) cout << x << ' ';
	cout << '\n';
}

signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	int t; cin >> t; // = 1;
	while(t--){
		solve();
	}
}
