#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve(){
	int n, m;
	cin >> n >> m;
	cout << (m <= n && (m==n || (n-m)%2 == 0) ? "Yes" : "No") << '\n';
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t; // = 1;
	while(t--){
		solve();
	}
}
