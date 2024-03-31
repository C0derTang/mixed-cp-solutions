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
	int n;
	cin >> n;
	vi a(n);
	FL(i, 0, n) cin >> a[i];

	vi ans(n);
	int mex = n;
	for (int i=n-1; i>-1; --i){
		if (a[i] > 0){
			ans[i] = mex-a[i];
			mex = ans[i];
		}else{
			ans[i] = mex+abs(a[i]);
		}
	}
	for (auto x: ans) cout << x << ' ';
	cout << '\n';

}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){
		solve();
	}
}
