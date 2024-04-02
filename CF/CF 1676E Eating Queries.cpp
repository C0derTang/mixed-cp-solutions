#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pii pair<int, int>
#define FL(i, a, b) for(int i=a; i<b; ++i)
#define PB push_back
#define F first
#define S second

bool cbs(pii a, pii b) {
    return a.second < b.second;
}

void solve(){
	int n, q;
	cin >> n >> q;
	vi a(n);
	FL(i,0,n) cin >> a[i];
	sort(a.rbegin(), a.rend());

	vi pref(n+1);
	FL(i,0,n) pref[i+1] = pref[i] + a[i];

	while (q--){
		int target; cin >> target;
		auto ans = lower_bound(pref.begin(), pref.end(), target);
		if (ans == pref.end()) {
			cout << "-1\n";
		}else{
			cout << ans - pref.begin() << '\n';
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
