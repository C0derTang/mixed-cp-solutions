#include <bits/stdc++.h>
using namespace std;


int main() {
	cin.tie(NULL) -> sync_with_stdio(false);

	int n, x;
	cin >> n >> x;
	vector<int> c(n);
	for(int i=0; i<n; ++i) cin >> c[i];
	sort(c.begin(), c.end());

	vector<int> dp(x+1);
	dp[0] = 1;
	for(int i=1; i<=x; ++i){
		for(auto num: c){
			if (i-num < 0) break;
			dp[i] += dp[i-num];
			dp[i] %= 1000000007;
		}
	}
	cout << dp[x];
}
