#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void solve(){
	int n; cin >> n;
	vector<ll> k(n);
	for(int i=0; i<n; ++i) cin >> k[i];

	multiset<ll> towers;
	for (auto x: k){
		auto pt = towers.upper_bound(x);
		if (pt != towers.end()){
			towers.erase(pt);
		}
		towers.insert(x);
	}
	cout << towers.size();
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 1;
	while(t--){
		solve();
	}
}
