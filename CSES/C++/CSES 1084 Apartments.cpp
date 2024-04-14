#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	vector<ll> a(n);
	vector<ll> b(m);
	for(int i=0; i<n; ++i) cin >> a[i];
	for(int i=0; i<m; ++i) cin >> b[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	
	int i = 0, j = 0, ans = 0;
	while (i < n && j < m) {
		if (abs(a[i]-b[j]) <= k) {
			++i;
			++j;
			++ans;
		}else if (b[j] > a[i]) {
			++i;
		}else{
			++j;
		}
	}

	cout << ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 1;
	while(t--){
		solve();
	}
}
