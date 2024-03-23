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
	int n; cin >> n;
	int a[n];
	FL(i, 0, n) cin >> a[i];

	bool val = true;
	FL(i, 1, n-1){
		if (a[i-1] == 0) continue;
		if (a[i] - 2*a[i-1] < 0 || a[i+1] - a[i-1] < 0){
			val = false;
			break;
		}
		a[i] -= 2*a[i-1];
		a[i+1] -= a[i-1];
		a[i-1] = 0;
	}
	if (a[n-1] != 0 || a[n-2] != 0 || !val) cout << "NO\n";
	else cout << "YES\n";
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){
		solve();
	}
}