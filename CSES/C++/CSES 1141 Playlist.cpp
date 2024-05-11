#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void solve(){
	int n;
	cin >> n;
	vector<ll> k(n);
	for(int i=0; i<n; ++i) cin >> k[i];

	//this seems to be trivial, a sliding window + map.
	// map used to keep track of where the previous element's location is
	// update accordingly
	// too lazy to write edi idk how iframe does it

	map<ll, int> loc;

	int l=0, ans = 0;
	for (int r=0; r<n; ++r){
		if (loc.find(k[r]) != loc.end()){
			l = max(l, loc[k[r]]+1);
		}
		loc[k[r]] = r;
		ans = max(ans, r-l+1);
	}
	cout << ans;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 1;
	while(t--){
		solve();
	}
}
