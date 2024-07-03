#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n, x;
	cin >> n >> x;
	vector<pair<int, int>> a(n);
	vector<int> b(n);
	for(int i=0; i<n; ++i){
		cin >> a[i].first;
		a[i].second = i;
	}
	for(int i=0; i<n; ++i) cin >> b[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	rotate(b.begin(), b.begin()+x, b.end());

	vector<int> ans(n);
	int match = 0;
	for(int i=0; i<n; ++i){
		if (a[i].first > b[i]) ++match;
		ans[a[i].second] = b[i];
	}
	
	if (match == x){
		cout << "YES\n";
		for(auto num: ans) cout << num << ' ';
		cout << '\n';
	}else{
		cout << "NO\n";
	}
}

signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	int t; cin >> t; // = 1;
	while(t--){
		solve();
	}
}