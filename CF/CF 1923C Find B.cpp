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
	int n, q; cin >> n >> q;

	int pref[n+1] = {0};
	int c1[n+1] = {0};
	FL(i, 0, n){
		int x; cin >> x;
		pref[i+1] = pref[i] + x;
		c1[i+1] = c1[i] + (x == 1);
	}
	while (q--) {
		int l, r;
		cin >> l >> r;
		--l;

		int curpref = pref[r] - pref[l];
		int curc1 = c1[r] - c1[l];
		
		if (r-l+curc1 <= curpref && r-l > 1) {
			cout << "YES\n";
		}else{
			cout << "NO\n";
		}
		
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){
		solve();
	}
}
