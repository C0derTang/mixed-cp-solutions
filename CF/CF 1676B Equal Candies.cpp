#include <algorithm>
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
	int n; cin >> n;
	vi a(n);
	FL(i,0,n) cin >> a[i];
	int eat = *min_element(a.begin(), a.end());
	int ans = 0;
	FL(i, 0, n) ans += a[i]-eat;
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
