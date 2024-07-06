#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>

#define FOR(i, a, b) for(int i=a; i<b; ++i)
#define F0R(i, a) for(int i=0; i<a; ++i)
#define ROF(i, a, b) for(int i=b; i>a-1; --i)
#define R0F(i, a) for(int i=a; i>-1; --i)

// is the strat just to take as early as possible? skull
// slide the fucking window

void solve(){
	int n, l, r;
	cin >> n >> l >> r;
	vi a(n);
	F0R(i, n) cin >> a[i];

	int sum=0;
	int ans=0;
	int lp=0;
	F0R(rp, n){
		sum += a[rp];
		while(sum > r && lp<rp){
			sum-= a[lp];
			++lp;
		}
		if (sum >= l && sum <=r){
			++ans;
			sum=0;
			lp=rp+1;
		}
	}
	cout << ans << '\n';
}

signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	int t; cin >> t; // = 1;
	while(t--){
		solve();
	}
}
