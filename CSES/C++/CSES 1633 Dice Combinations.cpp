#include <bits/stdc++.h>
using namespace std;

int MOD = 1000000007;

int main() {
	int n; cin >> n;
	vector<int> dp(n+1);
	dp[0] = 1;

	for(int i=1; i<=n; ++i){
		for(int j=i-6; j<i; ++j){
			if (j<0) continue;
			dp[i] += dp[j];
			dp[i] %= MOD;
		}
	}
	
	cout << dp[n];
}
