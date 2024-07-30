#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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
	int n, k;
	cin >> n >> k;
	vi a(n);
	int sum=0;
	F0R(i, n){
		cin >> a[i];
		sum += a[i];
	}
	sort(a.begin(), a.end());

	vi pref(n+1);
	F0R(i, n) pref[i+1] = pref[i]+a[i];
	vi suff(n+1);
	R0F(i, n-1) suff[i] = suff[i+1]+a[i];

	int ans=0;
	F0R(i, k+1){
		ans = max(ans, sum-pref[i*2]-suff[n-k+i]);
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
