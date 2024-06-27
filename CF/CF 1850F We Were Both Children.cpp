#include <bits/stdc++.h>

using namespace std;

#define int long long

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

//if any number > n immediately discard it
// if there are no other multiples of a number, discard it
// actually gay sol

void solve(){
	int n; cin >> n;
	vector<int> a(n+1), dp(n+1);
	for(int i=0; i<n; ++i){
		int x; cin >> x;
		if(x <= n) ++a[x];
	}

	for(int i=1; i<=n; ++i){
		for(int j=i; j<=n; j += i) dp[j] += a[i];
	}

	cout << *max_element(dp.begin(), dp.end()) << '\n';
}

signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	int t; cin >> t; // = 1;
	while(t--){
		solve();
	}
}
