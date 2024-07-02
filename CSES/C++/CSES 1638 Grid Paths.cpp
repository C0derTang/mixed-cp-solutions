#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

signed main() {
	int n; cin >> n;
	vector<string> grid(n);
	for(int i=0; i<n; ++i) cin >> grid[i];

	vector<vector<int>> dp(n, vector<int>(n));
	dp[0][0] = 1;
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			if(grid[i][j] == '*'){
				dp[i][j] = 0;
				continue;
			}
			int pl=0, pu=0;
			if (j>0) pl = dp[i][j-1];
			if (i>0) pu = dp[i-1][j];
			dp[i][j] = max(dp[i][j], pl + pu) % MOD;
		}
	}

	cout << dp[n-1][n-1];
}
