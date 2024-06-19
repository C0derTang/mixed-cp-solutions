#include <bits/stdc++.h>

using namespace std;

#define ll long long

// weird median definition. read problem carefully!

void solve(){
	int n; cin >> n;
	vector<int> a(n);
	for(int i=0; i<n; ++i) cin >> a[i];

    if (n==2){
        cout << min(a[0], a[1]) << '\n';
        return;
    }

	int ans = min(a[0], a[1]);
	for(int i=0; i<n-2; ++i){
		vector<int> lmao = {a[i], a[i+1], a[i+2]};
        sort(lmao.begin(), lmao.end());
        ans = max(ans, lmao[1]);
	}
	cout << ans << '\n';
}

signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	int t; cin >> t; // = 1;
	while(t--){
		solve();
	}
}
