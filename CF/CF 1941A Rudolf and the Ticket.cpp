#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define int long long
#define FL(i, a, b) for(int i=a; i<b; ++i)
#define PB push_back
#define F first
#define S second

bool cbs(pii a, pii b) {
    return a.second < b.second;
}

void solve(){
	int n,m,k; cin >> n >> m >> k;
	int b[n], c[m];
	FL(i, 0, n) cin >> b[i];
	FL(i, 0, m) cin >> c[i];

	int ans = 0;
	for(auto x: b){
		for (auto y: c){
			ans += (x+y <= k);
		}
	}
	cout << ans << '\n';
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){
		solve();
	}
}