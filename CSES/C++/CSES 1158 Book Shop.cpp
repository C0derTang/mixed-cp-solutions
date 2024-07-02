#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>

#define FOR(i, a, b) for(int i=a; i<b; ++i)
#define F0R(i, a) for(int i=0; i<a; ++i)
#define ROF(i, a, b) for(int i=b; i>a-1; --i)
#define R0F(i, a) for(int i=a; i>-1; --i)

// standard 0/1 knapsack problem

signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	
	int n, x; cin >> n >> x;
	vi h(n);
	F0R(i, n) cin >> h[i];
	vi s(n);
	F0R(i, n) cin >> s[i];

	vector<vi> dp(n+1, vi(x+1));
	for(int i=1; i<=n; ++i){
		for(int j=0; j<=x; ++j){
			dp[i][j] = dp[i-1][j];
			if(j-h[i-1] >= 0) dp[i][j] = max(dp[i][j], dp[i-1][j-h[i-1]] + s[i-1]);
		}
	}
	cout << dp[n][x];
}
