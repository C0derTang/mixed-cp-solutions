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


void solve(){
	int n, m;
	cin >> n >> m;

	vi x(n);
	F0R(i, n) cin >> x[i];

	vector<vi> dp(n, vi(m+2));
	
	if (x[0] == 0) FOR(i, 1, m+1) dp[0][i] = 1;
	else dp[0][x[0]]=1;

	FOR(i, 1, n){
		if (x[i] > 0){ dp[i][x[i]] = (dp[i-1][x[i]-1] + dp[i-1][x[i]] + dp[i-1][x[i]+1]) %1000000007; continue;}
	
		FOR(j, 1, m+1){
			dp[i][j] = (dp[i-1][j-1]+ dp[i-1][j] + dp[i-1][j+1]) %1000000007;
		}
	}
	if (x[n-1] == 0) {
		int ans=0;
		for(auto x: dp[n-1]) ans = (ans+x) %1000000007;
		cout << ans;
	}
	else {cout << dp[n-1][x[n-1]] ;}
	/*
	cout << '\n';
	for (auto row: dp){
		for (auto c: row) cout << c << ' ';
		cout << '\n';
	}
	*/
	
	
}

signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	int t  = 1;
	while(t--){
		solve();
	}
}
