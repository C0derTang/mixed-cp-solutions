#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve(){
    int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	set<char> can;
	for(int i=0; i<k; ++i){
		char x; cin >> x; can.insert(x);
	}

	int ans = n*(n+1)/2;
	int latest = 0;
	for(int i=0; i<n; ++i){
		if (can.count(s[i])) continue;
		ans -= (n-i)*(i-latest+1);
		latest = i+1;
	}
	cout << ans;
}

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    int t = 1; 
    while (t--) {
        solve();
    }
}
