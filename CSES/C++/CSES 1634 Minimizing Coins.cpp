#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, x;
	cin >> n >> x;
	vector<int> c(n);
	for(int i=0; i<n; ++i) cin >> c[i];
	sort(c.begin(), c.end());

	vector<int> dp(x+1, 1000001);
	dp[0] = 0;

	for(int i=1; i<=x; ++i){
		for(auto num: c){
			if (i-num < 0) continue;
			dp[i] = min(dp[i-num]+1, dp[i]);
		}
	}
	cout << (dp[x] == 1000001 ? -1 : dp[x]);

}
