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
	FL(i,0,n){
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	if (n==1){
		cout << (a[0] == 1 ? "YES\n" : "NO\n");
		return;
	}
	cout << (a[n-1]-a[n-2] > 1 ? "NO\n" : "YES\n");
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){
		solve();
	}
}
