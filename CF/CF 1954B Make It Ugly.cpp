#include <bits/stdc++.h>

using namespace std;

#define ll long long

// i am bad at observings

void solve(){
	int n; cin >> n;
	vector<int> a(n);
	for(int i=0; i<n; ++i) cin >> a[i];

	if (a[0] != a[n-1]){
		cout << "-1\n";
		return;
	}

	int minlen = n, curlen = 0;
	for(int i=0; i<n; ++i){
		if(a[i] == a[0]){
			++curlen;
		}else{
			minlen = min(minlen, curlen);
			curlen = 0;
		}
	}
	minlen = min(minlen, curlen);

	if (minlen == n) cout << "-1\n";
	else cout << minlen << '\n';
}

signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	int t; cin >> t; // = 1;
	while(t--){
		solve();
	}
}
