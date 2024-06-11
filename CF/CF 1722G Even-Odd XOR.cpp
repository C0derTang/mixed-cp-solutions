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

// every odd number xored with cumulative odd numbers an even number of times will always yield an even number
// and if n is even we can just check for n-1 and slap 0 on to the end
// so we set the values from 0 to n-1 (for odd) or 0 to n-2 (for even) and the last value is just the xor of the odds xored by the xor of the evens
// and if n is even we just slap on zero
// the first element has to be 3 tho because one causes weird case where the xor of odds and evens == 0 which kinda sucks when n is even and we slap another zero onto that meaning theres duplicates

// lowkey guessforced

void solve(){
	int n; cin >> n;

	bool even = n%2 == 0;
	n -= even;

	--n;
	int num = 3;
	int e = 0, o = 0;
	for(int i=0; i<n; ++i){
		cout << num << ' ';
		if (i%2) e ^= num;
		else o ^= num;
		num += 2;
	}
	cout << (e ^ o) << ' ';

	
	if (even) cout << '0';
	cout << '\n';
}

signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	int t; cin >> t;
	while(t--){
		solve();
	}
}
