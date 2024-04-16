#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
	int n;
	cin >> n;
	vector<ll> p(n);
	for (int i=0; i<n; ++i) cin >> p[i];
	sort(p.begin(), p.end());
	
	ll ans = 0;
	for (int i=0; i<n; ++i) {
		ans += abs(p[i]-p[n/2]);
	}
	cout << ans;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 1;
	while(t--){
		solve();
	}
}
