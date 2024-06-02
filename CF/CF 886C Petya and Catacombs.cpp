#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long

void solve(){
	int n; cin >> n;
	vector<int> a(n);
	map<int, int> count;
	for(int i=0; i<n; ++i){
		cin >> a[i];
		++count[a[i]];
	}
	
	// the first occurence of every number is a repeating room
	// fuck me in the ass bro how am i so dumb at this

	int ans = 0;
	for(int i=0; i<n; ++i){
		ans += max(0, count[i] - 1);
	}
	cout << ans+1;
}

signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	int t = 1;
	while(t--){
		solve();
	}
}
