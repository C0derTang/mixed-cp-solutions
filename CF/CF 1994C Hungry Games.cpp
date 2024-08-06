#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <numeric>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>

#define FOR(i, a, b) for(int i=a; i<b; ++i)
#define F0R(i, a) for(int i=0; i<a; ++i)
#define ROF(i, a, b) for(int i=b; i>a-1; --i)
#define R0F(i, a) for(int i=a; i>-1; --i)
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

bool cbs(pii a, pii b) {
    return a.second < b.second;
}

void solve(){
	int n, x;
	cin >> n >> x;
	vi a(n);
	F0R(i, n) cin >> a[i];
	
	int ans = n+n*(n-1)/2;
	
	int cur=0, l=0;
	
	vi dp(n);
	//sliding window and count endpoints
	F0R(r, n){
		cur += a[r];
		//dp[r] = (r-1 < 0 ? 0 : dp[r-1]);
		

		while (cur > x && l <= r){
			//cout << l << ' ' << r << '\n';
			++dp[r];
			dp[r] += (l-1 < 0 ? 0 : dp[l-1]);
			cur -= a[l];
			++l;
		}
	}
	//for(auto g: dp) cout << g << ' ';

	cout << ans-accumulate(dp.begin(), dp.end(), 0LL) << '\n';
}

signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	int t; cin >> t; // = 1;
	while(t--){
		solve();
	}
}