#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define ll long long

bool cbs(pii a, pii b) {
    return a.second < b.second;
}

void solve(){
	int n, m;
	cin >> n >> m;
	ll a[n];
	for (int i=0; i<n; ++i) {
		cin >> a[i];
	}
	ll b[n];
	for (int i=0; i<n; ++i) {
		cin >> b[i];
	}
	int krill = n;
	ll finalans = LONG_LONG_MAX;
	ll ans = 0;
	while (krill >= 1){
		while (krill-1 > 0 && b[krill-1] < a[krill-1]) {
			if (krill-1 <= m-1){
				finalans = min(ans+a[krill-1], finalans);
			}
			--krill;
			ans += b[krill];
		}
		--krill;
		ans += a[krill];
		if (krill <= m-1){
			finalans = min(ans, finalans);
		}
		
	}
	cout << finalans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){
		solve();
	}
}
